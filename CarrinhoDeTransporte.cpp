//
// Created by andre on 02-12-2021.
//

#include <iostream>
#include "CarrinhoDeTransporte.h"


CarrinhoDeTransporte::CarrinhoDeTransporte(int carruagens, ModelCar model){
    this-> capacity = carruagens;
    for (int i=0;i<carruagens;i++){
        Carruagem c(model.getPilhas(),model.getMalas());
        carrinho.push_back(c);
    }
}

vector<Bagagem> CarrinhoDeTransporte::getBagagem() const {
    vector<Bagagem> temp;
    for(auto carruagem:carrinho)
        temp.insert(temp.end(), carruagem.getBagagemS().begin(), carruagem.getBagagemS().end());
    return temp;
}

void CarrinhoDeTransporte::AddBagagem(Bagagem bag){
    for (int i=0;i<carrinho.size();i++){
        if (carrinho[i].AddBag(bag)==false){
            continue;
        }
        else{
            break;
        }
    }
}

bool CarrinhoDeTransporte::ClearCar() {
    bool pop=false;
    for(int i=0;i<carrinho.size();i++){
        carrinho[i].PopAllBags();
    }
    for(int i=0;i<carrinho.size();i++){
        pop=carrinho[i].isClear();
    }
    if (pop){
        cout<<"The transportation car is totally clear"<<endl;
        return true;
    }
    else{
        cout<<"The transportation car is not totally clear"<<endl;
        return false;
    }



}




