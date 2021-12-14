//
// Created by andre on 02-12-2021.
//

#include "Aviao.h"

Aviao::Aviao(string matricula, string tipo, int capacidade, vector<Voo> plano, queue<Service> servicesRealizar) {
    this->matricula=matricula;
    this->tipo=tipo;
    this->capacity=capacidade;
    this->plano=plano;
    this->servicesRealizar=servicesRealizar;
    this->servicesRealizados={};
    this->state=false;
}

string Aviao::getMatricula() const {
    return this->matricula;
}

string Aviao::getTipo() const {
    return this->tipo;
}

int Aviao::getCapacidade() const {
    return this->capacity;
}

vector<Voo> Aviao::getPlano() const {
    return this->plano;
}

queue<Service> Aviao::getServicesRealizados() const {
    return this->servicesRealizados;
}

queue<Service> Aviao::getServicesRealizar() const {
    return this->servicesRealizar;
}

void Aviao::addVoo(const Voo& voo) {
    plano.push_back(voo);
}

void Aviao::addServices(const Service &service) {
    servicesRealizar.push(service);
}

bool Aviao::isBroken() const {
    return state;
}

void Aviao::setBroken() {
    state=true;
}

