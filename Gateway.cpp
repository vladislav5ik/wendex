//
// Created by Professional on 14.04.2021.
//

#include "Gateway.h"
#include <iomanip>
#include "cmath"
using namespace std;

string Gateway::fileNameAddresses = "addresses.json",
        Gateway::fileNameCars = "cars.json",
        Gateway::fileNameOrders = "orders.json",
        Gateway::fileNameUsers = "users.json";

json Gateway::jsonUsers = json::parse(ifstream(fileNameUsers)),
        Gateway::jsonAddresses = json::parse(ifstream(fileNameAddresses)),
        Gateway::jsonOrders = json::parse(ifstream(fileNameOrders)),
        Gateway::jsonCars = json::parse(ifstream(fileNameCars));
Gateway::Gateway() = default;

void Gateway::addCar(Car& car) {
    try{
        getAddress(car.number);
    } catch (notFound& e) {
        car.id = jsonCars.at("carsCount");
        jsonCars.at("carsCount") = (int) jsonCars.at("carsCount") + 1;
        jsonCars.at("cars").push_back(Car::toJson(car));
        saveCars();
        return;
    }
    throw alreadyExists("car number" + car.number);
}

void Gateway::addAddress(Address &address) {
    try{
        getAddress(address.title);
    } catch (notFound& e) {
        address.id = jsonAddresses.at("addressesCount");
        jsonAddresses.at("addressesCount") = (int) jsonAddresses.at("addressesCount") + 1;
        jsonAddresses.at("addresses").push_back(Address::toJson(address));
        saveAddresses();
        return;
    }
    throw alreadyExists("title " + address.title);
}

void Gateway::addOrder(Order &order) {
    order.id = jsonOrders.at("ordersCount");
    jsonOrders.at("ordersCount") = (int)jsonOrders.at("ordersCount") + 1;
    jsonOrders.at("orders").push_back(Order::toJson(order));
    saveOrders();
}

void Gateway::addDriver(Driver &driver) {
    driver.id = jsonUsers.at("driversCount");
    jsonUsers.at("driversCount") = (int) jsonUsers.at("driversCount") + 1;
    jsonUsers.at("drivers").push_back(Driver::toJson(driver));
    saveUsers();
}

void Gateway::addPassenger(Passenger &passenger) {
    passenger.id = jsonUsers.at("passengersCount");
    jsonUsers.at("passengersCount") = 1 + passenger.id;
    jsonUsers.at("passengers").push_back(Passenger::toJson(passenger));
    saveUsers();
}

void Gateway::saveUsers(){
    ofstream users_stream(fileNameUsers);
    users_stream << setw(4) << jsonUsers << std::endl;
    users_stream.close();
}

void Gateway::saveAddresses() {
    ofstream addresses_stream(fileNameAddresses);
    addresses_stream << setw(4) << jsonAddresses << std::endl;
    addresses_stream.close();
}
void Gateway::saveCars() {
    ofstream cars_stream(fileNameCars);
    cars_stream << setw(4) << jsonCars << std::endl;
    cars_stream.close();
}
void Gateway::saveOrders() {
    ofstream orders_stream(fileNameOrders);
    orders_stream << setw(4) << jsonOrders << std::endl;
    orders_stream.close();
}

json Gateway::findPassenger(int id) {
    return jsonUsers.at("passengers").at(id);
}

json Gateway::findDriver(int id) {
    return jsonUsers.at("drivers").at(id);
}

json Gateway::findOrder(int id) {
    return jsonOrders.at("orders").at(id);
}

json Gateway::findAddress(int id) {
    return jsonAddresses.at("addresses").at(id);
}

json Gateway::findCar(int id) {
    return jsonCars.at("cars").at(id);
}

int Gateway::getPassengersCount() {
    return jsonUsers.at("passengersCount");
}
int Gateway::getDriversCount() {
    return jsonUsers.at("driversCount");
}

int Gateway::getAddressesCount() {
    return jsonAddresses.at("addressesCount");
}

int Gateway::getOrdersCount() {
    return jsonOrders.at("ordersCount");
}

int Gateway::getCarsCount() {
    return jsonCars.at("carsCount");
}

Address Gateway::getAddress(string title) {
    for (int id = 0; id < getAddressesCount(); id++){
        json jsonAddress = findAddress(id);
        if (jsonAddress.at("title") == title)
            return Address::toInstance(jsonAddress);
    }
    throw notFound("address title " + title);
}

Car Gateway::getCar(string number) {
    for (int id = 0; id < getCarsCount(); id++){
        json jsonCar = findCar(id);
        if (jsonCar.at("number") == number)
            return Car::toInstance(jsonCar);
    }
    throw notFound("car number " + number);
}

Passenger Gateway::getPassenger(string name) {
    for (int id = 0; id < getPassengersCount(); id++){
        json jsonPassenger = findPassenger(id);
        if (jsonPassenger.at("name") == name)
            return Passenger::toInstance(jsonPassenger);
    }
    throw notFound("passenger's name " + name);
}

