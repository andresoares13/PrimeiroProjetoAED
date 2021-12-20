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
    void setPlane(int i,Aviao plane);
    int getnumFLights();
    void addLocal(const LocalTransporte& local);
    void printLocais() const; //faz print de todos os locais próximos do aeroporto;
    vector<LocalTransporte> getLocais(string tipo="", float distance=0) const; //retorna todos os locais próximos ao aeroporto conforme o critério escolhido pelo passageiro
    vector<LocalTransporte> getLocais(float distance);
    bool updateLocal(string tipo, float distance, vector<float> horariosPartida, bool availability); //se o transporte daquele tipo àquela distância existir, altera a availability e horário
    vector<float> consultLocais(string tipo, float distance, LocalTransporte& previous, LocalTransporte& next) const;
    void servicePrinter();
    void DoneFlightsPrinter();
private:
    vector<Aviao> planes;
    BST<LocalTransporte> locais; //ordenados segundo a distância ao aeroporto
};


#endif //UNTITLED1_AEROPORTO_H

