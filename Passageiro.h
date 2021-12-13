//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_PASSAGEIRO_H
#define UNTITLED1_PASSAGEIRO_H


class Passageiro {
public:
    Passageiro(int ID, int num_tickets, bool bagagem);
    bool isBagagem() const;
    bool isCheckin() const;
    int getNumTickets() const;
    int getID() const;
    void setNumTickets(int num);
    void setCheckin(bool checkin);

private:
    int ID; //número de identificação do passageiro
    int num_tickets;
    bool bagagem;
    bool checkin;
};


#endif //UNTITLED1_PASSAGEIRO_H
