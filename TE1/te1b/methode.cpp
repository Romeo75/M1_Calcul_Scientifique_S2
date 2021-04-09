#include "methode.h"

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y ){
    
    for (int i= 1; i<Y.
         size(); i++){
        
        Y(i) = f(X(i)); 

    }
    
}

float cright(std::function<float(float)> f, float t0, float h){
    
    
    return (f(h+t0)-f(t0))/h;
    
}

float cleft(std::function<float(float)> f, float t0, float h){
    
    return ( f(t0) - f(t0-h) )/h;
    
}

float ccenter(std::function<float(float)> f, float t0, float h){
    

    return(f(t0+h) - f(t0-h))/(2*h);

    
}