//
// Created by andre on 02-12-2021.
//

#include "Voo.h"


int Voo::getNumero() const {
    return numero;
}

string Voo::getPartida() const {
    return partida;
}

int Voo::getDuration() const {
    return duration;
}

string Voo::getOrigem() const {
    return origem;
}

string Voo::getDestino() const {
    return destino;
}

int Voo::getCapacity() const {
    return capacity;
}

int Voo::getProfit() const {
    int profit;
    int bilhetesvendidos = capacity - ticketsAvailable();

    profit = bilhetesvendidos * getTicketPrice();

    return profit;
}

int Voo::getTicketPrice() const {
    return ticketprice;
}

int Voo::ticketsAvailable() const {
    return capacity - passageiros.size();
}

list<Passageiro> Voo::getPassageiros() const {
    return list<Passageiro>();
}

bool Voo::addPassageiro(Passageiro &p) {

    if(ticketsAvailable() == 0)//verificar se está cheio
    {
        return false;
    }
    else
    {
        passageiros.push_back(p);
        return true;
    }
}

bool Voo::removePassageiro(int ID) {


    for(int i = 0; i < passageiros.size(); i++)
    {
        if(passageiros[i].getID() == ID)
        {
            passageiros.erase(passageiros.begin() + i);
            return true;
        }
    }

    return false; //se o passageiro não estiver
}

Passageiro &Voo::findPassageiro(int ID) {
    for(int i = 0; i < passageiros.size(); i++)
    {
        if(passageiros[i].getID() == ID)
        {
            //return ;
        }
    }
}
