//
// Created by andre on 15-12-2021.
//

#include <stdexcept>
#include "ModelCar.h"

ModelCar::ModelCar(string type) {
    if(type=="X"){
        pilhas=10;
        malas=10;
        this->type=type;
    }
    else if (type=="Y"){
        pilhas=5;
        malas=5;
        this->type=type;
    }
    else{
        throw invalid_argument("That model does not exist");
    }
}

const string &ModelCar::getType() const {
    return type;
}

int ModelCar::getPilhas() const {
    return pilhas;
}

int ModelCar::getMalas() const {
    return malas;
}


