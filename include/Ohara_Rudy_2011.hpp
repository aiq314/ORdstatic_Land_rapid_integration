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
  void initConsts(double type, double conc, const double *hill, const double *herg );
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveEuler(double dt);
  double tryDt( double dt,
               double TIME,
               double *CONSTANTS,
               double *RATES,
               double* STATES,
               double* ALGEBRAIC );
  void gaussElimination(double *A, double *b, double *x, int N);
//  void gaussSeidel(double **a, double *b, double *x, int n, int maxIterations, double tolerance);
  void solveRK4(double TIME,double dt);
  void mat_vec_multiply(double** a, double* x, double *result, int n);
  double set_time_step(double TIME,
                       double time_point,
                       double min_time_step,
                       double max_time_step,
                       double min_dV,
                       double max_dV,
                       double* CONSTANTS,
                       double* RATES,
                       double* STATES,
                       double* ALGEBRAIC);
private:
  void ___applyDrugEffect(double conc, const double *hill);
  void ___initConsts(double type);
};


#endif

