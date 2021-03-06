#include <Eigen/Dense>
#include <fstream>

void ecrit( std::string name, float step, const Eigen::VectorXf &X, const Eigen::MatrixXf &Y_calc, const Eigen::MatrixXf &Y_th, const Eigen::MatrixXf &Delta );