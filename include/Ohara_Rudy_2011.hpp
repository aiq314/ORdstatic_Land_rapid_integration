#ifndef OHARA_RUDY_2011_HPP
#define OHARA_RUDY_2011_HPP

#include "Cellmodel.h"
#include "enum_Ohara_Rudy_2011.hpp"

#define EULER

class Ohara_Rudy_2011 : public Cellmodel
{
public:
  Ohara_Rudy_2011();
  ~Ohara_Rudy_2011();
  void initConsts ();
  void initConsts(double type);
  void initConsts(double type, double conc, double *hill);
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveEuler(double dt);
  void solveAnalytical(double dt);
  void solveRK4(double TIME,double dt);
  double set_time_step(double TIME,
                       double time_point,
                       double min_time_step,
                       double max_time_step);
private:
  void ___applyDutta();
  void ___applyDrugEffect(double conc, const double *hill);
  void ___initConsts(double type);
};


#endif

