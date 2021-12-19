#include "Service.h"

Service::Service(string tipo, string data, string funcionario) {
    this->data=data;
    this->funcionario=funcionario;
    if (tipo=="m"){
        this->tipo="manutenção";
    }
    if (tipo=="l"){
        this->tipo="limpeza";
    }

}

string Service::getData() const {
    return this->data;
}

bool Service::operator<(Service &servico) {
    if (data.substr(6,4)==servico.getData().substr(6,4)){
        if(data.substr(3,2)==servico.getData().substr(3,2)){
            if(data.substr(0,2)==servico.getData().substr(0,2)){
                return funcionario<servico.getFuncionario();
            }
            return data.substr(0,2)<servico.getData().substr(0,2);
        }
        return data.substr(3,2)<servico.getData().substr(3,2);
    }
    return data.substr(6,4)<servico.getData().substr(6,4);
}

string Service::getFuncionario() const {
    return this->funcionario;
}

string Service::getTypeENG() const {
    string s;
    if (tipo=="manutenção"){
        s="maintenance";
    }
    else{
        s="cleaning";
    }
    return s;
}
