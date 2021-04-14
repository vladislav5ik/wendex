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
    Passenger p1;
    Driver d1;
    Gateway g = Gateway("users.json","orders.json","addresses.json","cars.json");
    //PassengerGateway pg1; //child of Gateway
    //DriverGateway dg1;

    //pg1.register(p1, string pwd); //or reg/login in one method. If not regitered - register.
    //pg1.login(p1, string pwd);



    return 0;
}
