#ifndef UNTITLED1_MODELCAR_H
#define UNTITLED1_MODELCAR_H

#include <string>

using namespace std;
class ModelCar {
public:
    ModelCar(string type);

    const string &getType() const;

    int getPilhas() const;

    int getMalas() const;

private:
    string type;
    int pilhas;
    int malas;
};


#endif //UNTITLED1_MODELCAR_H
