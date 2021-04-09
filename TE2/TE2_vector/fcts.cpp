#include <cmath>
#include "fcts.h"
#include <Eigen/Dense>

float a;
float tau;
extern float k;

//syteme differentiel à resoudre desiré (2)
Eigen::VectorXf dvect_calc(float t, const Eigen::VectorXf y){
    
    int N = y.size();
    
    Eigen::VectorXf res(N);
    
    res(0) = y(1);
    res(1) = - pow(k,2)*sin(y(0));
    
    return res;
    
}


Eigen::VectorXf vect_th(float t, const Eigen::VectorXf y){
    
    //y = (Y0,Vy_0)
    
    int N = y.size();
    
     Eigen::VectorXf res(N);
    
    res(0) =  y(0)*cos(k*t) + y(1)*sin(k*t);
    res(1) = -k*y(0)*sin(k*t) + k*y(1)*cos(k*t);
    
    
    return res;
    
}


//Solution theorique de reference (2)



/*
float logistique(float t){
    
    float result = k/(1 + ( (k-y0)/y0 )*std::exp(-a*(t-t0)) ) ;
    
    return result ;
}

float k;
    
float sin_k(float t){
    return sin(k*t);
}

float exp_k(float t){
    
    return exp(k*t);
    
}


float sin_deriv_th(float t){
    return k*cos(k*t);
}

float exp_deriv_th(float t){
    
    return k*exp(k*t);
    
}

*/