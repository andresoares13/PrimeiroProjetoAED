//
// Created by andre on 02-12-2021.
//

#include "CarrinhoDeTransporte.h"


CarrinhoDeTransporte::CarrinhoDeTransporte(int carruagens, int pilhas, int malas){
    for (int i=0;i<carruagens;i++){
        Carruagem c(pilhas);
        carrinho.push_back(c);
    }
}

void CarrinhoDeTransporte::SetStacks(int n) {
    for (int i=0;i<carrinho.size();i++){
        carrinho[i].setN(n);
    }
}