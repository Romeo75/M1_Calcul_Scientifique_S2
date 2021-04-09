#include "util.h"

void ecrit( std::string name, const Eigen::VectorXf &X, const Eigen::VectorXf &Y ){
    
    std::ofstream points;
    points.open(name);
    
    points << "#Nombre de pas: " << X.size() << std::endl;
    points << "#Min du pas: " << X.minCoeff() << std::endl;
    points << "#Max du pas: " << X.maxCoeff() << std::endl;
    points << "Min de l'erreur: " << Y.minCoeff() << std::endl;
    points << "Max de l'erreur: " << Y.maxCoeff() << std::endl;
    
    for (int i= 1; i<X.size(); i++){
        
        points << X(i) << "	" << Y(i) << std::endl;
        
    }
    
    points.close();
    
}