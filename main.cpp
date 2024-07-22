#include "Ohara_Rudy_2011.hpp"
#include "Land_2016.hpp"

#include "omp.h"
#include "simulationparams.h"
#include "drug_data.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>

int main(int argc, char* argv[]){
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << "<params.txt> <hill_data.csv> <herg_data.csv>" << std::endl;
    return 1;
  }
  // Load params
  simulation_params params = load_params(argv[1]);
  std::cout << "Running simulation with parameters:" << std::endl;
  std::cout << "celltype : " << params.celltype << std::endl;
  std::cout << "bcl (ms): " << params.bcl << std::endl;
  std::cout << "beats : " << params.beats << std::endl;
  std::cout << "dtw (ms): " << params.dtw << std::endl;
  std::cout << "time_point (ms): " << params.time_point << std::endl;
  std::cout << "min_dt (ms): " << params.min_dt << std::endl;
  std::cout << "max_dt (ms): " << params.max_dt << std::endl;
  std::cout << "drug_name : " << params.drug_name << std::endl;
  std::cout << "conc (nM): ";
  for (int i = 0; i < params.conc_size; i++){
    std::cout<< params.conc[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "cai_scaling :" << params.cai_scaling << std::endl;
  // Input for adaptive time step
  double time_point = params.time_point;
  double min_dt = params.min_dt;
  double max_dt = params.max_dt;
  // Load drug data
  hill_data hill = load_hill(argv[2]);
  herg_data herg = load_herg(argv[3]);
  std::cout << "hill data:" << std::endl;
  for(int i = 0; i < 14; i++){
    std::cout << "Col " << i << ": " << hill.hill[i] << std::endl;
  }
  std::cout << "herg data:" << std::endl;
  for(int i = 0; i < 6; i++){
    std::cout << "Col " << i << ": " << herg.herg[i] << std::endl;
  }
  // Measure time
  clock_t start, end, start_total, end_total;
  double cpu_time_used;
  start_total = clock();
  for (int conc_id = 0; conc_id < params.conc_size; conc_id++){
    // Input for AP simulation
    double t_max = (double) params.beats * params.bcl;
    double t_curr = 0.0, t_mech = 0.0;
    double dt = 0.0, dt_mech = 0.0;
    double dtw = params.dtw;
    double t_next = t_curr + dtw;
    double next_write_time = t_max - params.bcl;
    double epsilon = 1e-4;
    double conc = params.conc[conc_id];
    int cai_scaling = params.cai_scaling;
    int mech_jump = 0;
    double cai_rates = 0.0;
    // Start of calculations
    int imax = int((t_max - next_write_time) / dtw) + 1;// + ((int(t_max) - int(next_write_time)) % int(dtw) == 0 ? 0 : 1);
    Cellmodel* p_elec;
    Cellmodel* p_mech;
    Cellmodel* p_em;
    std::ofstream vmcheck, em_vmcheck;
    std:: ostringstream file_name;
    std::string vmcheck_name;
    start = clock();
    p_elec = new Ohara_Rudy_2011();
    p_elec->initConsts(params.celltype,conc,hill.hill,herg.herg); // drug effects
    p_elec->CONSTANTS[BCL] = params.bcl;
    p_mech = new Land_2016();
    p_mech->initConsts(false, false);
    file_name << "vmcheck_";
    file_name << params.drug_name << "_";
    file_name << conc << ".plt";

    vmcheck_name = file_name.str();
    vmcheck.open(vmcheck_name.c_str());
    vmcheck << "Time" << "\t";
    vmcheck << "dt" << "\t";
    vmcheck << "INa" << "\t";
    vmcheck << "INaL" << "\t";
    vmcheck << "Ito" << "\t";
    vmcheck << "ICaL" << "\t";
    vmcheck << "ICaNa" << "\t";
    vmcheck << "ICaK" << "\t";
    vmcheck << "IKr" << "\t";
    vmcheck << "IKs" << "\t";
    vmcheck << "IK1" << "\t";
    vmcheck << "INaCa_i" << "\t";
    vmcheck << "INaCa_ss" << "\t";
    vmcheck << "INaK" << "\t";
    vmcheck << "INab" << "\t";
    vmcheck << "IKb" << "\t";
    vmcheck << "IpCa" << "\t";
    vmcheck << "ICab" << "\t";
    vmcheck << "Tension" << "\t";
    for(int i = 0; i < p_elec->states_size; i++) {
      vmcheck << "STATES[" << i << "]";
      vmcheck << "\t";
    }
    for(int i = 0; i < p_mech->states_size; i++) {
      vmcheck << "STATES_MECH[" << i << "]";
      if(i < p_mech->states_size-1) {// Add a tab for all but the last element
        vmcheck << "\t";
      } else {// End the line after the last element
        vmcheck << "\n";
      }
    }
    int iprint = 0;
    while(iprint<imax){
      if (cai_scaling == 1){
        p_mech->CONSTANTS[Cai] = p_elec->STATES[cai]*1000.;
      }
      else{
        p_mech->CONSTANTS[Cai] = p_elec->STATES[cai];
      }
      p_mech->computeRates(t_curr,
                          p_mech->CONSTANTS,
                          p_mech->RATES,
                          p_mech->STATES,
                          p_mech->ALGEBRAIC);
      p_elec->RATES[ca_trpn] = p_elec->CONSTANTS[trpnmax] * p_mech->RATES[TRPN];
      p_elec->computeRates(t_curr,
                          p_elec->CONSTANTS,
                          p_elec->RATES,
                          p_elec->STATES,
                          p_elec->ALGEBRAIC);
      // Solve CiPAORdv1
      dt = max_dt;
      if (t_curr + dt >= next_write_time){
        dt = next_write_time - t_curr;
      }
      p_elec->solveEuler(dt);
      // Solve Land2016
      if (dt >= min_dt){
        dt_mech = min_dt;
      } else {
        dt_mech = dt;
      }
      t_mech = t_curr;
      if (dt > 0 && dt_mech > 0){
        mech_jump = static_cast<int>(std::ceil(dt/dt_mech));
        if (cai_scaling == 1){
          cai_rates = p_elec->RATES[ca_trpn] * 1000.0;
        } else {
          cai_rates = p_elec->RATES[ca_trpn];
        }
        for (int i_jump = 0; i_jump < mech_jump; i_jump++){
          if (t_mech + dt_mech >= t_curr + dt){
            dt_mech = t_curr + dt - t_mech;
          }
          p_mech->solveEuler(dt_mech);
          // For next i_jump
          t_mech = t_mech + dt_mech;
          p_mech->CONSTANTS[Cai] = p_mech->CONSTANTS[Cai] + cai_rates*dt_mech;
          p_mech->computeRates(t_mech,
                  p_mech->CONSTANTS,
                  p_mech->RATES,
                  p_mech->STATES,
                  p_mech->ALGEBRAIC);
        }
      }
      t_curr = t_curr + dt;
      if (t_curr >= next_write_time){
        vmcheck << iprint * dtw << "\t";
        vmcheck << dt << "\t";
        vmcheck << p_elec->ALGEBRAIC[INa] << "\t";
        vmcheck << p_elec->ALGEBRAIC[INaL] << "\t";
        vmcheck << p_elec->ALGEBRAIC[Ito] << "\t";
        vmcheck << p_elec->ALGEBRAIC[ICaL] << "\t";
        vmcheck << p_elec->ALGEBRAIC[ICaNa] << "\t";
        vmcheck << p_elec->ALGEBRAIC[ICaK] << "\t";
        vmcheck << p_elec->ALGEBRAIC[IKr] << "\t";
        vmcheck << p_elec->ALGEBRAIC[IKs] << "\t";
        vmcheck << p_elec->ALGEBRAIC[IK1] << "\t";
        vmcheck << p_elec->ALGEBRAIC[INaCa_i] << "\t";
        vmcheck << p_elec->ALGEBRAIC[INaCa_ss] << "\t";
        vmcheck << p_elec->ALGEBRAIC[INaK] << "\t";
        vmcheck << p_elec->ALGEBRAIC[INab] << "\t";
        vmcheck << p_elec->ALGEBRAIC[IKb] << "\t";
        vmcheck << p_elec->ALGEBRAIC[IpCa] << "\t";
        vmcheck << p_elec->ALGEBRAIC[ICab] << "\t";
        vmcheck << p_mech->ALGEBRAIC[land_T] * 480.0 << "\t";
        for(int i = 0; i < p_elec->states_size; i++){
          vmcheck << p_elec->STATES[i];
          vmcheck << "\t";
        }
        for(int i = 0; i < p_mech->states_size; i++){
          vmcheck << p_mech->STATES[i];
          if(i < p_mech->states_size-1) {// Add a tab for all but the last element
              vmcheck << "\t";
          } else {// End the line after the last element
          vmcheck << "\n";
          }
        }
        // Increment next_write_time by dtw
        next_write_time += dtw;
        iprint += 1;
      }
    }
    vmcheck.close();
    em_vmcheck.close();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Simulation is successfully done\n";
    std::cout << "Computational time: " << cpu_time_used << " seconds\n";
    delete p_elec;
    delete p_mech;
  }
  end_total = clock();
  cpu_time_used = ((double) (end - start_total)) / CLOCKS_PER_SEC;
  std::cout << "All simulations are successfully done\n";
  std::cout << "Total computational time: " << cpu_time_used << " seconds\n";
  return 0;
}
