//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_GATEWAY_H
#define HOMEWORK4_GATEWAY_H
#include "fstream"
#include "iostream"
#include "json.hpp"
#include "Address.h"
#include "Car.h"
#include "Order.h"
#include "Driver.h"
#include "Passenger.h"

using namespace nlohmann;
using namespace std;

class Gateway {
public:
    Gateway(const string& fileNameUsers, const string& fileNameOrders,
            const string& fileNameAddresses, const string& fileNameCars);
private:
    string fileNameUsers, fileNameOrders, fileNameAddresses, fileNameCars;
    json jsonUsers, jsonOrders, jsonAddresses, jsonCars;
protected:
    Car addCar(Car& car);
    Address addAddress(Address& address);
    Order addOrder(Order& order);
    Driver addDriver(Driver& driver);
    Passenger addPassenger(Passenger& passenger);
    void saveAll();

    json getUser(int id);
    json getOrder(int id);
    json getAddress(int id);
    json getCar(int id);

    //boolean authUser(User user, int securityPin);
};



#endif //HOMEWORK4_GATEWAY_H
