//
// Created by andre on 13-12-2021.
//

#include "Bagagem.h"

Bagagem::Bagagem(int ID, int peso) {
    this->ID=ID;
    this->peso=peso;
}

int Bagagem::getID() const {
    return this->ID;
}

int Bagagem::getPeso() const {
    return this->peso;
}

void Bagagem::setPeso(int peso) {
    Bagagem::peso = peso;
}
