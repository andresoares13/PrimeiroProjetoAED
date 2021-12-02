//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_PASSAGEIRO_H
#define UNTITLED1_PASSAGEIRO_H


class Passageiro {
public:
    Passageiro(bool bagagem);

    bool isBagagem() const;

    bool isCheckin() const;

    void setBagagem(bool bagagem);

    void setCheckin(bool checkin);

    bool Canbuy(int bilhetes); //receives the number of tickets to see if it's possible to buy them or not

    int MaybuyTickets(int bilhetes); //given the number of tickets the passenger wants to buy, return the amount possible


private:
    bool bagagem;
    bool checkin;
};


#endif //UNTITLED1_PASSAGEIRO_H
