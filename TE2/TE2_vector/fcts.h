#include <Eigen/Dense>

float dydt(float t,float y);
float y_th(float t, float t0, float y0);


Eigen::VectorXf dvect_calc(float t, const Eigen::VectorXf y);
Eigen::VectorXf vect_th(float t, const Eigen::VectorXf y);

/*
float logistique(float t);

float sin_k(float t);

float exp_k(float t);

float sin_deriv_th(float t);

float exp_deriv_th(float t);
*/