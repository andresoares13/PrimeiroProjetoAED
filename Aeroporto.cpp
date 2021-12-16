//
// Created by andre on 02-12-2021.
//

#include "Aeroporto.h"
#include "BinarySearchTree.h"

Aeroporto::Aeroporto(): locais(LocalTransporte("", 0, {}, true)){

}

void Aeroporto::addLocal(const LocalTransporte &local) {
    locais.insert(local);
}

ostream& operator<<(ostream& os, const LocalTransporte& l1){
    if(!l1.isAvailable())
        return os;
    string horario;
    for(int i=0; i<l1.getHorarios().size(); i++){
        horario+= to_string(l1.getHorarios()[i]);
        horario+="    ";
    }
    os<<l1.getTipo()<<" a "<<l1.getDistance()<<" km "<<endl<<horario<<endl;
    return os;
}

void Aeroporto::printLocais() const {
    locais.printTree();
}


