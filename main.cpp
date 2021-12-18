#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Service.h"
#include "Passageiro.h"
#include "Voo.h"
#include "CarrinhoDeTransporte.h"
#include "Aeroporto.h"
#include "AirportMaker.h"
#include "App.h"


using namespace std;
int main() {
    AirportMaker createPort;
    createPort.FillAirport();
    Aeroporto aeroporto=createPort.GetAeroporto();
    App app(aeroporto);
    return(app.run());












    //cout<<aeroporto.GetPlanes()[0].getPlano().begin()->getDestino()<<endl;
    //cout<<aeroporto.GetPlanes()[0].getServicesRealizar().front().getData();
   // aeroporto.printLocais();
   //list<Voo> ::iterator it=aeroporto.GetPlanes()[i].getPlano().begin();
    //                    while(it!=aeroporto.GetPlanes()[i].getPlano().end()){
    //                        cout<<"     - Date: "<<(*it).getPartida()<<" Origin: "<<(*it).getOrigem()<<" Destination: "<<(*it).getDestino()<<" Duration: "<<(*it).getDuration()<<endl;
    //                        it++;
    //                    }

}