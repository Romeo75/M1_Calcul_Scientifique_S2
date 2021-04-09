#include "fcts.h"
#include<functional>
#include <Eigen/Dense>

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y );