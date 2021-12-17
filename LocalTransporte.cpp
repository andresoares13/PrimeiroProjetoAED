//
// Created by andre on 02-12-2021.
//

#include "LocalTransporte.h"

LocalTransporte::LocalTransporte(string tipo, float distance, vector<float> horariosPartida, bool availability) {
    this->tipo=tipo;
    this->distance=distance;
    this->horariosPartida=horariosPartida;
    this->availability=availability;
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
