#include <iostream>
#include "Carruagem.h"

/**
 * Creates a carriage with the given data.
 * The capacity of a carriage is given by the parameter pilhas.
 * @param pilhas amount of stacks by carriage
 * @param malas amount of bags by stack
 */
Carruagem::Carruagem(int pilhas, int malas) {
    malasPorStack=malas;
    for (int i=0;i<pilhas;i++){
        stack<Bagagem> b;
        carruagem.push_back(b);
    }
    capacity=pilhas;
}

/**
 * Checks if the carriage is full
 * @return bool
 */
bool Carruagem::isFull() const {
    if(carruagem.size()<capacity)
        return false;
    for (auto pilha: carruagem)
        if(pilha.size()<malasPorStack)
            return false;
    return true;
}

/**
 * Gets out all the luggage of the carriage
 * @return vector of luggage
 */
vector<Bagagem> Carruagem::getBagagemS() const {
    vector<Bagagem> res;
    vector<stack<Bagagem>> temp=carruagem;
    for(auto pilha:temp)
        while(!pilha.empty()) {
            res.push_back(pilha.top());
            pilha.pop();
        }
    return res;
}

/**
 * Adds the luggage to the carriage if it isn't full and returns true.
 * If it's full returns false
 * @param bag luggage
 * @return bool
 */
bool Carruagem::AddBag(Bagagem bag){
    for (int i=0;i<carruagem.size();i++){
        if (carruagem[i].size()<malasPorStack){
            carruagem[i].push(bag);
            return true;
        }
    }
    return false;
}

/**
 * Removes all luggage from the carriage
 */
void Carruagem::PopAllBags() {
    for(int i=0;i<carruagem.size();i++)
        while(carruagem[i].size()>0)
            carruagem[i].pop();
}

/**
 * Checks if the carriage is empty.
 * If is empty returns true, otherwise returns false
 * @return bool
 */
bool Carruagem::isClear() const {
    bool p=true;
    for (int i=0;i<carruagem[i].size();i++)
        if(carruagem[i].size()!=0)
            p=false;
    return p;
}


/**
 * Gets the maximum capacity of the carriage
 * @return capacity
 */
int Carruagem::getCapacity() const {
    return capacity;
}




