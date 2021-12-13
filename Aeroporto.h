//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H


#include "Aviao.h"

class Aeroporto {
public:
    vector<Aviao> getPlanes() const;

private:
    vector<Aviao> planes;
};


#endif //UNTITLED1_AEROPORTO_H
