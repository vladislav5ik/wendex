#include <iostream>

#include "Gateway.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "Driver.h"
#include "Passenger.h"
#include "Order.h"
#include "Car.h"
#include "Address.h"
#include "json.hpp"
using namespace std;
using namespace nlohmann;



int main() {
    Gateway g = Gateway("users.json","orders.json","addresses.json","cars.json");
    PassengerGateway passengerApp = PassengerGateway("users.json","orders.json","addresses.json","cars.json");
    Passenger p1 = passengerApp.createAccount("Anna", 123);



    return 0;
}
