#include <Eigen/Dense>
#include <fstream>

void ecrit( std::string name, const Eigen::VectorXf &X, const Eigen::VectorXf &Y_calc, const Eigen::VectorXf &Y_th, const Eigen::VectorXf &Delta );