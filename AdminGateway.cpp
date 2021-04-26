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
    Admin admin = getAdmin(name);//existence checks in that method too
    if (admin.securityPin == securityPin){
        return admin;
    }
    throw loginError();
}

void AdminGateway::seeAllData(Admin admin) {
    cout << "---Passengers Data---" << endl;
    for (int i = 0; i < getPassengersCount();i++){
        Passenger passenger = Passenger::toInstance(Gateway::findPassenger(i));
        cout << "-" << i << "-"; PassengerGateway::getOrderHistory(passenger);
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
