#include "util.h"
#include <iostream>
#include <iomanip>

extern float k;
extern float m;
extern float l;

void ecrit( std::string name, float step, const Eigen::VectorXf &X, const Eigen::MatrixXf &Y_calc, const Eigen::MatrixXf &Y_th, const Eigen::MatrixXf &Delta ){
    
    float Delta_max = 0.;
    int i_max = 0, N = X.size();
    std::string name_file;
    name_file = name + ".txt";
    
    
    
    std::ofstream points;
    points.open(name_file);
    
    //Definitions des energies et coordonées necesaires
    Eigen::VectorXf Y = Y_calc.col(0);
    Eigen::VectorXf Vy = Y_calc.col(1);
    
    float Em_th;
    Eigen::VectorXf Em(N);
    Eigen::VectorXf Ec(N);
    Eigen::VectorXf Ep(N);
    
    points << "#Methode utilisée: " << name << std::endl;
    
    //std::cout << "i    i_max    Delta_max     Delta(i)" << std::endl;
    //Find the max point
    for (int i = 0; i<N; i++){
        
        if( Delta(i) < Delta_max ) {
            i_max = i;
            Delta_max = Delta(i);
        }
        
        //Calcul des enerigies

        Ec(i) = 0.5 * m * std::pow(Vy(i),2);
        Ep(i) = std::pow(k,2)* ( 1-cos(Y(i)) );
        Em_th = std::pow(k,2)* ( 1-cos(Y(0)) ) + 0.5 * m * std::pow(Vy(0),2);
            
        Em(i) = (Ec(i) + Ep(i) - Em_th)/Em_th;


        //std::cout << i << "   " << Em(i) << "   " << Em_th << "   " << Ec(i) << std::endl;
    
    }
    
    points << "#Pas d'integration: " << step << std::endl;
    points << "#Position initiale: " << Y_th(0,0) << std::endl;
    points << "#Vitesse initiale: " << Y_th(0,1) << std::endl;
    
    
    //Data points
    std::setprecision(7); //Format
    for (int i= 0; i<N-1; i++){
        
        points << X(i) << "	" << Y(i)<< "	" << Vy(i)<< "	" << Y_th(i,0) << "	" << Y_th(i,1)<< "	" << Em(i) << std::endl;
        
    }
    
    points.close();
    
}