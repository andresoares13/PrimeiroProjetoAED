//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_CARRINHODETRANSPORTE_H
#define UNTITLED1_CARRINHODETRANSPORTE_H


#include "Carruagem.h"
#include "Bagagem.h"
#include <vector>
using namespace std;

class CarrinhoDeTransporte {
public:
    CarrinhoDeTransporte(int carruagens); //retirou-se pilhas e malas
    vector<Bagagem> getBagagem() const; //retorna num vetor todas as malas que estão no carrinho   <------------
    void popBag(); //retira uma mala do carrinho
    bool pushBag(const Bagagem& mala); //adiciona uma mala ao carrinho
    bool isFull() const; //verifica se o carrinho já está cheio

private:
    int capacity; //número de carruagens do carrinho
    vector<Carruagem> carrinho;
};




#endif //UNTITLED1_CARRINHODETRANSPORTE_H
