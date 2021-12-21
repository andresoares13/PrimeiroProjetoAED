#include "Aeroporto.h"
#include <iomanip>
#include <algorithm>

/**
 * Creates an airport object
 */
Aeroporto::Aeroporto(): locais(LocalTransporte("", 0, {}, true)){}

/**
 * Adds a plane to the vector of planes
 * @param plane object of the class Aviao
 */
void Aeroporto::addPlane(Aviao plane) {
    planes.push_back(plane);
}

/**
 * Gets all the planes on the airport
 * @return vector of planes
 */
vector<Aviao> Aeroporto::GetPlanes() {
    return planes;
}

/**
 * Gets the total number of flights the airport has
 * @return number of flights
 */
int Aeroporto::getnumFLights() {
    int counter=0;
    for (int i=0;i<planes.size();i++){
        counter+=planes[i].getPlano().size();
    }
    return counter;
}

/**
 * Adds a transport location to the binary search tree locais
 * @param local object of the class LocalTransporte
 */
void Aeroporto::addLocal(const LocalTransporte &local) {
    locais.insert(local);
}

/**
 * Checks if the transport type received is valid
 * @param tipo transport type
 */
void verifyTipo(string tipo) {
    if(tipo!="metro" && tipo!="autocarro" && tipo!="comboio" && tipo!="")
        throw invalid_argument("Invalid transport");
}

/**
 * Displays the content of the BST
 * @param os
 * @param l1 object of the class LocalTransporte
 * @return
 */
ostream& operator<<(ostream& os, const LocalTransporte& l1){
    if(!l1.isAvailable())
        return os;
    string horario;
    for(int i=0; i<l1.getHorarios().size(); i++){
        float num=l1.getHorarios()[i];
        string temp;
        if(num<10)
            temp=to_string(num).substr(0, 4);
        else
            temp=to_string(num).substr(0, 5);
        horario+= temp;
        horario+="    ";
    }
    os<<l1.getTipo()<<" a "<<l1.getDistance()<<" km "<<endl<<"Horario: "<<horario<<endl;
    return os;
}

/**
 * Displays the content of the BST locais
 */
void Aeroporto::printLocais() const {
    locais.printTree();
}

/**
 * Gets all locations close to the airport according to the criteria chosen by the passenger
 * @param tipo transport type
 * @param distance maximum distance desired
 * @return vector of transport locations
 */
vector<LocalTransporte> Aeroporto::getLocais(string tipo, float distance) const {
    vector<LocalTransporte> res;
    BSTItrIn<LocalTransporte> it(locais);
    verifyTipo(tipo);
    while(!it.isAtEnd()){
        if(tipo=="" && distance==0)
            res.push_back(it.retrieve());
        else if(tipo!=""  && distance==0 && it.retrieve().getTipo()==tipo)
            res.push_back(it.retrieve());
        else if(tipo!="" && distance!=0 && it.retrieve().getTipo()==tipo && it.retrieve().getDistance()<=distance)
            res.push_back(it.retrieve());
        it.advance();
    }
    return res;
}

/**
 * Gets all locations close to the airport according to the maximum distance chosen by the passenger
 * @param distance maximum distance desired
 * @return vector of transport locations
 */
vector<LocalTransporte> Aeroporto::getLocais(float distance) {
    vector<LocalTransporte> res;
    BSTItrIn<LocalTransporte> it(locais);
    while(!it.isAtEnd()){
        if(it.retrieve().getDistance()<=distance)
            res.push_back(it.retrieve());
        it.advance();
    }
    return res;
}

/**
 * If transport with the type and distance given exists, changes its availability and time.
 * Otherwise, creates a new location with the given data and adds it to the BST locais
 * @param tipo transport type
 * @param distance distance to the airport
 * @param horariosPartida departure times
 * @param availability the transport is working (true) or isn't (false)
 * @return
 */
bool Aeroporto::updateLocal(string tipo, float distance, vector<float> horariosPartida, bool availability) {
    BSTItrIn<LocalTransporte> it(locais);
    verifyTipo(tipo);
    while(!it.isAtEnd()){
        if(it.retrieve().getTipo()==tipo && it.retrieve().getDistance()==distance){
            locais.remove(it.retrieve());
            addLocal(LocalTransporte(tipo, distance, horariosPartida, availability));
            return true;
        }
        it.advance();
    }
    addLocal(LocalTransporte(tipo, distance, horariosPartida, availability));
    return false;
}

