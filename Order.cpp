//
// Created by Professional on 14.04.2021.
//

#include "Order.h"

json Order::getJson() {
    json order = {
            {"id" , this->id},
            {"isFinished" , true},
            {"fromId" , this->fromId},
            {"toId" , this->toId},
            {"distance" , this->distance},
            {"carId" , this->carId},
            {"cost" , this->cost},
            {"driverId" , this->driverId},
            {"passengerId" , this->passengerId},
            {"timeSeconds" , this->timeSeconds}
    };
    return order;
}