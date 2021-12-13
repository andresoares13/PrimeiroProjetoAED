//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_VOO_H
#define UNTITLED1_VOO_H
#include <string>
#include <vector>
#include "Passageiro.h"
#include <list>

using namespace std;

class Voo {
public:
    Voo(int numero, string partida, int duration, string origem, string destino);
    int getNumero() const;
    string getPartida() const;
    int getDuration() const;
    string getOrigem() const;
    string getDestino() const;
    int getCapacity() const;
    int getProfit() const;   //dinheiro que vais ser feito com o voo
    int getTicketPrice() const;
    int ticketsAvailable() const;
    list<Passageiro> getPassageiros() const;
    bool addPassageiro(Passageiro &p); //adiciona passageiro se o nº de bilhetes que quer comprar for inferior ou igual aos lugares disponíveis
    bool removePassageiro(int ID); //caso o passageiro com esse ID exista, remove-o
    Passageiro& findPassageiro(int ID);

private:
    int numero;
    string partida; //data de partida
    int duration;
    string origem;
    string destino;
    int ticketprice;
    int capacity;
    vector<Passageiro> passageiros;
};


#endif //UNTITLED1_VOO_H
