//
// Created by Professional on 14.04.2021.
//

#include "PassengerGateway.h"
#include "DriverGateway.h"
PassengerGateway::PassengerGateway() = default;

Passenger PassengerGateway::createAccount(const string &name, int securityPin) {
    try{
        getPassenger(name);
    } catch (notFound& e) {
        Passenger passenger =  Passenger(-1, securityPin, 0, name,"",{},{},{});
        Gateway::addPassenger(passenger);
        return passenger;
    }
    throw alreadyExists("name " + name);
}

Passenger PassengerGateway::login(const string & name, int securityPin) {
    Passenger passenger = getPassenger(name);//existence checks in that method too
    if (passenger.securityPin == securityPin){
        return passenger;
    }
    throw loginError();
}

void PassengerGateway::linkAddress(Passenger& passenger, Address& address) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
    if(address.id == -1)
        Gateway::addAddress(address);
    passenger.addressesIds.push_back(address.id);
    Gateway::updatePassenger(Passenger::toJson(passenger));
}
void PassengerGateway::pinAddress(Passenger& passenger,  Address& address) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
    if(address.id == -1){
        linkAddress(passenger,address);
    } else {
        passenger.pinnedAddressesIds.push_back(address.id);
        cout << "Address " + address.title + " was pinned" << endl;
        Gateway::updatePassenger(Passenger::toJson(passenger));
    }
}
void PassengerGateway::unPinAddress(Passenger &passenger,  Address &address) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
    if(address.id == -1){
        linkAddress(passenger,address);
    } else {
        vector<int> new_vector;
        remove_copy(passenger.pinnedAddressesIds.begin(), passenger.pinnedAddressesIds.end(),
                    new_vector.begin(), address.id);
        passenger.pinnedAddressesIds = new_vector;
        cout << "Address " + address.title + " was unpinned" << endl;
        Gateway::updatePassenger(Passenger::toJson(passenger));
    }
}
void PassengerGateway::setDefaultPaymentMethod(Passenger passenger, const string& paymentMethod) {
    passenger.defaultPaymentMethod = paymentMethod;
    cout << "Default payment method now is " + paymentMethod << endl;
    Gateway::updatePassenger(Passenger::toJson(passenger));
}
void PassengerGateway::getOrderHistory(Passenger passenger) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
    if(passenger.ordersIds.empty()){
        cout << "You have no orders yet" << endl;
        return;
    }
    cout << "You have " + to_string(passenger.ordersIds.size()) + " orders:" << endl;
    for(int i = 0; i < passenger.ordersIds.size(); i++){
        json order = Gateway::findOrder(passenger.ordersIds[i]);
        cout << "id" << passenger.ordersIds[i] << " - " << order.at("carType")
            << " from " << Gateway::findAddress(order.at("fromId")).at("title")
            << " from " << Gateway::findAddress(order.at("toId")).at("title");
        if(order.at("isFinished")){
            cout << "finished";
        } else {
            cout << "searching for car";
        }
        cout << endl;

    }
}
void PassengerGateway::getAddresses(Passenger passenger) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id)); //updating information from database
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
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
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


Order PassengerGateway::addOrder(Passenger passenger, Address from, Address to, string carType) {
    passenger = Passenger::toInstance(Gateway::findPassenger(passenger.id));
    if(from.id == -1) {
        linkAddress(passenger, from); //after that id will update
    }
    if(to.id == -1) {
        linkAddress(passenger, to);
    }

    Order order(from.id, to.id, passenger.id, carType);
    Gateway::addOrder(order);
    passenger.ordersIds.push_back(order.id);
    Gateway::updatePassenger(Passenger::toJson(passenger));
    //for (int i = 0; i < Gateway::getDriversCount(); i++){
    //    json driver = Gateway::findDriver(i);
    //    if(Gateway::findCar(driver["carId"])["carType"] != carType ||
    //        driver["status"] == "in ride"){
    //        break;
    //    } else {
    //        int multiplier;
    //        if(carType == "Economy"){
    //            multiplier = 1;
    //        } else if (carType == "Comfort"){
    //            multiplier = 5;
    //        } else if (carType == "ComfortPlus") {
    //            multiplier = 8;
    //        } else if (carType == "Business"){
    //            multiplier = 10;
    //        } else {
    //            multiplier = 1;
    //        }
    //        double distance = getRandomNumber(5,100);
    //        int time = distance * 30;
    //        double cost = distance * multiplier;
    //        cout << "Please confirm the order: (Y/N)" << endl
    //            << "time = " << time << ", cost = " << cost << endl;
    //        string confirmation;
    //        cin >> confirmation;
    //        if (confirmation == "Y") {
    //            json car = Gateway::findCar(driver["carId"]);
    //            cout << "Car " << car["color"] << " " << car["model"] << ", number" << car["number"];
    //            Order order = Order(false, -1, from.id, to.id, driver["id"],
    //                                passenger.id, driver["carId"], time, distance, cost);
    //            Gateway::addOrder(order);
    //            passenger.ordersIds.push_back(order.id);
    //            passenger.rating =(getRandomNumber(1,5) + passenger.rating) / passenger.ordersIds.size();
    //            saveAll();
                return order;
    //        }
    //    }
    //}
    //cout << "Sorry, there are no free drivers now.";
    //return Order(false,-1,-1,-1,-1,-1,-1,-1,-1,-1);
}
