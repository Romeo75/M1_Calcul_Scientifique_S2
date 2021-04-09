#include <iostream>
#include <eigen3/Eigen/Dense>
#include <math.h>

using namespace Eigen;
using namespace std;

extern float L, dx, pi; 

VectorXf init2sinus(int N){
    
    
    VectorXf B(N); B.setZero();
    
    for( int i = 0; i < N ; i++){
        
        B(i) = 1 + sin(pi*(1+i)*dx/L) + 0.2 * sin(5*pi*(1+i)*dx/L);
        
    }
    
    return B;
}

VectorXf init2step(int N){
    
    
    VectorXf B(N); B.setZero();
    
    for( int i = 0; i < N ; i++){
        
        if( i <N/2 ) B(i) = +1;
        else B(i) = -1;
        
    }
    
    return B;
}
