//
// Created by andre on 13-12-2021.
//

#ifndef UNTITLED1_BAGAGEM_H
#define UNTITLED1_BAGAGEM_H


class Bagagem {
public:
    Bagagem(int ID, int peso);
    int getID() const;
    int getPeso() const;

    void setPeso(int peso);

private:
    int ID;
    int peso;
};


#endif //UNTITLED1_BAGAGEM_H