Driver Gateway::getDriver(string name) {
    for (int id = 0; id < getDriversCount(); id++){
        json jsonDriver = findDriver(id);
        if (jsonDriver.at("name") == name)
            return Driver::toInstance(jsonDriver);
    }
    throw notFound("driver's name " + name);
}

void Gateway::updatePassenger(json jsonPassenger) {
    Gateway::jsonUsers.at("passengers").at((int)jsonPassenger.at("id")) = jsonPassenger;
    saveUsers();
}

void Gateway::updateDriver(json jsonDriver) {
    Gateway::jsonUsers.at("drivers").at((int)jsonDriver.at("id")) = jsonDriver;
    saveUsers();
}

void Gateway::updateOrder(json jsonOrder) {
    Gateway::jsonOrders.at("orders").at((int)jsonOrder.at("id")) = jsonOrder;
    saveUsers();
}

void Gateway::updateCar(json jsonCar) {
    Gateway::jsonCars.at("cars").at((int)jsonCar.at("id")) = jsonCar;
    saveUsers();
}

json Gateway::findAdmin(int id) {
    return jsonUsers.at("admins").at(id);
}

int Gateway::getAdminCount() {
    return jsonUsers.at("adminsCount");
}

Admin Gateway::getAdmin(string name) {
    for (int id = 0; id < getAdminCount(); id++){
        json jsonAdmin = findAdmin(id);
        if (jsonAdmin.at("name") == name)
            return Admin::toInstance(jsonAdmin);
    }
    throw notFound("Admin's name " + name);}

void Gateway::addAdmin(Admin &admin) {
    admin.id = jsonUsers.at("adminsCount");
    jsonUsers.at("adminsCount") = 1 + admin.id;
    jsonUsers.at("admins").push_back(Admin::toJson(admin));
    saveUsers();
}

void Gateway::reset() {
    jsonUsers = {
            {"drivers", json::parse("[]")},
            { "driversCount", 0},
            { "passengers", json::parse("[]") },
            { "passengersCount", 0 },
            { "admins",  json::parse("[]")},
            { "adminsCount", 0 }
    };
    jsonAddresses = {
            {"addresses", json::parse("[]")},
            {"addressesCount", 0}
    };
    jsonCars = {
            {"cars", json::parse("[]")},
            {"carsCount", 0}
    };
    jsonOrders = {
            {"orders", json::parse("[]")},
            {"ordersCount", 0}
    };
    saveUsers();
    saveOrders();
    saveAddresses();
    saveCars();
}

void Gateway::computeOrder(json &jsonOrder, const Car &car, const Driver &driver) {
    json jsonFrom = Gateway::findAddress(jsonOrder.at("fromId"));
    json jsonTo = Gateway::findAddress(jsonOrder.at("toId"));

    int multiplier;
    if(car.carType == "Economy"){
        multiplier = 1;
    } else if (car.carType == "Comfort"){
        multiplier = 5;
    } else if (car.carType == "ComfortPlus") {
        multiplier = 8;
    } else if (car.carType == "Business"){
        multiplier = 10;
    } else {
        multiplier = 1;
    }
    double distance = sqrt(pow((car.x - (double)jsonFrom.at("x")),2) +
            pow((car.y - (double)jsonFrom.at("y")),2));

    int time = distance * 120 + getRandomNumber(50,100);
    double cost = distance * multiplier;

    jsonOrder.at("distance") = distance;
    jsonOrder.at("timeSeconds") = time;
    jsonOrder.at("cost") = cost;
    cout << "Order confirmed." << endl
    << "distance = " << distance << ", time = " << time << ", cost = " << cost << endl;
}

void Gateway::notifyPassenger(json& jsonOrder) {
    cout<< "[ notification for " << Gateway::findPassenger(jsonOrder.at("passengerId")).at("name") << "]"
    << "Order id" << jsonOrder.at("id")
    << " from " << Gateway::findAddress(jsonOrder.at("fromId")).at("title")
    << " to " << Gateway::findAddress(jsonOrder.at("toId")).at("title")
    << " has been competed.";

    string method = Gateway::findPassenger(jsonOrder.at("passengerId")).at("defaultPaymentMethod");
    if (method != ""){
        cout << "You pay using " << method;
    } else {
        cout << "You not specified payment method. Please pay with cash";
    }
    cout << " " << jsonOrder.at("cost") << "." << endl;
    jsonOrder.at("isFinished") = true;
    updateOrder(jsonOrder);

    int rate;
    cout << "Please rate this order from 1 to 5:" << endl;
    cin >> rate;
    if (rate > 5 || rate <1) rate = 5;
    cout << "Thank you!" << endl;
    json jsonDriver = Gateway::findDriver(jsonOrder.at("driverId"));
    jsonDriver.at("rating") = ((double)jsonDriver.at("rating") + rate)/((int)jsonDriver.at("ordersIds").size());
    updateDriver(jsonDriver);
}
