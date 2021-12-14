//
// Created by andre on 02-12-2021.
//

#include "Passageiro.h"

Passageiro::Passageiro(int ID, int num_tickets, bool bagagem) {
    this->ID=ID;
    this->num_tickets=num_tickets;
    this->bagagem=bagagem;
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


