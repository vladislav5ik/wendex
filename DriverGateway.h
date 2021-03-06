//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_DRIVERGATEWAY_H
#define HOMEWORK4_DRIVERGATEWAY_H
#include "Gateway.h"
#include "Address.h"
#include "Order.h"
#include "Driver.h"
class AdminGateway;

class DriverGateway : Gateway{
public:
    friend class AdminGateway;
    DriverGateway();
    static Driver createAccount(const string &name, int securityPin);
    static Driver login(const string &name, int securityPin);
    static void linkCar(Driver& driver, Car& car);
    static void getOrderHistory(Driver driver);
    static void setStatus(Driver driver, string status);
    static void seeCars(Driver driver);
    static void getOrder(Driver driver);
};


#endif //HOMEWORK4_DRIVERGATEWAY_H
