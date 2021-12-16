//
// Created by andre on 02-12-2021.
//

#ifndef UNTITLED1_VOO_H
#define UNTITLED1_VOO_H
#include <string>
#include <vector>
#include "Passageiro.h"
#include "ModelCar.h"
#include "CarrinhoDeTransporte.h"
#include <list>
#include <queue>


using namespace std;

class Voo {
public:
    Voo(int numero, string partida, int duration, string origem, string destino,int capacity, int BagWeight);
    int getNumero() const;
    string getPartida() const;
    int getDuration() const;
    string getOrigem() const;
    string getDestino() const;
    int getCapacity() const;
    int getProfit() const;   //dinheiro que vais ser feito com o voo
    int getTicketPrice() const;
    int ticketsAvailable() const;
    vector<Passageiro> getPassageiros() const;
    bool addPassageiro(Passageiro &p); //adiciona passageiro se o nº de bilhetes que quer comprar for inferior ou igual aos lugares disponíveis
    bool removePassageiro(int ID); //caso o passageiro com esse ID exista, remove-o
    Passageiro& findPassageiro(int ID);
    string ModelSelector(); //retorna o modelo de carruagem mais adequado em função dos passageiros com bagagem
    int numCarruagens(ModelCar model) const; //retorna o numero de carrugens necessario em funçao do modelo e do numero de passageiros
    CarrinhoDeTransporte AutoBag(); // chooses the model, creates the car with the correct number of chariots, adds the baggs to the car and returns it
    void AddToBuy (Passageiro p); //Adds a potential passenger to the queue to buy a ticket
    void BuyTickets(); //goes through the queue of potential passengers and if there is space and if their luggage can go to the plane, they buy the tickets. also adds the passengers to the vector
private:
    int numero;
    string partida; //data de partida
    int duration;
    int TicketsBought;
    string origem;
    string destino;
    int ticketprice;
    int capacity;
    int NumBags; // minimum amount of luggage
    int BagWeight;
    vector<Passageiro> passageiros;
    queue<Passageiro> ToBuyTicket;
};


#endif //UNTITLED1_VOO_H
