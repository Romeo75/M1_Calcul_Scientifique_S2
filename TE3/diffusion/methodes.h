#include <eigen3/Eigen/Dense>


VectorXf avance_expl( const VectorXf uold, const float alpha, const float ug,  const float ud);

VectorXf implicite( const VectorXf uold,const VectorXf V, const MatrixXf invmalpha, const float alpha);

VectorXf cNicolson( const VectorXf uold,const VectorXf V, const MatrixXf malpha, const MatrixXf invmalpha, const float alpha);