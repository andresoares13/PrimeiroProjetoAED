//
// Created by up202004161 on 03/12/2021.
//

#include "Carruagem.h"

Carruagem::Carruagem(int pilhas) {
    int counter=1;
    for (int i=0;i<pilhas;i++){
        stack<int> p;
        p.push(counter);
        chariot.push_back(p);
    }
}

void Carruagem::setN(int n) {
    Carruagem::n = n;
}
