//
// Created by Professional on 14.04.2021.
//

#include "Gateway.h"
using namespace std;

Gateway::Gateway(const string& fileNameUsers, const string& fileNameOrders,
                 const string& fileNameAddresses, const string& fileNameCars) {

    this->fileNameAddresses = fileNameAddresses;
    this->fileNameCars = fileNameCars;
    this->fileNameOrders = fileNameOrders;
    this->fileNameUsers = fileNameUsers;

    ifstream fileUsers_stream(fileNameUsers);
    ifstream fileAddresses_stream(fileNameAddresses);
    ifstream fileCars_stream(fileNameCars);
    ifstream fileOrders_stream(fileNameOrders);

    this->jsonUsers = json::parse(fileUsers_stream);
    this->jsonAddresses = json::parse(fileAddresses_stream);
    this->jsonCars = json::parse(fileCars_stream);
    this->jsonOrders = json::parse(fileOrders_stream);
}

Car Gateway::addCar(Car& car) {
    car.id = jsonCars["carsCount"];
    jsonCars["carsCount"] += 1;
    jsonCars["cars"] += car.getJson();
    return car;
}

Address Gateway::addAddress(Address &address) {
    address.id = jsonCars["addressesCount"];
    jsonCars["addressesCount"] += 1;
    jsonCars["addresses"] += address.getJson();
    return address;
}

Order Gateway::addOrder(Order &order) {
    order.id = jsonCars["ordersCount"];
    jsonCars["ordersCount"] += 1;
    jsonCars["orders"] += order.getJson();
    return order;
}

Driver Gateway::addDriver(Driver &driver) {
    driver.id = jsonCars["driversCount"];
    jsonCars["driversCount"] += 1;
    jsonCars["drivers"] += driver.getJson();
    return driver;
}

Passenger Gateway::addPassenger(Passenger &passenger) {
    passenger.id = jsonCars["passengersCount"];
    jsonCars["passengersCount"] += 1;
    jsonCars["passengers"] += passenger.getJson();
    return passenger;
}

void Gateway::saveAll() {
    ofstream users_stream(jsonUsers);
    users_stream << jsonUsers << std::endl;

    ofstream addresses_stream(jsonAddresses);
    addresses_stream << jsonAddresses << std::endl;

    ofstream cars_stream(jsonCars);
    cars_stream << jsonCars << std::endl;

    ofstream orders_stream(jsonOrders);
    orders_stream << jsonOrders << std::endl;
}

