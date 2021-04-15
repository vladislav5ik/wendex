//
// Created by Professional on 14.04.2021.
//

#include "Order.h"
Order::Order(bool isFinished, int id, int fromId, int toId, int driverId, int passengerId, int carId, int timeSeconds,
             double distance, double cost) : is_finished(isFinished), id(id), fromId(fromId), toId(toId),
                                             driverId(driverId), passengerId(passengerId), carId(carId),
                                             timeSeconds(timeSeconds), distance(distance), cost(cost) {}
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