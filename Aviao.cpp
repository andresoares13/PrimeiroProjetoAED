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

bool Aviao::Fly(string data, string origem, string destino, bool checkin) {
    bool IFlew=false;
    vector<Voo> NotRealizados;
    Voo v=plano.front();
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if((*it).getPartida()==data&&(*it).getOrigem()==origem&&(*it).getDestino()==destino){
            v=(*it);
            CarrinhoDeTransporte car=(*it).AutoBag();
            string x;
            int chariots;
            if (car.getBagagem()[0].getCapacity()==10){
                x="X";
            } else{
                x="Y";
            }
            chariots=car.getBagagem().size();
            if (checkin==true){
                cout<<endl<<"In accordance to the number of passengers in this flight the carriages of the Transportation vehicle that will take your luggage will be of type "<<x<<endl<<endl;
                cout<<"The car will have a total of "<<chariots<<" carriages so that the luggage of every person will have a spot there, worry not it will not get lost"<<endl<<endl;
                cout<<"All the bags have been moved to the car"<<endl<<endl;
            }
            cout<<"The flight has begun"<<endl<<endl;
            IFlew=true;
        }
        else{
            NotRealizados.push_back(*it);
        }
        it++;
    }
    plano.clear();
    int ciclo=NotRealizados.size();
    for (int i=0;i<ciclo;i++){
        if (NotRealizados[0]<v){
            NotRealizados.erase(NotRealizados.begin());
        }
    }
    plano.insert(plano.begin(), NotRealizados.begin(), NotRealizados.end());
    return IFlew;
}


vector<Voo> Aviao::getPlanoVector() {
    vector<Voo> voos;
    voos.insert(voos.end(),plano.begin(),plano.end());
    return voos;
}

void Aviao::setPlano(list<Voo> lv) {
    this->plano=lv;
}

void Aviao::setServices(queue<Service> sv, queue<Service> sv2) {
    servicesRealizar=sv;
    servicesRealizados=sv2;
}

void Aviao::setVoo(Voo v) {
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if((*it).getPartida()==v.getPartida()&&(*it).getOrigem()==v.getOrigem()&&(*it).getDestino()==v.getDestino()){
            (*it)=v;
        }
        it++;
    }
}

bool Aviao::printVoo(string destination) {
    bool value=false;
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if ((*it).getDestino()==destination){
            value=true;
            cout<<"Id: "<<(*it).getNumero()<<" Date: "<<(*it).getPartida()<<" Origin: "<<(*it).getOrigem()<<" Destination: "<<(*it).getDestino()<<" Duration: "<<(*it).getDuration()<<" ("<<(*it).ticketsAvailable()<<" tickets available)"<<endl;
        }
        it++;
    }
    return value;
}


