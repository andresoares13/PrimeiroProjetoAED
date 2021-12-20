#include "Aeroporto.h"
#include "BinarySearchTree.h"
#include <iomanip>
#include <cmath>
#include <algorithm>

Aeroporto::Aeroporto(): locais(LocalTransporte("", 0, {}, true)){}

void Aeroporto::addPlane(Aviao plane) {
    planes.push_back(plane);
}

vector<Aviao> Aeroporto::GetPlanes() {
    return planes;
}

int Aeroporto::getnumFLights() {
    int counter=0;
    for (int i=0;i<planes.size();i++){
        counter+=planes[i].getPlano().size();
    }
    return counter;
}

int Aeroporto::getnumServices() {
    int counter=0;
    for (int i=0;i<planes.size();i++){
        counter+=planes[i].getServicesRealizar().size();
    }
    return counter;
}

void Aeroporto::addLocal(const LocalTransporte &local) {
    locais.insert(local);
}

void verifyTipo(string tipo) {
    if(tipo!="metro" && tipo!="autocarro" && tipo!="comboio" && tipo!="")
        throw invalid_argument("Invalid transport");
}

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

void Aeroporto::printLocais() const {
    locais.printTree();
}

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

vector<float> Aeroporto::consultLocais(string tipo, float distance, LocalTransporte& previous, LocalTransporte& next) const {
    vector<float> res;
    BSTItrIn<LocalTransporte> it(locais);
    verifyTipo(tipo);
    //VERIFICA SE EXISTE ALGUM TRANSPORTE DENTRO DISTÂNCIA DADA
    if(it.retrieve().getDistance()<distance)
        previous = it.retrieve();
    else
        cout << "There is no transportation method at a maximum distance of " << distance <<" km"<< endl;

    //VERIFICA SE EXISTE ALGUM TRANSPORTE DO TIPO DADO
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
    for (int i=0;i<planes.size();i++){
        queue<Service> qs =planes[i].getServicesRealizar();
        queue<Service> qs2=planes[i].getServicesRealizados();
        while (qs.size()>0){
            undone.push_back(qs.front());
            qs.pop();
        }
        while (qs2.size()>0){
            done.push_back(qs2.front());
            qs2.pop();
        }

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
