//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_ORDER_H
#define HOMEWORK4_ORDER_H
#include "string"
#include "json.hpp"
using namespace std;
using namespace nlohmann;


class Order {
private:
    friend class Gateway;
    bool is_finished;
    int id, fromId, toId, driverId, passengerId, carId, timeSeconds;
    double distance, cost;
    json getJson();
};


#endif //HOMEWORK4_ORDER_H
