//
// Created by up202004161 on 03/12/2021.
//

#include "Carruagem.h"

Carruagem::Carruagem(int pilhas, int malas) {
    malasPorStack=malas;
    for (int i=0;i<pilhas;i++){
        stack<Bagagem> b;
        carruagem.push_back(b);
    }
    capacity=pilhas;
}

bool Carruagem::isFull() const {
    if(carruagem.size()<capacity)
        return false;
    for (auto pilha: carruagem)
        if(pilha.size()<malasPorStack)
            return false;
    return true;
}


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

void Carruagem::popAllBags() const {

}
