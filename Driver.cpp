//
// Created by Professional on 14.04.2021.
//
#include "Driver.h"

Driver::Driver(int id, vector<int> carIds, int securityPin, double rating, const string &status, const string &name,
               const vector<int> &ordersIds) : id(id), carIds(carIds), securityPin(securityPin), rating(rating),
                                               status(status), name(name), ordersIds(ordersIds) {}

json Driver::toJson(Driver driver) {
    json orders, cars;
    if(driver.ordersIds.empty()){
        orders = json::parse("[]");
    }else {
        orders = json::parse(driver.ordersIds.begin(), driver.ordersIds.end());
    }
    if(driver.carIds.empty()){
        cars = json::parse("[]");
    }else {
        cars = json::parse(driver.carIds.begin(), driver.carIds.end());
    }
    json jsonDriver = {
            {"id", driver.id},
            {"name", driver.name},
            {"securityPin" , driver.securityPin},
            {"rating" , driver.rating},
            {"status" , driver.status},
            {"ordersIds" , orders},
            {"carIds" , cars}
    };
    return jsonDriver;
}

Driver Driver::toInstance(json jsonDriver) {
    Driver driver = Driver(jsonDriver.at("id"),
                           jsonDriver.at("carIds"),
                           jsonDriver.at("securityPin"),
                           jsonDriver.at("rating"),
                           jsonDriver.at("status"),
                           jsonDriver.at("name"),
                           jsonDriver.at("ordersIds"));
    return driver;
}