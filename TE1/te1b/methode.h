#include "fcts.h"
#include<functional>
#include <Eigen/Dense>

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y );

float cright(std::function<float(float)> f, float t0, float h);

float cleft(std::function<float(float)> f, float t0, float h);

float ccenter(std::function<float(float)> f, float t0, float h);