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
class Passenger {
private:
    friend class Gateway;
    int id, securityPin;
    double rating;
    string name, defaultPaymentMethod;
    vector<int> addressesIds, pinnedAddressesIds, ordersIds;
    json getJson();
};


#endif //HOMEWORK4_PASSENGER_H
