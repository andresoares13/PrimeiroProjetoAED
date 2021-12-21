#include <cmath>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include "Voo.h"

/**
 * Creates the flights with the data given and sets the the tickets bought to 0
 * @param numero flight number
 * @param partida departure date
 * @param duration flight duration
 * @param origem flight origin
 * @param destino flight destination
 * @param capacity flight capacity
 * @param BagWeight weight of the bag
 */
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

/**
 * Gets the flight number
 * @return flight number
 */
int Voo::getNumero() const {
    return numero;
}

/**
 * Gets the flight date
 * @return flight date
 */
string Voo::getPartida() const {
    return partida;
}

/**
 * Gets the flight duration
 * @return duration
 */
int Voo::getDuration() const {
    return duration;
}

/**
 * Gets the flight origin
 * @return origin
 */
string Voo::getOrigem() const {
    return origem;
}

/**
 * Gets the flight destination
 * @return destination
 */
string Voo::getDestino() const {
    return destino;
}

/**
 * Gets the maximum capacity of the flight
 * @return capacity
 */
int Voo::getCapacity() const {
    return capacity;
}

/**
 * Gets the profit done by that flight based on the tickets sold
 * @return profit
 */
int Voo::getProfit() const {
    int profit;
    int bilhetesvendidos = capacity - ticketsAvailable();

    profit = bilhetesvendidos * getTicketPrice();

    return profit;
}

/**
 * Gets the ticket price
 * @return ticket price
 */
int Voo::getTicketPrice() const {
    return ticketprice;
}

/**
 * Gets the number of tickets available
 * @return tickets available
 */
int Voo::ticketsAvailable() const {
    return capacity-TicketsBought;
}

/**
 * Gets all the passengers of the flight
 * @return vector of passengers
 */
vector<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}

/**
 * Adds a passenger to the flight and checks if his luggage has the right weight
 * @param p passenger who bought a ticket to the flight
 */
void Voo::addPassageiro(Passageiro &p) {
    if (p.isBagagem()==true){
        Bagagem b=p.GetBag();
        if (b.getPeso()>BagWeight)
            p.setCheckin(true);
    }
    passageiros.push_back(p);
}

/**
 * Removes the passsenger with the ID given if exists
 * @param ID passenger identification
 * @return bool
 */
bool Voo::removePassageiro(int ID) {
    for(int i = 0; i < passageiros.size(); i++){
        if(passageiros[i].getID() == ID)
        {
            passageiros.erase(passageiros.begin() + i);
            return true;
        }
    }
    return false;
}

/**
 * Finds the passenger with the ID given
 * If that passenger does not exist, throws an exception
 * @param ID passenger identification
 * @return passenger
 */
Passageiro &Voo::findPassageiro(int ID) {
    for(int i = 0; i < passageiros.size(); i++)
        if(passageiros[i].getID() == ID)
            return passageiros[i];
    throw logic_error("Passenger does not exist");
}

/**
 *Tells us the optiomal number of carriages needed for the transportation car based on the model of each carriage and the number of passengers that chose the auto chekcin option
 * It gives us a number in a way that it is guaranteed that there will be enough space for every luggage
 * @param model model of the carriage
 * @return numbers of carriages needed
 */
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

/**
 * Selects the optimal model of carriage to use in the Transportation car (for the lugagge) by the number of passengers that chose the auto checkin option
 * @return returns the string that represents the model
 */
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

/**
 * Adds all the passengers luggage to the cart
 * @return cart
 */
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

/**
 * Puts the passenger in the queue to wait for his turn to buy the ticket
 * @param p passenger
 */
void Voo::AddToBuy(Passageiro p) {
    ToBuyTicket.push(p);
}

/**
 * Each passenger in the queue buys the number of tickets desired based on the tickets available
 */
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

/**
 * It is called when the user chooses a flight and a plane and adds a random number of passengers to the flight given its capacity given by the parameter type
 * @param type represents the capacity of the flight (the capacity is given by the type of plane therefore the name type)
 */
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

/**
 * Gets the size of the passengers waiting queue
 * @return queue size
 */
int Voo::getQueueSize() {
    return ToBuyTicket.size();
}

/**
 * Sorts the flights list based on the date of each flight
 * If two flights have the same date, sorts it by its identification number
 * @param v object of the class Voo
 * @return
 */
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

/**
 * Gets the maximum weight per luggage
 * @return luggage weight
 */
int Voo::getBagWeight() const {
    return BagWeight;
}
