//
// Created by andre on 02-12-2021.
//

#include "Passageiro.h"

bool Passageiro::isBagagem() const {
    return bagagem;
}

bool Passageiro::isCheckin() const {
    return checkin;
}

void Passageiro::setCheckin(bool checkin) { //por que é que isto está escrito desta maneira?
    Passageiro::checkin = checkin;
}

int Passageiro::getNumTickets() const { //Sofia
    return num_tickets;
}

void Passageiro::setNumTickets(int num) { //Sofia
    this-> num_tickets = num;
}
