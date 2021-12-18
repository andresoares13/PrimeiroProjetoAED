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
/*
    Aeroporto A;

    vector<float> v1={9.10, 9.45, 9.50};
    vector<float> v2={10.20, 11.40};
    vector<float> v3={13.45};
    LocalTransporte l1("metro", 1.2, v1, true);
    LocalTransporte l2("comboio", 0.8, v2, true);
    LocalTransporte l3("autocarro", 1.0, v3, true);
    LocalTransporte l4("metro", 2.2, v2, true);
    LocalTransporte l5("autocarro", 0.5, v1, true);
    LocalTransporte l6("metro", 2, v3, true);

    A.addLocal(l1);
    A.addLocal(l2);
    A.addLocal(l3);
    A.addLocal(l4);
    A.addLocal(l5);
    A.addLocal(l6);

//    A.printLocais();

//    LocalTransporte previous("", 0, {}, true), next("",0,{},true);
//    vector<float> res=A.consultLocais("metro", 2.0, previous, next);
//    if(!res.empty()) {
//        cout << "Horario: ";
//        for (auto value: res)
//            cout << value << "    ";
//    }

//    vector<LocalTransporte> r1=A.getLocais();
//    for(auto local:r1)
//        cout<<local.getTipo()<<" a "<<local.getDistance() << "km"<<endl;
//    cout<<endl;

//    vector<LocalTransporte> r2=A.getLocais("comboio");
//    for(auto local:r2)
//        cout<<local.getTipo()<<" a "<<local.getDistance() << "km"<<endl;
//    cout<<endl;

//    vector<LocalTransporte> r3=A.getLocais("metro", 2.0);
//    for(auto local:r3)
//        cout<<local.getTipo()<<" a "<<local.getDistance() << "km"<<endl;
//    cout<<endl;

//    vector<LocalTransporte> r4=A.getLocais(2.0);
//    for(auto local:r4)
//        cout<<local.getTipo()<<" a "<<local.getDistance() << "km"<<endl;

    vector<float> v4={15.0, 15.30, 15.45, 16.10};
    vector<float> v5={12.20, 13.25, 14.35};
    cout<<A.updateLocal("metro", 1.2, v4, true)<<endl;
    cout<<A.updateLocal("comboio", 1.4, v5, true)<<endl;
    cout<<A.updateLocal("autocarro", 2, v5, true)<<endl;
    vector<LocalTransporte> r5=A.getLocais();
    for(auto local:r5)
        cout<<local.getTipo()<<" a "<<local.getDistance() << "km"<<endl;
*/
    return 0;
}
