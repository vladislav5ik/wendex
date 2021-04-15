//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_DRIVERGATEWAY_H
#define HOMEWORK4_DRIVERGATEWAY_H
#include "Gateway.h"
#include "Address.h"
#include "Order.h"
#include "Driver.h"

class DriverGateway : Gateway{
public:
    DriverGateway(const string &fileNameUsers, const string &fileNameOrders, const string &fileNameAddresses,
                  const string &fileNameCars);

    bool login(const Driver& driver, int securityPin);
    Car createCar(string color, string model, string number, string carType);
    Driver createAccount(const string &name, Car car, int securityPin);
};


#endif //HOMEWORK4_DRIVERGATEWAY_H
