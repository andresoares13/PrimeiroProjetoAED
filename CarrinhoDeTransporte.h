//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_CARRINHODETRANSPORTE_H
#define UNTITLED1_CARRINHODETRANSPORTE_H


#include "cmake-build-debug/Carruagem.h"
#include <vector>
using namespace std;

class CarrinhoDeTransporte {
public:
    CarrinhoDeTransporte(int carruagens, int pilhas, int malas);
    void SetStacks(int n);
    bool IsFull(Carruagem);

private:
    int c;
    vector<Carruagem> carrinho;
};




#endif //UNTITLED1_CARRINHODETRANSPORTE_H
