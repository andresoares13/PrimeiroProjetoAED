#include <cstdlib>
#include <ctime>
#include "Passageiro.h"

/**
 * Creates a passenger with the given data.
 * If the passenger has luggage, the luggage weight will be choosen randomly
 * @param ID passenger identification
 * @param num_tickets number of tickets the passenger wants to buy
 * @param bagagem passenger has luggage (true) or doesn't (false)
 * @param checkin passenger wants automatic check in (true) or doesn't (false)
 */
Passageiro::Passageiro(int ID, int num_tickets, bool bagagem, bool checkin) {
    srand (time(NULL));
    this->ID=ID;
    this->num_tickets=num_tickets;
    this->bagagem=bagagem;
    this->checkin=checkin;
    if (bagagem==true){
        Bagagem mala(ID,rand() % 80 + 10);
        bag.push_back(mala);
    }
}

/**
 * Checks if the passenger has luggage or not
 * @return bool
 */
bool Passageiro::isBagagem() const {
    return bagagem;
}

/**
 * Checks if the passenger wants the automatic check in or not
 * @return bool
 */
bool Passageiro::isCheckin() const {
    return checkin;
}

/**
 * Gets the passenger identification
 * @return passenger identification
 */
int Passageiro::getID() const {
    return this->ID;
}

/**
 * Updates the checkin
 * @param checkin
 */
void Passageiro::setCheckin(bool checkin) {
    Passageiro::checkin = checkin;
}

/**
 * Gets the tickets amount the passenger wants to buy
 * @return tickets amount
 */
int Passageiro::getNumTickets() const {
    return num_tickets;
}

/**
 * Updates the tickets amount the passenger wants to buy
 * @param num
 */
void Passageiro::setNumTickets(int num) {
    this-> num_tickets = num;
}

/**
 * Gets the passenger luggage
 * @return luggage
 */
Bagagem Passageiro::GetBag() const {
    return bag[0];
}




