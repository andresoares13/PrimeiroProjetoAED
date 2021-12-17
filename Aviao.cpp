//
// Created by andre on 02-12-2021.
//

#include <algorithm>
#include "Aviao.h"

Aviao::Aviao(string matricula, string tipo,  list<Voo> plano, queue<Service> servicesRealizar) {
    this->matricula=matricula;
    this->tipo=tipo;
    this->plano=plano;
    this->servicesRealizar=servicesRealizar;
    this->servicesRealizados={};
    this->state=false;
    if (matricula.substr(0,1)=="A"){
        LimitPerBag=40;
        capacity=200;
    }
    if (matricula.substr(0,1)=="B"){
        LimitPerBag=20;
        capacity=100;
    }
    if (matricula.substr(0,1)=="S"){
        LimitPerBag=60;
        capacity=400;
    }

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

list<Voo> Aviao::getPlano() const {
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


bool Aviao::isBroken() const {
    return state;
}

void Aviao::setBroken() {
    state=true;
}

int Aviao::getLimitPerBag() const {
    return LimitPerBag;
}

void Aviao::AddToSort(const Service s) {
    ServiceSorter.push_back(s);
}

void Aviao::SortAndPush() {
    while(servicesRealizar.size()>0){
        ServiceSorter.push_back(servicesRealizar.front());
        servicesRealizar.pop();
    }
    sort(ServiceSorter.begin(),ServiceSorter.end());
    for (int i=0;i<ServiceSorter.size();i++){
        servicesRealizar.push(ServiceSorter[i]);
    }
}

