#include "Gateway.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"

using namespace std;


int main() {
    DriverGateway driveApp;
    PassengerGateway userApp;

    Car myBusinessCar = Car("a404ru", "white", "WEndex self-driving", "Business", 152, 165);
    //Driver drifter = driveApp.createAccount("Drifter Driftovich", 1234);

    Driver drifter1 = driveApp.login("Drifter Driftovich", 1234);
    //Passenger studentka = userApp.createAccount("Anna K.", 123);

    Address a = Address("University", "Innopolis, University st. 1", 123, 456);
    Address b = Address("5ka", "Innopolis, Sportivnaya 152", 120, 450);
    //Address c = Gateway::getAddress("5ka"); //result - error because address not linked to any user and hence not found in database

    Passenger studentka1 = userApp.login("Anna K.", 123);
        //userApp.linkAddress(studentka1, a);
        //userApp.linkAddress(studentka1, b);

        userApp.pinAddress(studentka1, a);
        userApp.getPinnedAddresses(studentka1);
        userApp.unPinAddress(studentka1, a);

        userApp.getAddresses(studentka1);
        userApp.getOrderHistory(studentka1);
        userApp.setDefaultPaymentMethod(studentka1, "card");

        Order order = userApp.addOrder(studentka1, a, b, "Business");

        drifter1 = driveApp.login("Drifter Driftovich", 1234);
        driveApp.setStatus(drifter1, "in ride");

//            driveApp.getOrder(drifter, order);
            driveApp.getOrderHistory(drifter1);
            driveApp.setStatus(drifter1, "free");
        userApp.getOrderHistory(studentka1);
        // All data is always saved in json files.
    return 0;
}
