//
// Created by andre on 02-12-2021.
//

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






