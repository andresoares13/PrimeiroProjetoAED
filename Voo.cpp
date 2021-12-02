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

int Voo::getDuraçao() const {
    return duraçao;
}

const string &Voo::getOrigem() const {
    return origem;
}

const string &Voo::getDestino() const {
    return destino;
}

void Voo::setNumero(int numero) {
    Voo::numero = numero;
}

void Voo::setPartida(int partida) {
    Voo::partida = partida;
}

void Voo::setDuraçao(int duraçao) {
    Voo::duraçao = duraçao;
}

void Voo::setOrigem(const string &origem) {
    Voo::origem = origem;
}

void Voo::setDestino(const string &destino) {
    Voo::destino = destino;
}

int Voo::getLotaçao() const {
    return lotaçao;
}

void Voo::setLotaçao(int lotaçao) {
    Voo::lotaçao = lotaçao;
}
