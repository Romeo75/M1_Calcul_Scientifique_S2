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

int main(){
    
    //Variables nécessaires
    int N,select;
    float X_i, X_f, X_stp;
    string name;
    float a,k,y0,t0;
        
    //Insertion des parametres de l'utilisateur
    cout << "TE 1-A !!!" << endl;
    cout << "Fonction y(t) = t²" << endl;
    cout << "Introduire le nom du fichier desiré" << endl;
    cin >> name; name = name + ".txt";
    cout << "Introduire le nombre de points desirés" << endl;
    cin >> N;
    cout << "Introduire l'abscise initiale desirée" << endl;
    cin >> X_i;
    cout << "Introduire l'abscise finale desirée" << endl;
    cin >> X_f;
    
    X_stp = (X_f - X_i)/N;
    
    //Creation des vecteurs des abscisses et ordonnées
    VectorXf X(N,1);
    VectorXf Y(N,1);
    
    for (int i= 1; i<X.size(); i++){
        
        X(i) = X_i + i*X_stp;
    
    }
    
    //cout << " Vectors: " << endl;
    //cout << "X :\n" << X << endl << "Y: \n" << Y << endl;
    
    //Selection de la fonction et  tabulation de la même
    cout << "Introduire 1 pour la fonction carre et 2 pour la logistique" << endl;
    cin >> select;
    if (select) tabule(y, X, Y );
    if (select){
        
        cout<<"Introduire le parametre a:"<<endl;
        cin >> a;
        cout<<"Introduire le parametre k:"<<endl;
        cin >> k;
        cout<<"Introduire le parametre t0:"<<endl;
        cin >> t0;
        cout<<"Introduire le parametre y0:"<<endl;
        cin >> y0;
        tabule(logistique, X, Y );
        
    }
    else {
        cout << "Aucune entrée valide !!!";
        return 1;
    }
    
    //Ecriture des données sur un fichier .txt avec le nom donné
    cout << "Tabulé !!!"<<endl;
    ecrit(name, X, Y); 
    cout << "Ecrit !!!"<<endl;
    
    return 0;
    
}