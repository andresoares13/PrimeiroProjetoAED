#ifndef UNTITLED1_LOCALTRANSPORTE_H
#define UNTITLED1_LOCALTRANSPORTE_H

#include <string>
#include <vector>

using namespace std;

class LocalTransporte {
public:
    LocalTransporte(string tipo, float distance, vector<float> horariosPartida, bool availability);
    string getTipo() const;
    float getDistance() const;
    void setDistance(float distance);
    vector<float> getHorarios() const;
    bool isAvailable() const;
    void changeAvailability();
    void changeHorarios(vector<float> horarios);
    bool operator<(const LocalTransporte &l1) const;
private:
    string tipo; //metro, comboio, autocarro
    float distance; //distância ao aeroporto de destino em km
    vector<float> horariosPartida;
    bool availability; //verifica se o transporte está em funcionamento ou não
};


#endif //UNTITLED1_LOCALTRANSPORTE_H
