#ifndef OHARA_RUDY_2011_HPP
#define OHARA_RUDY_2011_HPP

#include "Cellmodel.h"
#include "enum_Ohara_Rudy_2011.hpp"

class Ohara_Rudy_2011 : public Cellmodel
{
public:
  Ohara_Rudy_2011();
  ~Ohara_Rudy_2011();
  void initConsts ();
  void initConsts(double type);
	void initConsts(bool is_dutta);
	void initConsts(double type, double bcl, double conc, double *ic50, bool is_dutta );
  void computeRates();
  void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC);
  void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC, double land_trpn);
  void solveAnalytical( double dt, double *CONSTANTS, double *RATES, double* STATES, double* ALGEBRAIC );
  static double set_time_step(double TIME,double time_point,double max_time_step,
      double* CONSTANTS,double* RATES,double* STATES,double* ALGEBRAIC);

private:
	void ___applyDrugEffect(double conc, double *ic50);
	void ___applyDutta();
	void ___initConsts(double type, double bcl);

};


#endif

