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
    Aviao(string matricula, int capacidade, vector<Voo> plano, queue<Service> serviços);

    const string &getMatricula() const;

    int getCapacidade() const;

    const vector<Voo> &getPlano() const;

    const queue<Service> &getServiços() const;

    void setMatricula(const string &matricula);

    void setCapacidade(int capacidade);

    void addVoo(const Voo);

    void addServiços(const Service);

    void setLotaçao();


private:
    string matricula;
    int capacidade;
    vector<Voo> plano;
    queue<Service> serviços;
};


#endif //UNTITLED1_AVIAO_H
