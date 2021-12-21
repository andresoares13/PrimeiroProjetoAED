#include "Bagagem.h"

/**
 * Creates a luggage with the given data
 * @param ID luggage identification
 * @param peso luggage weight
 */
Bagagem::Bagagem(int ID, int peso) {
    this->ID=ID;
    this->peso=peso;
}

/**
 * Gets the luggage identification
 * @return luggage identification
 */
int Bagagem::getID() const {
    return this->ID;
}

/**
 * Gets the luggage weight
 * @return luggage weight
 */
int Bagagem::getPeso() const {
    return this->peso;
}

/**
 * Updates the luggage weight
 * @param peso luggage weight
 */
void Bagagem::setPeso(int peso) {
    Bagagem::peso = peso;
}
