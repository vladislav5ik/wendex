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
void PassengerGateway::unPinAddress(Passenger &passenger, const Address &address) {
    if(address.id == -1){
        cout << "Address do not exist" << endl;
    } else {
        vector<int> new_vector;
        remove_copy(passenger.pinnedAddressesIds.begin(), passenger.pinnedAddressesIds.end(),
                    new_vector.begin(), address.id);
        passenger.pinnedAddressesIds = new_vector;
        cout << "Address " + address.title + " was unpinned" << endl;
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
void PassengerGateway::getAddresses(Passenger passenger) {
    if(passenger.addressesIds.empty()) {
        cout << "You have no addresses yet" << endl;
        return;
    }
    cout << "You have " + to_string(passenger.addressesIds.size()) + " addresses:" << endl;
    for(int i = 0; i < passenger.addressesIds.size(); i++){
        json address = Gateway::findAddress(passenger.addressesIds[i]);
        cout << i << " - " << address["title"]
             << " , full address = " << address["full"]
             << " , x=" << address["x"]
             << " , y=" << address["y"] << endl;
}}

void PassengerGateway::getPinnedAddresses(Passenger passenger) {
    if (passenger.pinnedAddressesIds.empty()) {
        cout << "You have no pinned addresses yet" << endl;
        return;
    }
    cout << "You have " + to_string(passenger.pinnedAddressesIds.size()) + " pinned addresses:" << endl;
    for (int i = 0; i < passenger.pinnedAddressesIds.size(); i++) {
        json address = Gateway::findAddress(passenger.pinnedAddressesIds[i]);
        cout << i << " - " << address["title"]
             << " , full address = " << address["full"]
             << " , x=" << address["x"]
             << " , y=" << address["y"] << endl;
    }


}


void PassengerGateway::orderTaxi(Passenger passenger, Address from, Address to, string carType) {
    for (int i = 0; i < Gateway::getDriversCount(); i++){
        json driver = Gateway::findDriver(i);
        if(Gateway::findCar(driver["carId"])["carType"] != carType ||
            driver["status"] == "in ride"){
            break;
        } else {
            int multiplier;
            if(carType == "Economy"){
                multiplier = 1;
            } else if (carType == "Comfort"){
                multiplier = 5;
            } else if (carType == "ComfortPlus") {
                multiplier = 8;
            } else if (carType == "Business"){
                multiplier = 10;
            } else {
                multiplier = 1;
            }
            double distance = getRandomNumber(5,100);
            int time = distance * 30;
            double cost = distance * multiplier;

            cout << "Please confirm the order: (Y/N)" << endl
                << "time = " << time << ", cost = " << cost << endl;
            string confirmation;
            cin >> confirmation;
            if (confirmation == "Y") {
                json car = Gateway::findCar(driver["carId"]);
                cout << "Car " << car["color"] << " " << car["model"] << ", number" << car["number"];
                Order order = Order(false, -1, from.id, to.id, driver["id"],
                                    passenger.id, driver["carId"], time, distance, cost);
                Gateway::addOrder(order);
                passenger.ordersIds.push_back(order.id);
                passenger.rating =(getRandomNumber(1,5) + passenger.rating) / passenger.ordersIds.size();
                driver["rating"] =(getRandomNumber(1,5) + driver["rating"].get<int>()) / driver["ordersIds"].size();
                saveAll();
                return;
            }
        }
    }
    cout << "Sorry, there are no free drivers now.";
}
