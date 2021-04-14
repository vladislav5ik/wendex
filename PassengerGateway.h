//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_PASSENGERGATEWAY_H
#define HOMEWORK4_PASSENGERGATEWAY_H
#include "Gateway.h"
#include "Address.h"
#include "Order.h"

#include "vector"
using namespace std;


class PassengerGateway : Gateway{
    PassengerGateway();
    Order orderTaxi();
    vector<Address> getAddresses();
    vector<Address> getPinnedAddresses();
    bool unpinAddress();
};


#endif //HOMEWORK4_PASSENGERGATEWAY_H
