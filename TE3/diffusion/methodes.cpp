#include <eigen3/Eigen/Dense>
#include <iostream>
#include "matrices.h"

using namespace Eigen;


VectorXf avance_expl( const VectorXf uold, const float alpha, const float ug,  const float ud){
    
    int N = uold.size();
    VectorXf B(N);
    
    B(0) = alpha * (ug + uold(1)) + (1-2*alpha)*uold(0);
    
    for( int i = 1; i < N-1; i++ ){
        
        // Question comment mettre les indices ? Comment verifier le B ?
        B(i) = alpha * (uold(i-1) + uold(i+1)) + (1-2*alpha)*uold(i);
    
        }
    
    B(N-1) = alpha * (uold(N-2) + ud) + (1-2*alpha)*uold(N-1);
    
    return B;
}


VectorXf implicite( const VectorXf uold,const VectorXf V, const MatrixXf invmalpha, const float alpha){
    
    int N = uold.size();
    VectorXf B(N);
    
    
    B =  invmalpha * ( uold + alpha * V);
    
    
    return B;
}


VectorXf cNicolson( const VectorXf uold,const VectorXf V, const MatrixXf malpha, const MatrixXf invmalpha, const float alpha){
    
    int N = uold.size();
    VectorXf B(N);
    
    B =  invmalpha * ( malpha * uold + alpha * V); // Ici on a Vn+1 et Vn fixes dans le temps. Donc Vn+1 = Vn.
    
    
    return B;
}
