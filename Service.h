//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H
#include <string>
#include <vector>
using namespace std;

class Service {
public:
    Service(string tipo, string data, string funcionario);

    const string &getTipo() const;

    const string &getData() const;

    const string &getFuncionario() const;

    void setTipo(const string &tipo);

    void setData(const string &data);

    void setFuncionario(const string &funcionario);

private:
    string tipo;
    string data;
    string funcionario;
};


#endif //UNTITLED1_SERVICE_H
