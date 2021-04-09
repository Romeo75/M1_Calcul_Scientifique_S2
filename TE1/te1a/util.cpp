#include "util.h"

void ecrit( std::string name, const Eigen::VectorXf& X, const Eigen::VectorXf& Y){
    
    std::ofstream points;
    points.open(name);
    
    for (int i= 1; i<X.size(); i++){
        
        points << X(i) << "	" << Y(i) << std::endl;
        
    }
    
    points.close();
    
}