#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <string>
#include "util.h"

using namespace std;
using namespace Eigen;

void ecrit_entete( string name, int Nx, int Nt, float dt, float dx, float alpha ){
    
    ofstream data;    
    data.open(name);
    //Ajout des entetes
    data <<  "#" << Nx + 2   << " "
         <<  Nt    << " "
         <<  dx    << " "
         <<  dt    << " "
         <<  alpha << endl;
    data.close();

}


void ecrit( const string name, const VectorXf u, const float Ug , const float Ud ){
    
    int N = u.size();
    ofstream data;
    
    //On ouvre le fichier en mode append
    data.open(name, ios::app);
    
    //Condition limite à gauche
    data << Ug << "	";
    
    //On ectrit le vecteur U horizontalement par convention
    for(int i =0; i < N; i++){
        
        data << u[i] << "	";
    }
    
    //Condition limite à droite
    data << Ud << endl;
    
    
    data.close();
}

//Ecrit les vecteur pour ref et control
void w_test(const string name, const VectorXf uold, const float dx){
    
    int Nx = uold.size();
    
    ofstream data;
    
    data.open(name);
    
    for ( int i = 0; i< Nx; i++){
        
        data << i*dx << "	" << uold[i] << endl;
        
    }
         
    data.close();
}