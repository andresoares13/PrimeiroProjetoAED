//
// Created by andre on 02-12-2021.
//

#include "Passageiro.h"

bool Passageiro::isBagagem() const {
    return bagagem;
}

void Passageiro::setBagagem(bool bagagem) {
    Passageiro::bagagem = bagagem;
}

bool Passageiro::isCheckin() const {
    return checkin;
}

void Passageiro::setCheckin(bool checkin) {
    Passageiro::checkin = checkin;
}
