//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_PASSENGERGATEWAY_H
#define HOMEWORK4_PASSENGERGATEWAY_H
#include "Gateway.h"
#include "Address.h"
#include "Order.h"
#include "Passenger.h"

#include "vector"
using namespace std;

class PassengerGateway : Gateway{
public:
    PassengerGateway();
    static Passenger createAccount(const string &name, int securityPin);
    static Passenger login(const string &name, int securityPin);

    static void linkAddress(Passenger& passenger, Address& address);
    static void pinAddress(Passenger& passenger, Address& address);
    static void unPinAddress(Passenger& passenger, Address& address);
    static void getAddresses(Passenger passenger);
    static void getPinnedAddresses(Passenger passenger);
    static void setDefaultPaymentMethod(Passenger passenger, const string& paymentMethod);
    static void getOrderHistory(Passenger passenger);
    Order addOrder(Passenger passenger, Address from, Address to, string carType); //addOrder so-called

};



#endif //HOMEWORK4_PASSENGERGATEWAY_H
