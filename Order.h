//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_ORDER_H
#define HOMEWORK4_ORDER_H
#include "string"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Gateway;
class PassengerGateway;
class DriverGateway;

class Order {
private:
    friend class Gateway;
    friend class PassengerGateway;
    friend class DriverGateway;

private:
    Order(int fromId, int toId, int passengerId, string carType);
    //add recipe getter (toString method like)
    bool is_finished;
    int id, fromId, toId, driverId, passengerId, timeSeconds;
    double distance, cost;
    string carType;
    static json toJson(Order order);
};


#endif //HOMEWORK4_ORDER_H
