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
float k = 1.0;
float m = 1.0;
float l = 1.0;

int main(){
    
    //Variables nécessaires
    int Deriv,N,select;
    float t0, Y_0, Vy_0, step,tf;
    string name;
    
        
    //Insertion des parametres de l'utilisateur
    cout << "TE 2 !!!" << endl;
    cout << "Fonction EDO(2)" << endl;
    //cout << "Introduire l'ordre du systeme differentiel" << endl;
    //cin >> Deriv;
    cout << "Introduire le nom du fichier desiré" << endl;
    cin >> name;
    cout << "Introduire le pas desiré" << endl;
    cin >> step;
    //cout << "Introduire l'abscise t0 initiale desirée" << endl;
    //cin >> t0;
    //cout << "Introduire l'abscise tf finale desirée" << endl;
    //cin >> tf;
    //cout << "Introduire l'ordonnée Y_0 initiale desirée" << endl;
    //cin >> Y_0;
    cout << "Introduire la vitesse Vy_0 initiale desirée" << endl;
    cin >> Vy_0;
    
    //Conditions initiales
    Deriv = 2;
    t0 = 0; tf = 20; 
    
    Y_0 = 0.0;
    //Vy_0 = 2.1;
    
    N = int((tf-t0)/step);
    
    MatrixXf data_calc(N,Deriv);
    MatrixXf data_th(N,Deriv);
    
    //Creation des vecteurs des abscisses et ordonnées
    VectorXf t(N);
    //VectorXf data_calc.col(0)(N);
    //VectorXf data_th.col(1)(N);
    VectorXf Delta(N);
    
    //Initialisation des ordonnées
    data_calc.col(0)[0] = Y_0;
    data_calc.col(1)[0] = Vy_0;
    
    data_th.col(0)[0] = Y_0;
    data_th.col(1)[0] = Vy_0;
    
    
    for (int i= 0; i<t.size(); i++){
        
        t(i) = t0 + i*step;
        
    }
    
    //Selection de la fonction et  tabulation de la même
    Eigen::VectorXf (*df_chosen)(float t, const Eigen::VectorXf y); // Pointeur pour choisir une fonction arbitraire
    
    Eigen::VectorXf (*f_chosen_th)(float t, const Eigen::VectorXf y);
    
    
    cout << "Introduire 1 pour le systeme EDO (2)" << endl;
    cin >> select;
    if (select == 1) {
        df_chosen = &(dvect_calc);
        f_chosen_th = &(vect_th);
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

                data_calc.row(i+1) = euler_progres(df_chosen, t(i), data_calc.row(i), step );

                data_th.row(i+1) = f_chosen_th(t(i+1),data_th.row(0));

                //Delta(i) = data_calc.row(i) - data_th.row(i) ;

            }

            if (select == 2) {

                data_calc.row(i+1) = milieu(df_chosen, t(i), data_calc.row(i), step );

                data_th.row(i+1) = f_chosen_th(t(i+1),data_th.row(0));

                //Delta(i) = data_calc.row(i) - data_th.row(i) ;
                //cout << "data_calc.col(0): \n" << Delta(i) << endl;

            }

            if (select == 3){ 

               data_calc.row(i+1) = rk4(df_chosen, t(i), data_calc.row(i), step );

                data_th.row(i+1) = f_chosen_th(t(i+1),data_th.row(0));

                //Delta(i) = data_calc.row(i) - data_th.row(i) ;
                //cout << "data_calc.col(0): \n" << Delta(i) << endl;
            }

            if (select != 1 and select != 2 and select != 3 ) {
                cout << "Aucune entrée valide !!!";
            }        
    }
    
    //cout << " Vectors: " << endl;
    //cout << "X :\n" << X << endl << "Y_calc: \n" << Y_calc << endl;
    
    
    
    //Ecriture des données sur un fichier .txt avec le nom donné
    cout << "Tabulé !!!"<<endl;
    
    ecrit(name, step, t, data_calc, data_th, Delta); 
    cout << "Ecrit !!!"<<endl;
    
    return 0;
    
}