//
// Created by Professional on 14.04.2021.
//

#include "Order.h"
Order::Order(int fromId, int toId, int passengerId, string carType) {
    this->fromId = fromId;
    this->toId = toId;
    this->passengerId = passengerId;
    this->carType = carType;

    //these fields update when search for driver is complete
    //and when driver accept order or it is finished
    this->is_finished = false;
    this->id = -1;
    this->distance = -1;
    this->driverId = -1;
    this->cost = -1;
    this->timeSeconds = -1;
}
json Order::toJson(Order order) {
    json jsonOrder = {
            {"id" , order.id},
            {"isFinished" , order.is_finished},
            {"fromId" , order.fromId},
            {"toId" , order.toId},
            {"distance" , order.distance},
            {"carType" , order.carType},
            {"cost" , order.cost},
            {"driverId" , order.driverId},
            {"passengerId" , order.passengerId},
            {"timeSeconds" , order.timeSeconds}
    };
    return jsonOrder;
}