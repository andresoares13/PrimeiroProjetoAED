#include <algorithm>
#include <iostream>
#include "Aviao.h"

Aviao::Aviao(string matricula, string tipo,  list<Voo> plano, queue<Service> servicesRealizar) {
    this->matricula=matricula;
    this->tipo=tipo;
    this->plano=plano;
    this->servicesRealizar=servicesRealizar;
    this->servicesRealizados={};
    this->state=false;
    if (tipo.substr(0,1)=="A"){
        LimitPerBag=40;
        capacity=200;
    }
    if (tipo.substr(0,1)=="B"){
        LimitPerBag=20;
        capacity=200;
    }
    if (tipo.substr(0,1)=="S"){
        LimitPerBag=60;
        capacity=200;
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

bool Aviao::isService() {
    bool SDone=false;
    if (servicesRealizar.front().getData()==plano.begin()->getPartida()){
        servicesRealizados.push(servicesRealizar.front());
        servicesRealizar.pop();
        SDone=true;
    }
    return SDone;
}

bool Aviao::Fly(string data, string origem, string destino) {
    bool IFlew=false;
    vector<Voo> NotRealizados;
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if((*it).getPartida()==data&&(*it).getOrigem()==origem&&(*it).getDestino()==destino){
            CarrinhoDeTransporte car=(*it).AutoBag();
            IFlew=true;
        }
        else{
            NotRealizados.push_back(*it);
        }
        it++;
    }
    plano.clear();
    plano.insert(plano.begin(), NotRealizados.begin(), NotRealizados.end());
    return IFlew;
}

bool Aviao::removeFuncionario(const string funcinario) {
    vector<Service> s1;
    vector<Service> s2;
    while(servicesRealizar.size()>0){
        s1.push_back(servicesRealizar.front());
        servicesRealizar.pop();
    }
    for (int i=0;i<s1.size();i++){
        if(s1[i].getFuncionario()!=funcinario){
            s2.push_back(s1[i]);
        }
        else{
            //
        }
    }
    std::sort(s2.begin(), s2.end());
    return false;
}

vector<Voo> Aviao::getPlanoVector() {
    vector<Voo> voos;
    voos.insert(voos.end(),plano.begin(),plano.end());
    return voos;
}

