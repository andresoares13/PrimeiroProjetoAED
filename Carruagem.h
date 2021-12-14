//
// Created by up202004161 on 03/12/2021.
//

#ifndef UNTITLED1_CARRUAGEM_H
#define UNTITLED1_CARRUAGEM_H
#include <stack>
#include <vector>
#include "Bagagem.h"

using namespace std;


class Carruagem {
public:
    Carruagem(int pilhas, int malas);
    bool isFull() const;
    vector<Bagagem> getBagagemS() const;    //retorna todas as malas da carruagem
    void popAllBags() const;      //retira todas as malas da carruagem

private:
    int malasPorStack; //número de malas por pilha
    int capacity; //número de pilhas da carruagem
    vector<stack<Bagagem>> carruagem;
};


#endif //UNTITLED1_CARRUAGEM_H
