//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_PASSENGER_H
#define HOMEWORK4_PASSENGER_H
#include "string"
#include "vector"
#include "json.hpp"
//#include "Gateway.h"
using namespace std;
using namespace nlohmann;

class Gateway;
class PassengerGateway;
class Passenger {
private:
    friend class Gateway;
    friend class PassengerGateway;
    int id, securityPin;
    Passenger(int id, int securityPin, double rating, const string &name, const string &defaultPaymentMethod,
              const vector<int> &addressesIds, const vector<int> &pinnedAddressesIds, const vector<int> &ordersIds);

private:
    double rating;
    string name, defaultPaymentMethod;
    vector<int> addressesIds, pinnedAddressesIds, ordersIds;
    json getJson();
};


#endif //HOMEWORK4_PASSENGER_H
