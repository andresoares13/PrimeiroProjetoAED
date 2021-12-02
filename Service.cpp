//
// Created by andre on 02-12-2021.
//

#include "Service.h"

const string &Service::getTipo() const {
    return tipo;
}

const string &Service::getData() const {
    return data;
}

const string &Service::getFuncionario() const {
    return funcionario;
}

void Service::setTipo(const string &tipo) {
    Service::tipo = tipo;
}

void Service::setData(const string &data) {
    Service::data = data;
}

void Service::setFuncionario(const string &funcionario) {
    Service::funcionario = funcionario;
}
