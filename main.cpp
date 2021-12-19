#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Service.h"
#include "Passageiro.h"
#include "Voo.h"
#include "CarrinhoDeTransporte.h"
#include "Aeroporto.h"
#include "AirportMaker.h"
#include "App.h"

using namespace std;
int main() {

    AirportMaker createPort;
    createPort.FillAirport();
    Aeroporto aeroporto = createPort.GetAeroporto();
    App app(aeroporto);
    return (app.run());
}
