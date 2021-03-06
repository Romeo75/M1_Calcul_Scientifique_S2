#include "fcts.h"
#include<functional>
#include <Eigen/Dense>

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y );

Eigen::VectorXf euler_progres(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h);

Eigen::VectorXf milieu(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h);

Eigen::VectorXf rk4(std::function<Eigen::VectorXf(float,Eigen::VectorXf)> df, float t, Eigen::VectorXf y, float h);
/*
float cright(std::function<float(float)> f, float t0, float h);

float cleft(std::function<float(float)> f, float t0, float h);

float ccenter(std::function<float(float)> f, float t0, float h);
*/