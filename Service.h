//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H
#include <string>
#include <vector>
using namespace std;

using namespace std;

class Service {
public:
    Service(string tipo, string data, string funcionario);
    string getTipo() const; //porquê o const atrás
    string getData() const;
    string getFuncionario() const;
    string setFuncionario() const;
    bool changeData(string date);  //muda a data do serviço para date se essa data for antes do próximo voo
    bool operator < (Service &servico);

private:
    string tipo; //manutenção/limpeza
    string data;
    string funcionario;
};


#endif //UNTITLED1_SERVICE_H
