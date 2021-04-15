//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_CAR_H
#define HOMEWORK4_CAR_H

#include <utility>
//#include "Gateway.h"
#include "json.hpp"
#include "string"

using namespace std;
using namespace nlohmann;


class Gateway;
class Car {
public:
    json getJson();

private:
public:
    Car(int id, int freeBottleOfWater, double x, double y, const string &carType, const string &model,
        const string &color, const string &number);

private:
    friend class Gateway;
    friend class DriverGateway;
    int id, freeBottleOfWater;
    double x, y;
    string carType, model, color, number;
};


#endif //HOMEWORK4_CAR_H
