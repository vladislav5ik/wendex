//
// Created by Professional on 14.04.2021.
//
#include "Driver.h"

Driver::Driver(int id, int carId, int securityPin, double rating, const string &status, const string &name,
               const vector<int> &ordersIds) : id(id), carId(carId), securityPin(securityPin), rating(rating),
                                               status(status), name(name), ordersIds(ordersIds) {}

json Driver::getJson() {
    json orders = json::parse(this->ordersIds.begin(), this->ordersIds.end());
    json driver = {
            {"id", this->id},
            {"name", this->name},
            {"sucurityPin" , this->securityPin},
            {"rating" , this->securityPin},
            {"status" , this->status},
            {"ordersIds" , orders},
            {"carId" , this->carId}
    };
    return driver;
}