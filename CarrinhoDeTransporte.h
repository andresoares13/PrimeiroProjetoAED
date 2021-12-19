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
    vector<Carruagem> getBagagem() const;
    bool ClearCar(); //retira todas as malas
    void AddBagagem(Bagagem bag); //adiciona toda a bagagem

private:
    int capacity; //número de carruagens do carrinho
    vector<Carruagem> carrinho;
};

#endif //UNTITLED1_CARRINHODETRANSPORTE_H
