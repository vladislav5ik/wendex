//
// Created by Professional on 14.04.2021.
//

#include "Car.h"

Car::Car(const string &number,const string &color, const string &model,const string &carType, double x, double y, int freeBottleOfWater) {
    this->number = number;
    this->color = color;
    this->model = model;
    this->carType = carType;
    this->x = x;
    this->y = y;
    this->freeBottleOfWater = freeBottleOfWater;
    this->id = -1;
    this->is_validated = false;
}
json Car::toJson(Car car) {
    json jsonCar = {
            {"id" , car.id},
            {"carType" , car.carType},
            {"model" , car.model},
            {"color" , car.color},
            {"number" , car.number},
            {"x" , car.x},
            {"y" , car.y},
            {"freeBottleOfWater" , car.freeBottleOfWater},
            {"is_validated" , car.is_validated}
    };
    return jsonCar;
}

Car Car::toInstance(json jsonCar) {
    Car car = Car(jsonCar.at("number"),
                  jsonCar.at("color"),
                  jsonCar.at("model"),
                  jsonCar.at("carType"),
                  jsonCar.at("x"),
                  jsonCar.at("y"),
                  jsonCar.at("freeBottleOfWater"));
    car.id = jsonCar.at("id");
    car.is_validated = jsonCar.at("is_validated");
    return car;
}