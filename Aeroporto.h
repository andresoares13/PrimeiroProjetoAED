//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H


#include "Aviao.h"
#include "BinarySearchTree.h" //acrescentado
#include "LocalTransporte.h" //acrescentado

using namespace std; //acrescentado

class LocalTransporte;

class Aeroporto {
public:
    Aeroporto();
    vector<Aviao> getPlanes() const;

    //Bárbara
    void addLocal(const LocalTransporte& local);
    void printLocais() const; //faz print de todos os locais próximos do aeroporto;
    vector<LocalTransporte> getLocais(string tipo="", float distance=0) const; //retorna todos os locais próximos ao aeroporto conforme o critério escolhido pelo passageiro
    bool updateLocal(float distance, string tipo, bool availability, vector<float> horariosPartida); //se o transporte daquele tipo àquela distância existir, altera a availability e horário
                                                                                 // se não existir um transporte daquele tipo àquela distância, adiciona-o
    LocalTransporte consultLocais(string tipo, float distance, LocalTransporte& next) const;
    //Dos transportes que se encontram no máximo àquela distancia, retorna o horário do primeiro transporte do tipo dado caso exista
    //Caso não exista nenhum transporte desse tipo, coloca em next um transporte de outro tipo que se encontra à distância mínima


private:
    vector<Aviao> planes;
    //Bárbara
    BST<LocalTransporte> locais; //ordenados segundo a distância ao aeroporto
};


#endif //UNTITLED1_AEROPORTO_H

