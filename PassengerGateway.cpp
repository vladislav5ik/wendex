//
// Created by Professional on 14.04.2021.
//

#include "PassengerGateway.h"

PassengerGateway::PassengerGateway(const string &fileNameUsers, const string &fileNameOrders,
                                   const string &fileNameAddresses, const string &fileNameCars) :
                                   Gateway(fileNameUsers, fileNameOrders, fileNameAddresses, fileNameCars) {

}

Passenger PassengerGateway::createAccount(const string &name, int securityPin) {
    Passenger passenger =  Passenger(-1, securityPin, 0, name,"",{},{},{});
    addPassenger(passenger);
    saveAll();
    return passenger;
}

bool PassengerGateway::login(const Passenger& passenger, int securityPin) {
    return passenger.securityPin == securityPin;
}

void PassengerGateway::addAddress(Passenger passenger, Address address) {
    Gateway::addAddress(address);
    passenger.addressesIds.push_back(address.id);
    saveAll();
}

void PassengerGateway::pinAddress(Passenger& passenger, const Address& address) {
    if(address.id == -1){
        cout << "Address do not exist" << endl;
    } else {
        passenger.pinnedAddressesIds.push_back(address.id);
        cout << "Address " + address.title + " was pinned" << endl;
        saveAll();
    }
}

void PassengerGateway::setDefaultPaymentMethod(Passenger passenger, const string& paymentMethod) {
    passenger.defaultPaymentMethod = paymentMethod;
    cout << "Default payment method now is " + paymentMethod << endl;
    saveAll();
}

void PassengerGateway::getOrderHistory(Passenger passenger) {
    if(passenger.ordersIds.empty()){
        cout << "You have no orders yet" << endl;
        return;
    }
    cout << "You have " + to_string(passenger.ordersIds.size()) + " orders:" << endl;
    for(int i = 0; i < passenger.ordersIds.size(); i++){
        json order = Gateway::findOrder(passenger.ordersIds[i]);
        cout << i << " - " << Gateway::findCar(order["carID"])["carType"]
            << " from " << Gateway::findAddress(order["fromId"])["title"]
            << " from " << Gateway::findAddress(order["toId"])["title"] << endl;

    }
}

