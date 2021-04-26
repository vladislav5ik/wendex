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
    Car(const string &number,const string &color, const string &model,const string &carType, double x, double y, int freeBottleOfWater = 0);

private:
    friend class Gateway;
    friend class DriverGateway;
    int id, freeBottleOfWater;
    double x, y;
    string carType, model, color, number;
    bool is_validated;
    static json toJson(Car car);
    static Car toInstance(json jsonCar);
};


#endif //HOMEWORK4_CAR_H
