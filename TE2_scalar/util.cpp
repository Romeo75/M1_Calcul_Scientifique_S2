#include "util.h"
#include <iostream>
#include <iomanip>

void ecrit( std::string name, const Eigen::VectorXf &X, const Eigen::VectorXf &Y_calc, const Eigen::VectorXf &Y_th, const Eigen::VectorXf &Delta ){
    
    float Delta_max = 0.;
    int i_max = 0;
    
    std::ofstream points;
    points.open(name);
    
    points << "#Methode utilisée: " << name << std::endl;
    
    //std::cout << "i    i_max    Delta_max     Delta[i]" << std::endl;
    //Finfind the max point
    for (int i = 0; i<X.size(); i++){
        
        if( Delta[i] < Delta_max ) {
            i_max = i;
            Delta_max = Delta[i];
        }
        
    //std::cout << i << "   " << i_max << "   " << Delta_max << "   " << Delta[i] << std::endl;
    
    }
    
    points << "#Max de l'erreur: " << std::abs(Delta_max) << std::endl;
    points << "#Abscise de l'erreur max: " << X[i_max] << std::endl;
    
    
    //Data points
    std::setprecision(7); //Format
    for (int i= 0; i<X.size(); i++){
        
        points << X(i) << "	" << Y_calc(i)<< "	" << Y_th(i) << "	" << Delta(i) << std::endl;
        
    }
    
    points.close();
    
}