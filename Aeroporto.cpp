//
// Created by andre on 02-12-2021.
//

#include "Aeroporto.h"
#include "BinarySearchTree.h"
#include <iomanip>
#include <cmath>

Aeroporto::Aeroporto(): locais(LocalTransporte("", 0, {}, true)){

}

void Aeroporto::addLocal(const LocalTransporte &local) {
    locais.insert(local);
}

ostream& operator<<(ostream& os, const LocalTransporte& l1){
    if(!l1.isAvailable())
        return os;
    string horario;
    for(int i=0; i<l1.getHorarios().size(); i++){
        horario+= to_string(l1.getHorarios()[i]);
        horario+="    ";
    }
    os<<l1.getTipo()<<" a "<<l1.getDistance()<<" km "<<endl<<horario;
    return os;
}

void Aeroporto::printLocais() const {
    locais.printTree();
}

vector<LocalTransporte> Aeroporto::getLocais(string tipo, float distance) const {
    vector<LocalTransporte> res;
    BSTItrIn<LocalTransporte> it(locais);
    int option;
    if(tipo=="" && distance==0)
        option=1;
    else if(tipo!=""  && distance==0)
        option=2;
    else if(tipo=="" && distance!=0)
        option=3;
    else if(tipo!="" && distance!=0)
        option=4;
    while(!it.isAtEnd()){
        if(option==1)
            res.push_back(it.retrieve());
        else if(option==2 && it.retrieve().getTipo()==tipo)
            res.push_back(it.retrieve());
        else if(option==3 && it.retrieve().getDistance()<=distance)
            res.push_back(it.retrieve());
        else if(option==4 && it.retrieve().getTipo()==tipo && it.retrieve().getDistance()<=distance)
            res.push_back(it.retrieve());
        it.advance();
    }
    return res;
}

bool Aeroporto::updateLocal(float distance, string tipo, bool availability, vector<float> horariosPartida) {
    BSTItrIn<LocalTransporte> it(locais);
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
    previous=it.retrieve();
    while(!it.isAtEnd()){
        if(it.retrieve().getDistance()<=distance && it.retrieve().getTipo()==tipo)
            return it.retrieve().getHorarios();
        it.advance();
        if(distance<it.retrieve().getDistance() && it.retrieve().getTipo()==tipo){
            next=it.retrieve();
            return res;
        }
    }
}


