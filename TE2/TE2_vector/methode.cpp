#include "methode.h"

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y ){
    
    for (int i= 1; i<Y.
         size(); i++){
        
        Y(i) = f(X(i)); 

    }
    
}

//First order integrating factor
Eigen::VectorXf euler_progres(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h){
    

    return y + h*df(t,y);
}

//Second order integrating factor
Eigen::VectorXf milieu(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h){
    return y + h*df(t + h/2, y + (h/2)*df(t,y));
}

//Fourth order integrating factor
Eigen::VectorXf rk4(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h){
    
    Eigen::VectorXf k1 = df(t,y);
    Eigen::VectorXf k2 = df(t+h/2, y + k1*h/2);
    Eigen::VectorXf k3 = df(t+h/2, y + k2*h/2);
    Eigen::VectorXf k4 = df(t+h, y + k3*h);
    
    return y + (k1 + 2*k2 + 2*k3 + k4)*h/6;
    
}



/*
float cright(std::function<float(float)> f, float t0, float h){
    
    
    return (f(h+t0)-f(t0))/h;
    
}

float cleft(std::function<float(float)> f, float t0, float h){
    
    return ( f(t0) - f(t0-h) )/h;
    
}

float ccenter(std::function<float(float)> f, float t0, float h){
    

    return(f(t0+h) - f(t0-h))/(2*h);

    
}
*/