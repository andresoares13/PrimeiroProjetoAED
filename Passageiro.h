//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_PASSAGEIRO_H
#define UNTITLED1_PASSAGEIRO_H


#include "Bagagem.h"
#include <vector>
using namespace std;

class Passageiro {
public:
    Passageiro(int ID, int num_tickets, bool bagagem, bool checkin);
    bool isBagagem() const;
    bool isCheckin() const;
    int getNumTickets() const;
    int getID() const;
    void setNumTickets(int num);
    void setCheckin(bool checkin);
    Bagagem GetBag() const;


private:
    int ID; //número de identificação do passageiro
    int num_tickets;
    bool bagagem;
    bool checkin;
    vector<Bagagem> bag; //mala unica, pode ter ou nao
};


#endif //UNTITLED1_PASSAGEIRO_H
