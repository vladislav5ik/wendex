//
// Created by Professional on 14.04.2021.
//

#include "Car.h"

Car::Car(int id, int freeBottleOfWater, double x, double y, const string &carType, const string &model,
         const string &color, const string &number) : id(id), freeBottleOfWater(freeBottleOfWater), x(x), y(y),
                                                      carType(carType), model(model), color(color), number(number) {}
json Car::getJson() {
    json car = {
            {"id" , this->id},
            {"carType" , this->carType},
            {"model" , this->model},
            {"color" , this->color},
            {"number" , this->number},
            {"x" , this->x},
            {"y" , this->y},
            {"{freeBottleOfWater" , this->freeBottleOfWater}
    };
    return car;
}