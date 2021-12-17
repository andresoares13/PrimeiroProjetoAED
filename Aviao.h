//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_AVIAO_H
#define UNTITLED1_AVIAO_H
#include <string>
#include <vector>
#include "Voo.h"
#include "Service.h"
#include "Passageiro.h"
#include <queue>

using namespace std;


class Aviao {
public:
    Aviao(string matricula, string tipo, list<Voo> plano, queue<Service> servicesRealizar);
    string getMatricula() const;
    string getTipo() const;
    int getCapacidade() const;
    int getLimitPerBag() const;
    list<Voo> getPlano() const;
    queue<Service> getServicesRealizados() const;
    queue<Service> getServicesRealizar() const;
    bool isBroken() const;
    void setBroken() ;
    void addVoo(const Voo& voo);
    void AddToSort(const Service s);
    void SortAndPush();
    bool removeFuncionario(const string funcinario); //remove o funcionário e divide os serviços a realizar pelos restantes funcionários e apaga os serviços realizados
    void removeService(const string tipo, const string data);
    list<Voo> findVooOrigem(string origem);
    list<Voo> findVooDestino(string destino);
    list<Voo> findVooPartida(string partida);
    list<Passageiro> removeVoo(Voo &voo);



private:
    string matricula;
    string tipo;
    int capacity;
    int LimitPerBag; //weight limit in kg
    list<Voo> plano; //mudar para list
    queue<Service> servicesRealizados; //distinguir os serviços realizados dos a realizar
    queue<Service> servicesRealizar;
    bool state; //queremos que seja uma string?
    vector<Service> ServiceSorter;
};


#endif //UNTITLED1_AVIAO_H
