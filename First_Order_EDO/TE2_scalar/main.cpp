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
extern float a;
extern float tau;

int main(){
    
    a=4;
    tau = sqrt(2.);
    
    //Variables nécessaires
    int N,select;
    float t0, Y_0, step,tf;
    string name;
    
        
    //Insertion des parametres de l'utilisateur
    cout << "TE 2 !!!" << endl;
    cout << "Fonction EDO" << endl;
    cout << "Introduire le nom du fichier desiré" << endl;
    cin >> name; name = name + ".txt";
    cout << "Introduire le pas desiré" << endl;
    cin >> step;
    //cout << "Introduire l'abscise t0 initiale desirée" << endl;
    //cin >> t0;
    //cout << "Introduire l'abscise tf finale desirée" << endl;
    //cin >> tf;
    //cout << "Introduire l'ordonnée Y_0 initiale desirée" << endl;
    //cin >> Y_0;
    
    t0 = 0; tf = 20; Y_0 = 0.5;
    
    N = int((tf-t0)/step);
    
    //Creation des vecteurs des abscisses et ordonnées
    VectorXf t(N);
    VectorXf Y_calc(N);
    VectorXf Y_th(N);
    VectorXf Delta(N);
    
    //Initialisation des ordonnées
    Y_calc(0) = Y_0;
    
    for (int i= 0; i<t.size(); i++){
        
        t(i) = t0 + i*step;
        
    }
    
    //Selection de la fonction et  tabulation de la même
    float (*df_chosen)(float, float); // Pointeur pour choisir une fonction arbitraire
    
    float (*f_chosen_th)(float, float, float);
    
    
    cout << "Introduire 1 pour le systeme EDO (1)" << endl;
    cin >> select;
    if (select == 1) {
        df_chosen = &(dydt);
        f_chosen_th = &(y_th);
    }
    
    /*
    if (select == 2) {
        df_chosen = &(exp_k);
        f_chosen_th = &(exp_deriv_th);
    }
    // add this condindition to the next if "and select != 2"
    */ 
    
    if( select != 1 ) {
        cout << "Aucune entrée valide !!!";
    }
    
    
    // ODE integrating factors
    cout << "Introduire: \n 1 pour la methode d'euler, \n 2 pour la methode des milieux \n 3 pour la methode de RK4, \n" << endl;
    cin >> select;   
    
    for (int i = 0; i<t.size()-1; i++ ){

    if (select == 1) {
        
            Y_calc(i+1) = euler_progres(df_chosen, t(i), Y_calc(i), step );
            Y_th(i) = f_chosen_th(t(i),t0,Y_0);
            Delta(i) = Y_calc(i) - Y_th(i) ;
        
        }
        
        if (select == 2) {
            
            Y_calc(i+1) = milieu(df_chosen, t(i), Y_calc(i), step );
            Y_th(i) = f_chosen_th(t(i),t0,Y_0);
            Delta(i) = Y_calc(i) - Y_th(i) ;
            //cout << "Y_calc: \n" << Delta(i) << endl;
        
        }
            
        if (select == 3){ 
        
            Y_calc(i+1) = rk4(df_chosen, t(i), Y_calc(i), step );
            Y_th(i) = f_chosen_th(t(i),t0,Y_0);
            Delta(i) = Y_calc(i) - Y_th(i) ;
            //cout << "Y_calc: \n" << Delta(i) << endl;
        }
        
        if (select != 1 and select != 2 and select != 3 ) {
            cout << "Aucune entrée valide !!!";
        }        
    }
    
    //cout << " Vectors: " << endl;
    //cout << "X :\n" << X << endl << "Y_calc: \n" << Y_calc << endl;
    
    
    
    //Ecriture des données sur un fichier .txt avec le nom donné
    cout << "Tabulé !!!"<<endl;
    
    ecrit(name, t, Y_calc, Y_th, Delta); 
    cout << "Ecrit !!!"<<endl;
    
    return 0;
    
}