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
    Voo(int numero, string partida, int duration, string origem, string destino);

    int getNumero() const;

    string getPartida() const;

    int getDuration() const;

    const string &getOrigem() const;

    const string &getDestino() const;

    int getCapacity() const;

    void setNumero(int numero);

    void setPartida(int partida);

    void setDuration(int duration);

    void setOrigem(const string &origem);

    void setDestino(const string &destino);

    void setCapacity(int capacity);


private:
    int numero;
    string partida;
    int duration;
    string origem;
    string destino;
    int capacity;
};


#endif //UNTITLED1_VOO_H
