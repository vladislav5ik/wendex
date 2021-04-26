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
    Passenger(int id, int securityPin, double rating, const string &name, const string &defaultPaymentMethod,
              const vector<int> &addressesIds, const vector<int> &pinnedAddressesIds, const vector<int> &ordersIds);
    int id, securityPin;
    double rating;
    string name, defaultPaymentMethod;
    vector<int> addressesIds, pinnedAddressesIds, ordersIds;
    static json toJson(Passenger passenger);
    static Passenger toInstance(json jsonPassenger);
};


#endif //HOMEWORK4_PASSENGER_H
