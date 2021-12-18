#ifndef UNTITLED1_APP_H
#define UNTITLED1_APP_H

#include "Aeroporto.h"
#include <stdexcept>

class App {
public:
    App(Aeroporto aeroporto);
    int run();
private:
    Aeroporto aeroporto;
};

#endif //UNTITLED1_APP_H
