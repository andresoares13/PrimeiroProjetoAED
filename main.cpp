#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Service.h"
#include "Passageiro.h"
#include "Voo.h"

using namespace std;
int main() {
    Passageiro p1(3,1,true);
    Voo v(1,"2",1,"p","l",100);
    v.addPassageiro(p1);
    Passageiro p2 = v.findPassageiro(2);
    cout<<p2.getID()<<endl;
    return 0;

}
