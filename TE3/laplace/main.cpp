#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include <eigen3/Eigen/Dense>
#include <chrono>

#include "matrices.h"
#include "condlim.h"
#include "io.h"


using namespace std;
using namespace std::chrono;
using namespace Eigen;

// Variables Globales



int main(){

    //Variables necessaires locales

    string name;
    int nl = 3,dX=4;
    int nc = 4,dY=5;
    int N;
    float p = 0.;

    //Insertion des parametres de l'utilisateur
    cout << "TE 3 !!!" << endl;
    cout << "Fonction Laplace" << endl;
    cout << "Introduire le nom du fichier desiré" << endl;
    cin >> name;
    cout << "Introduire le nombre de lignes desirées" << endl;
    cin >> nl;
    cout << "Introduire le nombre de colonnes desirées" << endl;
    cin >> nc;
    /*
    cout << "Introduire le nombre dX desiré" << endl;
    cin >> dX;
    cout << "Introduire le nombre dY desiré" << endl;
    cin >> dY;
    */

    //Conditions initiales

    N = nc * nl;
    p = dX/(nl+1.);
    p = dY/(nl+1.);
    
    name += "_" + to_string(nl) + "_" + to_string(nc) + ".dat";

    //Declaration des matrices et vecteurs

    MatrixXf mat;
    VectorXf nord(nc);
    VectorXf sud(nc);
    VectorXf est(nl);
    VectorXf ouest(nl);
    VectorXf sm;
    VectorXf temp;

    //Initialisation des matrices

    mat = matl2d(nl,nc);

    //Insertion des temperatures
    condlimites1(nord, sud, ouest, est);

    sm = second_membre(nord, sud, ouest, est);

    //Affichage
    if( N < 20) {
            cout  << mat << endl;
    cout << sm << endl; }

    //Résolution du systeme et mésure de performance

    auto start = high_resolution_clock::now();

    //temp = mat.colPivHouseholderQr().solve(sm);
    temp = mat.ldlt().solve(sm);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::milliseconds>(stop-start).count();

    // << "\n Temps de calcul:    ";
    cout << duration << " ms"<<endl;

    //écriture des solutions
    ecritemp(name,temp,nord,sud,ouest,est,p);

    return 0;
}
