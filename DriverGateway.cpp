//
// Created by Professional on 14.04.2021.
//

#include "DriverGateway.h"
#include "Car.h"


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
