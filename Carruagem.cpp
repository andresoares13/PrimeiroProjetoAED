#include <iostream>
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


bool Carruagem::AddBag(Bagagem bag){
    for (int i=0;i<carruagem.size();i++){
        if (carruagem[i].size()<malasPorStack){
            carruagem[i].push(bag);
            return true;
        }
    }
    return false;
}

void Carruagem::PopAllBags() {
    for(int i=0;i<carruagem.size();i++){
        while(carruagem[i].size()>0){
            carruagem[i].pop();
        }
    }
}



bool Carruagem::isClear() const {
    bool p=true;
    for (int i=0;i<carruagem[i].size();i++){
        if(carruagem[i].size()!=0){
            p=false;
        }
    }
    return p;
}


string Carruagem::get() {
    for (int i=0;i<carruagem.size();i++){
        cout<<carruagem[i].size()<<endl;
    }
    return "";
}




