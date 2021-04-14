//
// Created by Professional on 14.04.2021.
//

#include "Car.h"
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