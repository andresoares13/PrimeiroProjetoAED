#ifndef UNTITLED1_AIRPORTMAKER_H
#define UNTITLED1_AIRPORTMAKER_H

#include <fstream>
#include "Aeroporto.h"
#include <stdexcept>
#include <sstream>

class AirportMaker {
public:
    AirportMaker();
    void FillAirport();
    vector<Aviao> PlaneMaker();
    list<Voo> VoosMaker(int capacidade, int BagLimit);
    vector<Voo> DoneVooMaker();
    queue<Service> ServicesMaker();
    queue<Service> DoneServiceMaker();
    vector<LocalTransporte> LocaisAdder();
    vector<float> GetHorarios(string tipo);
    Aeroporto GetAeroporto();

private:
    Aeroporto airport;
};

#endif //UNTITLED1_AIRPORTMAKER_H
