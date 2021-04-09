#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using namespace std;

float T_Nord=0,T_Sud=0,T_Est=0,T_Ouest=0;

void condlimites1( VectorXf &nord, VectorXf &sud, VectorXf &ouest, VectorXf &est){

cout << "Inserer la temperature desirée de la paroi Nord: " << endl;
cin >> T_Nord;

cout << "Inserer la temperature desirée de la paroi Sud: " << endl;
cin >> T_Sud;

cout << "Inserer la temperature desirée de la paroi Est: " << endl;
cin >> T_Est;

cout << "Inserer la temperature desirée de la paroi Ouest: " << endl;
cin >> T_Ouest;

nord.setConstant(T_Nord);
sud.setConstant(T_Sud);
est.setConstant(T_Est);
ouest.setConstant(T_Ouest);

}


VectorXf second_membre(const VectorXf &nord, const VectorXf &sud, VectorXf &ouest, VectorXf &est){

    int N = nord.size();
    int n = est.size();
    //cout << "N: " << N  << "    n" << n << endl;
    VectorXf B = VectorXf::Zero(N*n);

    B.head(N) = -1*nord;
    B.tail(N) = -1*sud;

    for( int i = 0; i<n ; i++){

        B(i*N) = B(i*N) -ouest(i);
        B((i+1)*N-1) = B((i+1)*N-1) -est(i);

    }
    return B;
}
