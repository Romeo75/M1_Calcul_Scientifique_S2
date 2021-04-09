#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include <Eigen/Dense>

#include "fcts.h"
#include "methode.h"
#include "util.h"


using namespace std;
using namespace Eigen;

//Variables globales
extern float k;

int main(){
    
    k=1;
    
    //Variables nécessaires
    int N,select;
    float X_i, X_f, X_stp, t0;
    string name;
    
        
    //Insertion des parametres de l'utilisateur
    cout << "TE 1-B !!!" << endl;
    cout << "Fonction Derivation" << endl;
    cout << "Introduire le nom du fichier desiré" << endl;
    cin >> name; name = name + ".txt";
    cout << "Introduire le nombre de pas desirés" << endl;
    cin >> N;
    cout << "Introduire le pas initial desiré" << endl;
    cin >> X_i;
    cout << "Introduire le pas final desiré" << endl;
    cin >> X_f;
    cout << "Introduire l'abscise t0 finale desiré" << endl;
    cin >> t0;
    
    X_stp = pow((X_f/X_i),( 1/(N-1. )));
    
    //Creation des vecteurs des abscisses et ordonnées
    VectorXf X(N);
    VectorXf Y(N);
    VectorXf Delta(N);
    
    for (int i= 1; i<X.size(); i++){
        
        X(i) = X_i*pow(X_stp,i);
    
    }
    
    //Selection de la fonction et  tabulation de la même
    float (*f_chosen)(float); // Pointeur pour choisir une fonction arbitraire
    
    float (*f_chosen_deriv)(float);
    
    
    cout << "Introduire 1 pour la fonction sin et 2 pour l'exp" << endl;
    cin >> select;
    if (select == 1) {
        f_chosen = &(sin_k);
        f_chosen_deriv = &(sin_deriv_th);
    }
    if (select == 2) {
        f_chosen = &(exp_k);
        f_chosen_deriv = &(exp_deriv_th);
    }
        
    if( select != 1 and select != 2 ) {
        cout << "Aucune entrée valide !!!";
    }
    
    
    
    //Derivation
    cout << "Introduire: \n 1 pour la fonction décentrée gauche, \n 2 pour la fonction décentrée droite \n 3 pour la fonction décentrée centrée, \n" << endl;
    cin >> select;   
    
    for (int i = 0; i<X.size(); i++ ){

    if (select == 1) { 
        Y(i) = cleft(f_chosen, t0, X(i) );
        Delta(i) = abs( Y(i) - f_chosen_deriv(t0) );
        
        }
        
        if (select == 2) { 
        Y(i) = cright(f_chosen, t0, X(i) );
        Delta(i) = abs( Y(i) - f_chosen_deriv(t0) );
        //cout << "Y: \n" << Delta(i) << endl;
        }
            
        if (select == 3){ 
        Y(i) = ccenter(f_chosen, t0, X(i) );
        Delta(i) = abs( Y(i) - f_chosen_deriv(t0) );
        //cout << "Y: \n" << Delta(i) << endl;
        }
        
        if (select != 1 and select != 2 and select != 3 ) {
            cout << "Aucune entrée valide !!!";
        }        
    }
    
    //cout << " Vectors: " << endl;
    //cout << "X :\n" << X << endl << "Y: \n" << Y << endl;
    
    
    
    //Ecriture des données sur un fichier .txt avec le nom donné
    cout << "Tabulé !!!"<<endl;
    
    ecrit(name, X, Delta); 
    cout << "Ecrit !!!"<<endl;
    
    return 0;
    
}