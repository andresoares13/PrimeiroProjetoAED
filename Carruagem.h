//
// Created by up202004161 on 03/12/2021.
//

#ifndef UNTITLED1_CARRUAGEM_H
#define UNTITLED1_CARRUAGEM_H
#include <stack>
#include <vector>
using namespace std;


class Carruagem {
public:
    Carruagem(int pilhas);
    void setN(int n);

private:
    int n;
    vector<stack<int>> chariot;

};


#endif //UNTITLED1_CARRUAGEM_H
