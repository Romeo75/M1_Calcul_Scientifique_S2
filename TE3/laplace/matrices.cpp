#include <eigen3/Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

// Sub-Matrice Diagonale
MatrixXf mat_diag(int n){

    MatrixXf result = MatrixXf::Zero(n,n);

    for (int i=0; i<n-1; i++){

        result(i,i+1) = 1.;
        result(i,i) = -4.;
        result(i+1,i) = 1.;

    }

    result(n-1,n-1) = -4.;

    return result;
}

// Sub matrice hors diagonale
MatrixXf mat_id(int n){
    return MatrixXf::Identity(n,n);
}

MatrixXf matl2d(int nl, int nc){

    int N = nl*nc;

    MatrixXf result(N,N);

    for (int i=0; i<N; i+=nc){


        //Diagonale
        result.block( i,i,nc,nc ) = mat_diag(nc);

        if (i < N-nc){
            //Elements hors diagonale
            result.block(i+nc,i, nc, nc) = mat_id(nc);
            result.block(i,i+nc,nc, nc) = mat_id(nc);

        }

    }

    return result;
}
