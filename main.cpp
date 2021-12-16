#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Service.h"
#include "Passageiro.h"
#include "Voo.h"
#include "CarrinhoDeTransporte.h"
#include "Aeroporto.h"

using namespace std;
int main() {
    Aeroporto A;

    vector<float> v1={9.10, 9.45, 9.50};
    vector<float> v2={10.20, 11.40};
    vector<float> v3={13.45};
    LocalTransporte l1("metro", 1.2, v1, true);
    LocalTransporte l2("comboio", 0.8, v2, true);
    LocalTransporte l3("autocarro", 1.0, v3, false);
    A.addLocal(l1);
    A.addLocal(l2);
    A.addLocal(l3);
    A.printLocais();
    vector<LocalTransporte> r1=A.getLocais();
    vector<LocalTransporte> r2=A.getLocais("metro");

/*
    Voo v(1,"p",2,"o","o",500,20);
    Passageiro p(1,1,true,true);
    Passageiro p1(1,1,true,false);
    Passageiro p2(1,1,true,false);
    v.AddToBuy(p);
    v.AddToBuy(p1);
    v.AddToBuy(p2);
    v.BuyTickets();
    v.addPassageiro(p);
    v.addPassageiro(p1);
    v.addPassageiro(p2);
    CarrinhoDeTransporte car=v.AutoBag();
    cout<<car.getBagagem().size()<<endl;
    for (int i=0;i<car.getBagagem().size();i++){
        car.getBagagem()[i].get();
    }
     */



    return 0;

}
