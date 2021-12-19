#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H
#include <string>
#include <vector>
using namespace std;

using namespace std;

class Service {
public:
    Service(string tipo, string data, string funcionario);
    string getData() const;
    string getFuncionario() const;
    bool operator < (Service &servico);
    string getTypeENG() const;

private:
    string tipo; //manutenção/limpeza
    string data;
    string funcionario;
};


#endif //UNTITLED1_SERVICE_H
