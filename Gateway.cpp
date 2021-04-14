//
// Created by Professional on 14.04.2021.
//

#include "Gateway.h"
#include <iomanip>
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
    jsonCars.at("carsCount") += 1;
    jsonCars.at("cars") += car.getJson();
    return car;
}

Address Gateway::addAddress(Address &address) {
    address.id = jsonAddresses["addressesCount"];
    jsonAddresses.at("addressesCount") += 1;
    jsonAddresses.at("addresses") += address.getJson();
    return address;
}

Order Gateway::addOrder(Order &order) {
    order.id = jsonOrders["ordersCount"];
    jsonOrders.at("ordersCount") += 1;
    jsonOrders.at("orders") += order.getJson();
    return order;
}

Driver Gateway::addDriver(Driver &driver) {
    driver.id = jsonUsers["driversCount"];
    jsonUsers.at("driversCount") += 1;
    jsonUsers.at("drivers") += driver.getJson();
    return driver;
}

Passenger Gateway::addPassenger(Passenger &passenger) {
    passenger.id = jsonUsers["passengersCount"];
    jsonUsers.at("passengersCount") = 1 + passenger.id;
    jsonUsers.at("passengers") += passenger.getJson();
    return passenger;
}

void Gateway::saveAll() {
    ofstream users_stream(fileNameUsers);
    users_stream << setw(4) << jsonUsers << std::endl;

    ofstream addresses_stream(fileNameAddresses);
    addresses_stream << setw(4) << jsonAddresses << std::endl;

    ofstream cars_stream(fileNameCars);
    cars_stream << setw(4) << jsonCars << std::endl;

    ofstream orders_stream(fileNameOrders);
    orders_stream << setw(4) << jsonOrders << std::endl;

    users_stream.close();
    addresses_stream.close();
    cars_stream.close();
    orders_stream.close();
}

json Gateway::findPassenger(int id) {
    return jsonUsers["passengers"][id];
}

json Gateway::findDriver(int id) {
    return jsonUsers["drivers"][id];
}

json Gateway::findOrder(int id) {
    return jsonOrders["orders"][id];
}

json Gateway::findAddress(int id) {
    return jsonAddresses["addresses"][id];
}

json Gateway::findCar(int id) {
    return jsonCars["cars"][id];
}

int Gateway::getPassengersCount() {
    return jsonUsers["passengersCount"];
}
int Gateway::getDriversCount() {
    return jsonUsers["driversCount"];
}

int Gateway::getAddressesCount() {
    return jsonAddresses["addressesCount"];
}

int Gateway::getOrdersCount() {
    return jsonOrders["ordersCount"];
}

int Gateway::getCarsCount() {
    return jsonCars["carsCount"];
}


