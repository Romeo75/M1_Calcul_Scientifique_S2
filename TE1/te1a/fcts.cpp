#include <cmath>
#include "fcts.h"

float y(float t){
    
    return t*t ;
    
}

float logistique(float t){
    
    float result = k/(1 + ( (k-y0)/y0 )*std::exp(-a*(t-t0)) ) ;
    
    return result ;
    
}