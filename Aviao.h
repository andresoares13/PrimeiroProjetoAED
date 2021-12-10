//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_AVIAO_H
#define UNTITLED1_AVIAO_H
#include <string>
#include <vector>
#include "Voo.h"
#include "Service.h"
#include <queue>

using namespace std;


class Aviao {
public:
    Aviao(string matricula, int capacidade, vector<Voo> plano, queue<Service> services);

    const string &getMatricula() const;

    int getCapacidade() const;

    const vector<Voo> &getPlano() const;

    const queue<Service> &getServices() const;

    void setMatricula(const string &matricula);

    void setCapacidade(int capacidade);

    void addVoo(const Voo);

    void addServices(const Service);

    void setCapacity();


private:
    string matricula;
    int capacidade;
    vector<Voo> plano;
    queue<Service> services;
};


#endif //UNTITLED1_AVIAO_H
