#include <cmath>
#include "fcts.h"

/*
float y(float t){
    
    return t*t ;
    
}
*/
/*
float logistique(float t){
    
    float result = k/(1 + ( (k-y0)/y0 )*std::exp(-a*(t-t0)) ) ;
    
    return result ;
}
*/

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