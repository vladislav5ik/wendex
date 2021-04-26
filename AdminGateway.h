//
// Created by Professional on 26.04.2021.
//

#ifndef HOMEWORK4_ADMINGATEWAY_H
#define HOMEWORK4_ADMINGATEWAY_H
#include "Admin.h"
#include "Gateway.h"
#include "PassengerGateway.h"
class AdminGateway : Gateway{
public:
    AdminGateway() = default;
    static Admin createAccount(const string &name, int securityPin);
    static Admin login(const string &name, int securityPin);
    static void seeAllData(Admin admin);
    static void validateCar(Admin admin, Car car);
    static void blockCar(Admin admin, Car car);
};


#endif //HOMEWORK4_ADMINGATEWAY_H
