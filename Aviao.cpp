//
// Created by andre on 02-12-2021.
//

#include "Aviao.h"

const string &Aviao::getMatricula() const {
    return matricula;
}

int Aviao::getCapacidade() const {
    return capacidade;
}

const vector<Voo> &Aviao::getPlano() const {
    return plano;
}

void Aviao::setMatricula(const string &matricula) {
    Aviao::matricula = matricula;
}

void Aviao::setCapacidade(int capacidade) {
    Aviao::capacidade = capacidade;
}

const queue<Service> &Aviao::getServices() const {
    return services;
}

void Aviao::addServices(const Service) {
    Aviao::services = services;
}

void Aviao::addVoo(const Voo) {
    Aviao::plano = plano;
}

void Aviao::setCapacity() { //Sets the capacity of each flight equal to the plane's capacity
    for (int i=0;i<this->plano.size();i++){
        plano[i].setCapacity(this->capacidade);
    }
}
