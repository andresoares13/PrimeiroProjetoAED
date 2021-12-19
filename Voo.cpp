#include <cmath>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include "Voo.h"
#include "CarrinhoDeTransporte.h"


int Voo::getNumero() const {
    return numero;
}

string Voo::getPartida() const {
    return partida;
}

int Voo::getDuration() const {
    return duration;
}

string Voo::getOrigem() const {
    return origem;
}

string Voo::getDestino() const {
    return destino;
}

int Voo::getCapacity() const {
    return capacity;
}

int Voo::getProfit() const {
    int profit;
    int bilhetesvendidos = capacity - ticketsAvailable();

    profit = bilhetesvendidos * getTicketPrice();

    return profit;
}

int Voo::getTicketPrice() const {
    return ticketprice;
}

int Voo::ticketsAvailable() const {
    return capacity-TicketsBought;
}

vector<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}

void Voo::addPassageiro(Passageiro &p) {
    if (p.isBagagem()==true){
        Bagagem b=p.GetBag();
        if (b.getPeso()>BagWeight){
            p.setCheckin(true);
        }
    }
    passageiros.push_back(p);
}

bool Voo::removePassageiro(int ID) {


    for(int i = 0; i < passageiros.size(); i++)
    {
        if(passageiros[i].getID() == ID)
        {
            passageiros.erase(passageiros.begin() + i);
            return true;
        }
    }

    return false; //se o passageiro não estiver
}

Passageiro &Voo::findPassageiro(int ID) {
    for(int i = 0; i < passageiros.size(); i++)
    {
        if(passageiros[i].getID() == ID)
        {
            return passageiros[i];
        }
    }
    throw logic_error("Passenger does not exist");
}


int Voo::numCarruagens(ModelCar model) const{
    int p=0;
    for (int i=0;i<passageiros.size();i++){
        if (passageiros[i].isCheckin()==true){
            p+=1;
        }
    }
    float m=model.getMalas()*model.getPilhas();
    float c=ceil(p/m);
    return c;
}

Voo::Voo(int numero, string partida, int duration, string origem, string destino, int capacity, int BagWeight) {
    this->numero=numero;
    this->partida=partida;
    this->origem=origem;
    this->destino=destino;
    this->duration=duration;
    this->capacity=capacity;
    TicketsBought=0;
    this->BagWeight=BagWeight;
}

string Voo::ModelSelector() {
    int c;
    for(int i=0;i<passageiros.size();i++){
        if (passageiros[i].isCheckin()==true){
            c+=1;
        }
    }
    if (c>=100){
        return "X";
    }
    else{
        return "Y";
    }
}


CarrinhoDeTransporte  Voo::AutoBag() {
    string x=ModelSelector();
    int chariots= numCarruagens(x);
    CarrinhoDeTransporte carrinho(chariots,x);
    for (int i=0;i<passageiros.size();i++){
        if (passageiros[i].isCheckin()){
            carrinho.AddBagagem(passageiros[i].GetBag());
        }
    }
    return carrinho;
}

void Voo::AddToBuy(Passageiro p) {
    ToBuyTicket.push(p);
}

void Voo::BuyTickets() {
    int size=ToBuyTicket.size();
    for (int i=0;i<size;i++){
        Passageiro p=ToBuyTicket.front();
        if (p.getNumTickets()<=ticketsAvailable()){
            TicketsBought+=p.getNumTickets();
            if (p.isBagagem()==true){
                NumBags+=1;
            }
        }
        ToBuyTicket.pop();
    }
}

void Voo::AddRandomP(int type) {
    int n;
    srand (time(NULL));
    if (type=400){
         n=rand() % 350 + 200;
    }
    if (type=200){
        n=rand() % 140 + 100;
    }
    if (type=100){
        n=rand() % 70 + 30;
    }
    for (int i=0;i<n;i++){
        Passageiro p(i+1,1, true, true);
        AddToBuy(p);
        addPassageiro(p);
    }
}

int Voo::getQueueSize() {
    return ToBuyTicket.size();
}

bool Voo::operator<(Voo &v) {
    if (partida.substr(6,4)==v.getPartida().substr(6,4)){
        if(partida.substr(3,2)==v.getPartida().substr(3,2)){
            if(partida.substr(0,2)==v.getPartida().substr(0,2)){
                return numero<v.getNumero();
            }
            return partida.substr(0,2)<v.getPartida().substr(0,2);
        }
        return partida.substr(3,2)<v.getPartida().substr(3,2);
    }
    return partida.substr(6,4)<v.getPartida().substr(6,4);
}

int Voo::getBagWeight() const {
    return BagWeight;
}
