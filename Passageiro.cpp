//
// Created by andre on 02-12-2021.
//

#include <cstdlib>
#include <ctime>
#include "Passageiro.h"

Passageiro::Passageiro(int ID, int num_tickets, bool bagagem, bool checkin) {
    srand (time(NULL));
    this->ID=ID;
    this->num_tickets=num_tickets;
    this->bagagem=bagagem;
    this->checkin=checkin;
    if (bagagem==true){
        Bagagem mala(ID,rand() % 80 + 10);
        bag.push_back(mala);
    }

}

bool Passageiro::isBagagem() const {
    return bagagem;
}

bool Passageiro::isCheckin() const {
    return checkin;
}

int Passageiro::getID() const {
    return this->ID;
}

void Passageiro::setCheckin(bool checkin) {
    Passageiro::checkin = checkin;
}

int Passageiro::getNumTickets() const {
    return num_tickets;
}

void Passageiro::setNumTickets(int num) {
    this-> num_tickets = num;
}

Bagagem Passageiro::GetBag() const {
    return bag[0];
}




