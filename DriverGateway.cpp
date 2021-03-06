//
// Created by Professional on 14.04.2021.
//

#include "DriverGateway.h"
#include "Car.h"
void DriverGateway::linkCar(Driver& driver, Car& car) {
    driver = Driver::toInstance(Gateway::findDriver(driver.id));
    Gateway::addCar(car);
    driver.carIds.push_back(car.id);
    Gateway::updateDriver(Driver::toJson(driver));
}

void DriverGateway::getOrderHistory(Driver driver) {
    driver = Driver::toInstance(Gateway::findDriver(driver.id));
    if(driver.ordersIds.empty()){
        cout << "You have no orders yet" << endl;
        return;
    }
    cout << "You have " + to_string(driver.ordersIds.size()) + " orders:" << endl;
    for(int i = 0; i < driver.ordersIds.size(); i++){
        json order = Gateway::findOrder(driver.ordersIds[i]);
        cout << "id" << driver.ordersIds[i] << " - " << order.at("cost")
             << " from " << Gateway::findAddress(order.at("fromId")).at("title")
             << " from " << Gateway::findAddress(order.at("toId")).at("title");
        if(order.at("isFinished")){
            cout << " - finished";
        } else {
            cout << " - now";
        }
        cout << endl;

    }
}
Driver DriverGateway::createAccount(const string &name, int securityPin) {
    try{
        getDriver(name);
    } catch (notFound& e) {
        Driver driver(-1,{}, securityPin, 0, "free", name,{} );
        Gateway::addDriver(driver);
        return driver;
    }
    throw alreadyExists("Driver's name " + name);
}

DriverGateway::DriverGateway() = default;


//Car DriverGateway::createCar(
//        string color, string model, string number, string carType) {
//    Car car = Car(-1,-1,getRandomNumber(1,1000),getRandomNumber(1,100),
//                  carType,model,color,number);
//    Gateway::addCar(car);
//    return car;
//}

void DriverGateway::setStatus(Driver driver, string status) {
    driver.status = status;
    cout << "Your status now: " << status << endl;
    saveUsers();
}

Driver DriverGateway::login(const string & name, int securityPin) {
    Driver driver = getDriver(name);//existence checks in that method too
    if (driver.securityPin == securityPin){
        return driver;
    }
    throw loginError();
}


void DriverGateway::seeCars(Driver driver) {
    driver = Driver::toInstance(Gateway::findDriver(driver.id)); //updating information from database
    if(driver.carIds.empty()) {
        cout << "You have no cars yet" << endl;
        return;
    }
    cout << "You have " + to_string(driver.carIds.size()) + " cars:" << endl;
    for(int i = 0; i < driver.carIds.size(); i++){
        json car = Gateway::findCar(driver.carIds[i]);
        cout << car.at("number") << " - " << car.at("model")
             << " , color = " << car.at("color")
             << " , type = " << car.at("carType")
             << " , water left = " << car.at("freeBottleOfWater")
             << " , coordinates =" << car.at("x") << ":" << car.at("y");
        if(car.at("is_validated")){
            cout << " - VALIDATED";
        } else {
            cout << " - NOT VALIDATED (waiting Admin approval)";
        }
        cout << endl;
    }}

void DriverGateway::getOrder(Driver driver) {
    for(int i = 0; i < Gateway::getOrdersCount(); i++){
        json jsonOrder = Gateway::findOrder(i);
        if (jsonOrder.at("isFinished")){
            continue;
        }
        for(int carId : driver.carIds){
            if (!Gateway::findCar(carId).at("is_validated")
             || jsonOrder.at("carType") != Gateway::findCar(carId).at("carType")){
                continue;
            }
            cout << "Order found. From " << Gateway::findAddress(jsonOrder.at("fromId")).at("title") <<
            " to " << Gateway::findAddress(jsonOrder.at("toId")).at("title") << endl;
            cout << "Press Y to take or anything else to discard" << endl;
            string ans; cin >> ans;
            if (ans == "Y"){
                Gateway::computeOrder(jsonOrder,Car::toInstance(Gateway::findCar(carId)), driver);
                driver.ordersIds.push_back(jsonOrder.at("id"));
                jsonOrder.at("driverId") = driver.id;
                Gateway::updateOrder(jsonOrder);
                Gateway::notifyPassenger(jsonOrder);
                updateDriver(Driver::toJson(driver));
                return;
            }
        }
        cout << "Seems that there are no orders left" << endl;
    }
}
