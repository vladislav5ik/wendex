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
    PassengerGateway(const string &fileNameUsers, const string &fileNameOrders,
                     const string &fileNameAddresses, const string &fileNameCars);
    Passenger createAccount(const string &name, int securityPin);
    bool login(const Passenger& passenger, int securityPin);

    void addAddress(Passenger passenger, Address address);
    void pinAddress(Passenger& passenger, const Address& address);
    void unPinAddress(Passenger& passenger, const Address& address);
    void getAddresses(Passenger passenger);
    void getPinnedAddresses(Passenger passenger);
    void setDefaultPaymentMethod(Passenger passenger, const string& paymentMethod);
    void getOrderHistory(Passenger passenger);
    void orderTaxi(Passenger passenger, Address from, Address to, string carType);

private:
    int getRandomNumber(int min, int max);
};




#endif //HOMEWORK4_PASSENGERGATEWAY_H
