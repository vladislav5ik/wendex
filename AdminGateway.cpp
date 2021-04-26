//
// Created by Professional on 26.04.2021.
//

#include "AdminGateway.h"

Admin AdminGateway::createAccount(const string &name, int securityPin) {
    try{
        getAdmin(name);
    } catch (notFound& e) {
        Admin admin =  Admin(name, securityPin,-1);
        Gateway::addAdmin(admin);
        return admin;
    }
    throw alreadyExists("Admin's name " + name);
}

Admin AdminGateway::login(const string &name, int securityPin) {
    Admin admin = getAdmin(name);//existence of account checks in that method too
    if (admin.securityPin == securityPin){
        return admin;
    }
    throw loginError();
}

void AdminGateway::seeAllData(Admin admin) {
    cout << endl << "---Passengers Orders Data---" << endl;
    for (int i = 0; i < getPassengersCount(); i++) {
        Passenger passenger = Passenger::toInstance(Gateway::findPassenger(i));
        cout << "-- PassengerId = " << i << ", Name = " << passenger.name << ", Pin " << passenger.securityPin << " ";
        PassengerGateway::getOrderHistory(passenger);
        PassengerGateway::getAddresses(passenger);
        PassengerGateway::getPinnedAddresses(passenger);
    }

    cout << endl << "---Drivers Orders Data---" << endl;
    for (int i = 0; i < getDriversCount(); i++) {
        Driver driver = Driver::toInstance(Gateway::findDriver(i));
        cout << "-- DriverId = " << i << ", Name = " << driver.name << ", Pin = " << driver.securityPin << " ";;
        DriverGateway::getOrderHistory(driver);
        DriverGateway::seeCars(driver);
    }


    cout << endl << "---Admin Data---" << endl;
    for (int i = 0; i < getAdminCount(); i++) {
        Admin admin = Admin::toInstance(Gateway::findAdmin(i));
        cout << "-- AdminId = " << i << ", Name = " << admin.name << ", Pin = " << admin.securityPin << endl;;
    }

    cout << endl << "---Orders Data---" << endl;
    for (int i = 0; i < getOrdersCount(); i++) {
        json jsonOrder = Gateway::findOrder(i);
        cout << "-- id = " << jsonOrder.at("id")
             << ", passenger = " << Gateway::findPassenger((int) jsonOrder.at("passengerId")).at("name")
             << ", carType =" << jsonOrder.at("carType")
             << ", from = " << Gateway::findAddress(jsonOrder.at("fromId")).at("title")
             << ", to = " << Gateway::findAddress(jsonOrder.at("toId")).at("title");
        if (jsonOrder.at("isFinished")) {
            cout << " - finished by driver with id = " << jsonOrder.at("driverId");
        } else {
            cout << " - searching for car";
        }
        cout << endl;
    }

    cout << endl << "---Addresses Data---" << endl;
    for (int i = 0; i < getAddressesCount(); i++) {
        json address = Gateway::findAddress(i);
        cout << "-- " << i << " - title = " << address["title"]
             << " , full address = " << address["full"]
             << " , x=" << address["x"]
             << " , y=" << address["y"] << endl;
    }

    cout << endl << "---Cars Data---" << endl;
    for(int i = 0; i < getCarsCount(); i++){
        json car = Gateway::findCar(i);
        cout << "-- " << car.at("number") << " - " << car.at("model")
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
    }
}

void AdminGateway::validateCar(Admin admin, Car car) {
    car.is_validated = true;
    updateCar(Car::toJson(car));
}

void AdminGateway::blockCar(Admin admin, Car car) {
    car.is_validated = false;
    updateCar(Car::toJson(car));
}
