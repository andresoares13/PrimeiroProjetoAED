#include <stdexcept>
#include "ModelCar.h"

/**
 * Creates a cart model based on the type
 * @param type
 */
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

/**
 * Gets the cart model
 * @return cart model
 */
const string &ModelCar::getType() const {
    return type;
}

/**
 * Gets the maximum number of stacks
 * @return maximum number of stacks
 */
int ModelCar::getPilhas() const {
    return pilhas;
}

/**
 * Gets the maximum number of luggage per stack
 * @return maximum number of luggage per stack
 */
int ModelCar::getMalas() const {
    return malas;
}