/**
 * From all the transports which distance is lower than the given one, returns the schedule of the first transport of the given type, if it exists.
 * If there's no transport from the given type at , at most, that distance, it puts in previous the closest one to the airport.
 * And in next the next transport of that type, if it exists, returning an empty vector
 * @param tipo transport type
 * @param distance maximum distance desired
 * @param previous object of the class LocalTransporte
 * @param next object of the class LocalTransporte
 * @return vector of departure times
 */
vector<float> Aeroporto::consultLocais(string tipo, float distance, LocalTransporte& previous, LocalTransporte& next) const {
    vector<float> res;
    BSTItrIn<LocalTransporte> it(locais);
    verifyTipo(tipo);
    if(it.retrieve().getDistance()<distance)
        previous = it.retrieve();
    else
        cout << "There is no transportation method at a maximum distance of " << distance <<" km"<< endl;

    if(getLocais(tipo).empty()){
        cout<<"There is no " << tipo;
        return res;
    }

    while(!it.isAtEnd()){
        if(it.retrieve().getDistance()<=distance && it.retrieve().getTipo()==tipo) {
            res=it.retrieve().getHorarios();
            break;
        }
        it.advance();
        if(distance<it.retrieve().getDistance() && it.retrieve().getTipo()==tipo){
            next=it.retrieve();
            cout<<"There is no "<<tipo<<" at a maximum distance of " << distance<<" km"<<endl;
            break;
        }
    }
    if(res.empty() && previous.getTipo()!="")
        cout << endl << "Closest transport: " << previous.getTipo() << " " << previous.getDistance()<<"km" << endl;
    if(res.empty() && next.getTipo()!="")
        cout << " closest "<< next.getTipo()<<": "<< next.getDistance() << "km" << endl;
    return res;
}

void Aeroporto::setPlane(int i,Aviao plane) {
    planes[i-1]=plane;
    for (int j=0;j<planes.size();j++){
        list<Voo> lv=planes[j].getPlano();
        queue<Service> s=planes[j].getServicesRealizar();
        queue<Service> s2=planes[j].getServicesRealizados();
        if (j==i-1){

        }
        else{
            while(lv.size()>plane.getPlano().size()){
                planes[j].addplanoDone(lv.front());
                lv.pop_front();
            }
        }
        while(s.size()>plane.getPlano().size()){
            s2.push(s.front());
            s.pop();
        }
        planes[j].setPlano(lv);
        planes[j].setServices(s,s2);
    }
}

void Aeroporto::servicePrinter() {
    vector<Service> done;
    vector<Service> undone;

    queue<Service> qs =planes[0].getServicesRealizar();
    queue<Service> qs2=planes[0].getServicesRealizados();
    while (qs.size()>0){
        undone.push_back(qs.front());
        qs.pop();
    }
    while (qs2.size()>0){
        done.push_back(qs2.front());
        qs2.pop();
    }

    cout<<"Services done: "<<endl<<endl;
    for(int i=0;i<done.size();i++){
        cout<<"      type: "<<done[i].getTypeENG()<<" Worker: "<<done[i].getFuncionario()<<" Date: "<<done[i].getData()<<endl<<endl;
    }
    cout<<"Services undone: "<<endl<<endl;
    for(int i=0;i<undone.size();i++){
        cout<<"      type: "<<undone[i].getTypeENG()<<" Worker: "<<undone[i].getFuncionario()<<" Date: "<<undone[i].getData()<<endl<<endl;
    }
}

void Aeroporto::DoneFlightsPrinter() {
    vector<Voo> temp;
    for (int i=0;i<planes.size();i++){
        for (int j=0;j<planes[i].getDoneFlights().size();j++){
            temp.push_back(planes[i].getDoneFlights()[j]);
        }
    }
    sort(temp.begin(),temp.end());
    for (int i=0;i<temp.size();i++){
        cout<<"     - Date: "<<temp[i].getPartida()<<" Origin: "<<temp[i].getOrigem()<<" Destination: "<<temp[i].getDestino()<<" Duration: "<<temp[i].getDuration()<<endl;
    }
}
