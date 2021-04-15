//
// Created by Professional on 14.04.2021.
//

#include "DriverGateway.h"
#include "Car.h"

void DriverGateway::getOrderHistory(Driver driver) {
    if(driver.ordersIds.empty()){
        cout << "You have no orders yet" << endl;
        return;
    }
    cout << "You have " + to_string(driver.ordersIds.size()) + " orders:" << endl;
    for(int i = 0; i < driver.ordersIds.size(); i++){
        json order = Gateway::findOrder(driver.ordersIds[i]);
        cout << i << " - " << Gateway::findCar(order["carID"])["carType"]
             << " from " << Gateway::findAddress(order["fromId"])["title"]
             << " from " << Gateway::findAddress(order["toId"])["title"] << endl;

    }
}
Driver DriverGateway::createAccount(const string &name, Car car, int securityPin) {
    Driver driver = Driver(-1,car.id,securityPin,0,"free",name,{});
    Gateway::addDriver(driver);
    return driver;
}

DriverGateway::DriverGateway(const string &fileNameUsers, const string &fileNameOrders, const string &fileNameAddresses,
                             const string &fileNameCars) : Gateway(fileNameUsers, fileNameOrders, fileNameAddresses,
                                                                   fileNameCars) {}

bool DriverGateway::login(const Driver &driver, int securityPin) {
    return driver.securityPin == securityPin;
}

Car DriverGateway::createCar(
        string color, string model, string number, string carType) {
    Car car = Car(-1,-1,getRandomNumber(1,1000),getRandomNumber(1,100),
                  carType,model,color,number);
    Gateway::addCar(car);
    return car;
}

void DriverGateway::setStatus(Driver driver, string status) {
    driver.status = status;
    cout << "Your status now: " << status << endl;
    saveAll();
}

void DriverGateway::getOrder(Driver driver, Order order) {
    if (order.is_finished) {
        driver.ordersIds.push_back(order.id);
        cout << "Thank you for choosing WEndex taxi! Pleas leave feedback." << endl;
        driver.rating = (getRandomNumber(1, 5) + driver.rating) / driver.ordersIds.size();
        saveAll();
    }
}
