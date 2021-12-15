//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_CARRINHODETRANSPORTE_H
#define UNTITLED1_CARRINHODETRANSPORTE_H


#include "Carruagem.h"
#include "Bagagem.h"
#include "ModelCar.h"
#include <vector>
using namespace std;

class CarrinhoDeTransporte {
public:
    CarrinhoDeTransporte(int carruagens, ModelCar model); //retirou-se pilhas e malas
    vector<Bagagem> getBagagem() const; //retorna num vetor todas as malas que estão no carrinho
    bool ClearCar(); //retira todas as malas
    bool pushBag(const Bagagem& mala); //adiciona uma mala ao carrinho
    bool isFull() const; //verifica se o carrinho já está cheio
    void AddBagagem(Bagagem bag); //adiciona toda a bagagem


private:
    int capacity; //número de carruagens do carrinho
    vector<Carruagem> carrinho;
};




#endif //UNTITLED1_CARRINHODETRANSPORTE_H
