#include "Gateway.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"

using namespace std;


int main() {
    Gateway g = Gateway("users.json", "orders.json", "addresses.json", "cars.json");

    DriverGateway driveApp = DriverGateway("users.json", "orders.json", "addresses.json", "cars.json");
    Car myBusinessCar = driveApp.createCar("white", "WEndex self-driving", "a404ru", "Business");
    Driver drifter = driveApp.createAccount("Drifter Driftovich", myBusinessCar, 1234);

    PassengerGateway userApp = PassengerGateway("users.json", "orders.json", "addresses.json", "cars.json");
    Passenger studentka = userApp.createAccount("Anna K.", 123);

    Address a = Address("University", "Innopolis, University st. 1", 123, 456);
    Address b = Address("5ka", "Innopolis, Sportivnaya 152", 120, 450);

    if (userApp.login(studentka, 123)) {
        userApp.addAddress(studentka, a);
        userApp.addAddress(studentka, b);

        userApp.pinAddress(studentka, a);
        userApp.getPinnedAddresses(studentka);
        userApp.unPinAddress(studentka, a);

        userApp.getAddresses(studentka);
        userApp.getOrderHistory(studentka);
        userApp.setDefaultPaymentMethod(studentka, "card");

        Order order = userApp.orderTaxi(studentka, a, b, "Business");

        if (driveApp.login(drifter, 1234)) {
            driveApp.setStatus(drifter, "in ride");

            driveApp.getOrder(drifter, order);
            driveApp.getOrderHistory(drifter);
            driveApp.setStatus(drifter, "Ready to work!");
        }
        userApp.getOrderHistory(studentka);
    }
    // All data is always saved in json files.

    return 0;
}
