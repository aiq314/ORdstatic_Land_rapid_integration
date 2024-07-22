#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


double set_time_step(double TIME,
  double time_point,
  double max_time_step,
  double* CONSTANTS,
  double* RATES,
  double* STATES,
  double* ALGEBRAIC) {
  double time_step = 0.005;

  if (TIME <= time_point || (TIME - floor(TIME / CONSTANTS[BCL]) * CONSTANTS[BCL]) <= time_point) {
    //printf("TIME <= time_point ms\n");
    return time_step;
    //printf("dV = %lf, time_step = %lf\n",RATES[V] * time_step, time_step);
  }
  else {
    //printf("TIME > time_point ms\n");
    if (std::abs(RATES[v] * time_step) <= 0.2) {//Slow changes in V
        //printf("dV/dt <= 0.2\n");
        time_step = std::abs(0.8 / RATES[v]);
        //Make sure time_step is between 0.005 and max_time_step
        if (time_step < 0.005) {
            time_step = 0.005;
        }
        else if (time_step > max_time_step) {
            time_step = max_time_step;
        }
        //printf("dV = %lf, time_step = %lf\n",std::abs(RATES[V] * time_step), time_step);
    }
    else if (std::abs(RATES[v] * time_step) >= 0.8) {//Fast changes in V
        //printf("dV/dt >= 0.8\n");
        time_step = std::abs(0.2 / RATES[v]);
        while (std::abs(RATES[v] * time_step) >= 0.8 &&
               0.005 < time_step &&
               time_step < max_time_step) {
            time_step = time_step / 10.0;
            //printf("dV = %lf, time_step = %lf\n",std::abs(RATES[V] * time_step), time_step);
        }
    }
    return time_step;
  }
}

#endif // FUNCTIONS_H_INCLUDED

