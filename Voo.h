//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_VOO_H
#define UNTITLED1_VOO_H
#include <string>
#include <vector>
using namespace std;

class Voo {
public:
    Voo(int numero, string partida, int duraçao, string origem, string destino);

    int getNumero() const;

    string getPartida() const;

    int getDuraçao() const;

    const string &getOrigem() const;

    const string &getDestino() const;

    int getLotaçao() const;

    void setNumero(int numero);

    void setPartida(int partida);

    void setDuraçao(int duraçao);

    void setOrigem(const string &origem);

    void setDestino(const string &destino);

    void setLotaçao(int lotaçao);


private:
    int numero;
    string partida;
    int duraçao;
    string origem;
    string destino;
    int lotaçao;
};


#endif //UNTITLED1_VOO_H
