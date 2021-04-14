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
    void saveAll();
    json findPassenger(int id);
    json findDriver(int id);
    json findOrder(int id);
    json findAddress(int id);
    json findCar(int id);
    int getPassengersCount();
    int getDriversCount();
    int getOrdersCount();
    int getAddressesCount();
    int getCarsCount();
private:
    string fileNameUsers, fileNameOrders, fileNameAddresses, fileNameCars;
    json jsonUsers, jsonOrders, jsonAddresses, jsonCars;

protected:
    Car addCar(Car& car);
    Address addAddress(Address& address);
    Order addOrder(Order& order);
    Driver addDriver(Driver& driver);
    Passenger addPassenger(Passenger& passenger);



    //boolean authUser(User user, int securityPin);
};




#endif //HOMEWORK4_GATEWAY_H
