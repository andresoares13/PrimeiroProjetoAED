#include <algorithm>
#include <iostream>
#include "Aviao.h"

/**
 * Creates a plane with the given data and sets its capacity and weight limit per luggage
 * @param matricula license plate
 * @param tipo plane model
 * @param plano list of flights
 * @param servicesRealizar queue of services to be performed
 */
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

/**
 * Gets the license plate of the plane
 * @return license plate
 */
string Aviao::getMatricula() const {
    return this->matricula;
}

/**
 * Gets the plane model
 * @return plane model
 */
string Aviao::getTipo() const {
    return this->tipo;
}

/**
 * Gets the maximum number of passengers the plane can take
 * @return plane capacity
 */
int Aviao::getCapacidade() const {
    return this->capacity;
}

/**
 * Gets a list of flights for the plane
 * @return list of flights
 */
list<Voo> Aviao::getPlano() const {
    return this->plano;
}

/**
 * Gets a queue of services already performed
 * @return queue of services already performed
 */
queue<Service> Aviao::getServicesRealizados() const {
    return this->servicesRealizados;
}

/**
 * Gets a queue of services to perform
 * @return queue of services to perform
 */
queue<Service> Aviao::getServicesRealizar() const {
    return this->servicesRealizar;
}

/**
 * Adds a flight to the list of flights
 * @param voo object of the class Voo
 */
void Aviao::addVoo(const Voo& voo) {
    plano.push_back(voo);
}

/**
 * Checks if the plane is currently not working due to malfunctions.
 * If that's the case, returns true, otherwise returns false
 * @return bool
 */
bool Aviao::isBroken() const {
    return state;
}

/**
 * Sets the state to true, when the plane is currently not working due to malfunctions
 */
void Aviao::setBroken() {
    state=true;
}

/**
 * Gets the weight limit per luggage
 * @return weight limit per luggage
 */
int Aviao::getLimitPerBag() const {
    return LimitPerBag;
}

/**
 * Adds a service to the vector of services to sort
 * @param s object of the class Service
 */
void Aviao::AddToSort(const Service s) {
    ServiceSorter.push_back(s);
}

/**
 * Sorts the services on the vector ServiceSorter and then adds it to the queue servicesRealizar
 */
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
/**
 * First checks if the service and the flight have the same date and if so it does the service itself
 * @return returns true if the service was done (which implies that it was on the same date of the flight), false otherwise
 */
bool Aviao::isService() {
    bool SDone=false;
    if (servicesRealizar.front().getData()==plano.begin()->getPartida()){
        servicesRealizados.push(servicesRealizar.front());
        servicesRealizar.pop();
        SDone=true;
    }
    return SDone;
}
/**
 * Goes through the list of flights and if there is a flight with the same parameters as the ones given then the flight is performed.
 * It also adds the flight done as well as any other flight with a previous date to the vector of completed flights
 * It lets the user know the specifics of the Car that transports their bag should they choose the auto check in option
 * Finally it rewrites the list of flights so that we are only left with the ones still yet to be done
 * @param data date of the flight
 * @param origem place of origin
 * @param destino destination
 * @param checkin true if the user chose the auto check in option
 * @return returns true if the plane was able to make the flight, in other words, if the flight with the given parameters exists
 */
bool Aviao::Fly(string data, string origem, string destino, bool checkin) {
    bool IFlew=false;
    bool Done=false;
    vector<Voo> NotRealizados;
    Voo v=plano.front();
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if (Done== false){
            planoDone.push_back((*it));
        }
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
            Done= true;
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

/**
 * Gets all the flights in a vector
 * @return vector of flights
 */
vector<Voo> Aviao::getPlanoVector() {
    vector<Voo> voos;
    voos.insert(voos.end(),plano.begin(),plano.end());
    return voos;
}

/**
 * Sets the list of flights to the data given
 * @param lv list of flights
 */
void Aviao::setPlano(list<Voo> lv) {
    this->plano=lv;
}

/**
 * Sets the attributes servicesRealizar and servicesRealizados to sv and sv2, respectively
 * @param sv queue of services
 * @param sv2 queue of services
 */
void Aviao::setServices(queue<Service> sv, queue<Service> sv2) {
    servicesRealizar=sv;
    servicesRealizados=sv2;
}

/**
 * Updates the flight with the same date, origin and destination given
 * @param v object of the class Voo
 */
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

/**
 * Displays all the information about the flights with the destination given
 * @param destination destination of the flight
 * @return bool
 */
bool Aviao::printVoo(string destination) {
    bool value=false;
    list<Voo> :: iterator it=plano.begin();
    list<Voo> :: iterator it2=plano.end();
    while (it!=it2){
        if ((*it).getDestino()==destination){
            value=true;
            cout<<"Id: "<<(*it).getNumero()<<" Date: "<<(*it).getPartida()<<" Origin: "<<(*it).getOrigem()<<" Destination: "<<(*it).getDestino()<<" Duration: "<<(*it).getDuration()<<endl;
        }
        it++;
    }
    return value;
}

/**
 * Adds the flight done to the vector of flights done (planoDone)
 * @param v object of the class Voo
 */
void Aviao::addplanoDone(Voo v) {
    planoDone.push_back(v);
}

/**
 * Gets all the flights already done
 * @return vector of flights already done
 */
vector<Voo> Aviao::getDoneFlights() {
    return planoDone;
}