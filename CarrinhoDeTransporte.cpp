//
// Created by andre on 02-12-2021.
//

#include "CarrinhoDeTransporte.h"


CarrinhoDeTransporte::CarrinhoDeTransporte(int carruagens){
    this-> capacity = carruagens;
}

vector<Bagagem> CarrinhoDeTransporte::getBagagem() const {
    vector<Bagagem> temp;
    for(auto carruagem:carrinho)
        temp.insert(temp.end(), carruagem.getBagagemS().begin(), carruagem.getBagagemS().end());
    return temp;
}




