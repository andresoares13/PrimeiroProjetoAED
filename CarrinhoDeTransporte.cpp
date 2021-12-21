#include <iostream>
#include "CarrinhoDeTransporte.h"

/**
 * Creates a transport cart with the given data
 * @param carruagens number of carriages
 * @param model cart model
 */
CarrinhoDeTransporte::CarrinhoDeTransporte(int carruagens, ModelCar model){
    this-> capacity = carruagens;
    for (int i=0;i<carruagens;i++){
        Carruagem c(model.getPilhas(),model.getMalas());
        carrinho.push_back(c);
    }
}

/**
 * Gets all
 * @return vector of carriages
 */
vector<Carruagem> CarrinhoDeTransporte::getBagagem() const {
   return carrinho;
}

/**
 * Adds the luggage to the cart using the member-function AddBag of the class Carruagem
 * @param bag
 */
void CarrinhoDeTransporte::AddBagagem(Bagagem bag){
    for (int i=0;i<carrinho.size();i++){
        if (carrinho[i].AddBag(bag)==false)
            continue;
        else
            break;
    }
}

/**
 * Removes all luggage from the cart using the member-function PopAllBags of the class Carruagem
 * @return bool
 */
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




