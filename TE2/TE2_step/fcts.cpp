#include <cmath>
#include "fcts.h"

float a;
float tau;
float k;

//syteme differentiel à resoudre desiré
float dydt(float t,float y){
    
    return -y*(t-a)/(std::pow(tau,2));
        
}

//Solution theorique de reference
float y_th(float t, float t0, float y0){
    
    return y0*exp(1/2. * ( pow( (t0 - a)/tau , 2) - ( pow( (t-a)/tau , 2) ) ) );
    
}

    
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

