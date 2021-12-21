#include "LocalTransporte.h"
#include <stdexcept>
using namespace std;

/**
 * Creates a transport local with the given data.
 * It doesn't accept any other transports besides train, bus and subway
 * @param tipo metro/autocarro/comboio
 * @param distance distance between the airport and the transport local
 * @param horariosPartida departure times
 * @param availability the transport is working (true) or isn't (false)
 */
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

/**
 * Gets the transport type
 * @return transport type
 */
string LocalTransporte::getTipo() const {
    return this->tipo;
}

/**
 * Gets the distance between the transport local and the airport
 * @return distance
 */
float LocalTransporte::getDistance() const {
    return this->distance;
}

/**
 * Gets the departure times
 * @return departure times
 */
vector<float> LocalTransporte::getHorarios() const {
    return this->horariosPartida;
}

/**
 * Gets the transport availability
 * @return bool
 */
bool LocalTransporte::isAvailable() const {
    return this->availability;
}

/**
 * Updates the transport availability
 */
void LocalTransporte::changeAvailability() {
    if(availability)
        availability=false;
    else
        availability=true;
}

/**
 * Updates the departure time
 * @param horarios departures time
 */
void LocalTransporte::changeHorarios(vector<float> horarios) {
    this->horariosPartida=horarios;
}

/**
 * Compares two objects of the class LocalTransporte and sorts it by ascending order of the date
 * If it has the same date, sorts it by alphabetic order of the transport type
 * @param l1 object of the class LocalTransporte
 * @return bool
 */
bool LocalTransporte::operator<(const LocalTransporte &l1) const {
    if(distance==l1.getDistance()){
        return tipo<l1.getTipo();
    }
    return distance < l1.getDistance();
}

/**
 * Updates the distance between the airport and the transport local
 * @param distance distance between the airport and the transport local
 */
void LocalTransporte::setDistance(float distance) {
    this->distance=distance;
}
