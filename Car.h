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
    friend class Gateway;
    int id, freeBottleOfWater;
    double x, y;
    string carType, model, color, number;
};


#endif //HOMEWORK4_CAR_H
