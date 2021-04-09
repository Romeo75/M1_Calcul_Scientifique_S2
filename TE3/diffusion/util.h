//#define IO_H
//#ifndef IO_H
#include <eigen3/Eigen/Dense>
#include <string>


using namespace std;
using namespace Eigen;


//#include <eigen3/Eigen/Dense>
void ecrit_entete( string name, int Nx, int Nt, float dt, float dx, float alpha );

void ecrit( const string name, const VectorXf u, const float Ug , const float Ud );

void w_test(const string name, const VectorXf uold, const float dx);