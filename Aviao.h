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
    void AddToSort(const Service s); //adiciona um serviço
    void SortAndPush(); //ordena os servços por data (ais antigo primeiro) e coloca-os na queue
    bool isService(); //ve o primeiro serviço da fila e se for no mesmo dia do primeiro elemento da lista de voos "faz o serviço" e coloca-os nos serviços realizados (correr antes de cada voo)
    bool Fly(string data, string origem, string destino, bool checkin ); //realiza o voo do seu plano com estas caracteristicas
    vector<Voo> getPlanoVector();
    void setPlano(list<Voo> lv);
    void setServices(queue<Service> sv, queue<Service> sv2);
    void setVoo(Voo v);
    bool printVoo(string destination);

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
