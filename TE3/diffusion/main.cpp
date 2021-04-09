#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "matrices.h"
#include "cond_init.h"
#include "util.h"
#include "methodes.h"


using namespace std;
using namespace std::chrono;
using namespace Eigen;

// Variables Globales

float L = 12.0, D = 1e-2;
float dx = 0.1, dt = 0.0;
float pi = M_PI;


int main(){

    //Variables necessaires locales

    string name, test_name = "uold_test.dat";
    
    
    float ug = 1.0, ud = -1.0;
    int Nx, Nt, choix = 0;
    float alpha;
    
    
    //Insertion des parametres de l'utilisateur
    cout << "TE 3 !!!" << endl;
    cout << "Fonction Diffusion" << endl;
    //cout << "Introduire le nom du fichier desiré" << endl;
    //cin >> name;
    cout << "Introduire le dt desiré" << endl;
    cin >> dt;
    cout << "Introduire le Nt desiré" << endl;
    cin >> Nt;
    cout << "Introduire: \n (1) poour explicite \n (2) pour implicite \n (3) pour Crank-Nicolson" << endl;
    cin >> choix;


    //Conditions initiales
    
    Nx    = int((L/dx) - 1);
    alpha = (D*dt)/pow(dx,2);
    
    //name += "_" + to_string(dt) + "_" + to_string(Nt) + ".dat";
    
    
    //Declaration des matrices et vecteurs

    MatrixXf malpha;
    MatrixXf invmalpha;
    VectorXf unew(Nx);
    //VectorXf uold = init2sinus(Nx);
    VectorXf uold = init2step(Nx);
    VectorXf V(Nx);
    
    //Initialisation des matrices et vecteurs
    
    V.setZero();
    V(0) = ug;
    V(Nx-1) = ud;
    
     

    //sm = second_membre(nord, sud, ouest, est);

    //Affichage et control
    
    cout << "Conditions initiales:\n "
         << "Nt = "    << Nt    << endl
         << "Nx = "    << Nx << endl
         << "dt = "    << dt    << "   dx = " << dx << endl
         << "alpha = " << alpha << endl
         << "D = "     << D     << endl;
    
    
    
 
    
    
    //____________Résolution du problème de diffusion_________________
        
    
    //écriture des entetes de la solution
    
    
    //Name tag
    ostringstream id_dt;
    id_dt << setprecision(2);
    id_dt << fixed;
    id_dt << dt;
    
    
    if ( choix == 1 ){
        
        
        name = "explicite" "-"+ id_dt.str() + "-" + to_string(Nt) + ".dat";
        ecrit_entete(name,Nx,Nt,dt,dx,alpha);
        
        //Boucle sur le temps pour calcul chaque solution
        for( int t = 0; t < Nt; t++){

            unew = avance_expl(uold,alpha,ug,ud);
            //ecriture des solutions
            ecrit(name,uold,ug,ud);
            uold = unew;

        }
    }

    if ( choix == 2 ){
        
        malpha = matl1d(Nx,alpha);
        invmalpha = malpha.inverse();
        
        name = "implicite" "-"+ id_dt.str() + "-" + to_string(Nt) + ".dat";
        ecrit_entete(name,Nx,Nt,dt,dx,alpha);
        
        //Boucle sur le temps pour calcul chaque solution
        for( int t = 0; t < Nt; t++){

            unew = implicite(uold,V,invmalpha,alpha);
            //ecriture des solutions
            ecrit(name,uold,ug,ud);
            uold = unew;

        }
    }
    
    if ( choix == 3 ){
        
        malpha = matl1d(Nx,alpha/2.0);
        invmalpha = malpha.inverse();
        
        malpha = matl1d(Nx,-alpha/2.0);
        
        name = "cranknic" "-"+ id_dt.str() + "-" + to_string(Nt) + ".dat";
        ecrit_entete(name,Nx,Nt,dt,dx,alpha);
        
        //Boucle sur le temps pour calcul chaque solution
        for( int t = 0; t < Nt; t++){
            unew = cNicolson(uold,V,malpha,invmalpha,alpha);
            //ecriture des solutions
            ecrit(name,uold,ug,ud);
            uold = unew;

        }
    }
    
    if( choix != 1 && choix != 2 && choix != 3) {
        cout << " Faaaaaiiiiiilllll  !!!!!! \n Mauvais Choix (~_~)" << endl;
        return 1;
    }
    
    return 0;
}


/*
//Affiche matrices
        if(Nx < 20) {
            cout << "Controle matrices:" << endl;
            cout << V << endl <<  "\n_______ M(alpha) _______\n" << malpha << "\n_______M(alpha).size()_______\n" << malpha.size() << endl;
        }
*/
        