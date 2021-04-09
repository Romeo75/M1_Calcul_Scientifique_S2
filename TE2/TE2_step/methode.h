#include "fcts.h"
#include<functional>
#include <Eigen/Dense>

void tabule(std::function<float(float)> f, const Eigen::VectorXf& X, Eigen::VectorXf& Y );

float euler_progres(std::function<float(float,float)> df, float t, float y, float h);

float milieu(std::function<float(float,float)> df, float t0, float y0, float h);

float rk4(std::function<float(float,float)> df, float t0, float y0, float h);
/*
float cright(std::function<float(float)> f, float t0, float h);

float cleft(std::function<float(float)> f, float t0, float h);

float ccenter(std::function<float(float)> f, float t0, float h);
*/