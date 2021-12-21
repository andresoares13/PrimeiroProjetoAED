#include "Service.h"

/**
 * Creates a service with the data given
 * @param tipo service type
 * @param data service date
 * @param funcionario employee name
 */
Service::Service(string tipo, string data, string funcionario) {
    this->data=data;
    this->funcionario=funcionario;
    if (tipo=="m")
        this->tipo="manutenção";
    if (tipo=="l")
        this->tipo="limpeza";
}

/**
 * Gets the service date
 * @return service date
 */
string Service::getData() const {
    return this->data;
}

/**
 * Compares two services and sorts it by date.
 * If it has the same date, sorts it by alphabetic order of the employee name
 * @param servico service
 * @return bool
 */
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

/**
 * Gets the employee name
 * @return employee name
 */
string Service::getFuncionario() const {
    return this->funcionario;
}

/**
 * Gets the service type in english
 * @return service type in english
 */
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
