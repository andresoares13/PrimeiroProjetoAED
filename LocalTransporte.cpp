#include "LocalTransporte.h"
#include <stdexcept>
#include <iostream>
using namespace std;

LocalTransporte::LocalTransporte(string tipo, float distance, vector<float> horariosPartida, bool availability) {
    if(tipo=="metro" || tipo=="autocarro" || tipo=="comboio") {
        this->tipo = tipo;
        this->distance = distance;
        this->horariosPartida = horariosPartida;
        this->availability = availability;
    }
    else if(tipo!="")
        throw invalid_argument("Transport invalid");
}

string LocalTransporte::getTipo() const {
    return this->tipo;
}

float LocalTransporte::getDistance() const {
    return this->distance;
}

vector<float> LocalTransporte::getHorarios() const {
    return this->horariosPartida;
}

bool LocalTransporte::isAvailable() const {
    return this->availability;
}

void LocalTransporte::changeAvailability() {
    if(availability)
        availability=false;
    else
        availability=true;
}

void LocalTransporte::changeHorarios(vector<float> horarios) {
    this->horariosPartida=horarios;
}

bool LocalTransporte::operator<(const LocalTransporte &l1) const {
    if(distance==l1.getDistance()){
        return tipo<l1.getTipo();
    }
    return distance < l1.getDistance();
}

void LocalTransporte::setDistance(float distance) {
    this->distance=distance;
}
