#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H


#include "Aviao.h"
#include "BinarySearchTree.h"
#include "LocalTransporte.h"

using namespace std;

class LocalTransporte;

class Aeroporto {
public:
    Aeroporto();
    void addPlane(Aviao plane);
    vector<Aviao> GetPlanes();
    int getnumFLights();
    int getnumServices();
    void addLocal(const LocalTransporte& local);
    void printLocais() const; //faz print de todos os locais próximos do aeroporto;
    vector<LocalTransporte> getLocais(string tipo="", float distance=0) const; //retorna todos os locais próximos ao aeroporto conforme o critério escolhido pelo passageiro
    vector<LocalTransporte> getLocais(float distance);
    bool updateLocal(string tipo, float distance, vector<float> horariosPartida, bool availability); //se o transporte daquele tipo àquela distância existir, altera a availability e horário
    // se não existir um transporte daquele tipo àquela distância, adiciona-o
    vector<float> consultLocais(string tipo, float distance, LocalTransporte& previous, LocalTransporte& next) const;
    //Dos transportes que se encontram no máximo àquela distancia, retorna o horário do primeiro transporte do tipo dado caso exista
    //Caso não exista nenhum transporte desse tipo àquela distância, coloca em previous o transporte mais próximo do aeroporto
    //e coloca em next o próximo tansporte desse tipo se existir e retorna um vetor vazio
private:
    vector<Aviao> planes;
    BST<LocalTransporte> locais; //ordenados segundo a distância ao aeroporto
};


#endif //UNTITLED1_AEROPORTO_H

