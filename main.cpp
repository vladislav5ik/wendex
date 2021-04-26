#include "Gateway.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "AdminGateway.h"

using namespace std;

int main() {
    Gateway::reset(); //WARNING it will erase your data
    cout << "Database was erased" << endl;

    try {
        Passenger p1 = PassengerGateway::createAccount("Vladislav", 1234);
        Passenger p2 = PassengerGateway::createAccount("Vladislav", 4321);
    } catch (alreadyExists& e) {
        cout << e.what();
        cout << " - Only one user with unique name was created" << endl;
    }

    Passenger p1 = PassengerGateway::login("Vladislav", 1234);
    Driver d1 = DriverGateway::createAccount("Alex", 7777);
    try {
        d1 = DriverGateway::login("Alex", 5656); //by the way driver is already authorized in var d1
    } catch (loginError& e) { //incorrect security pin
        cout << e.what() << endl;
    }
    try {
        Driver d2 = DriverGateway::login("Max", 1111); //not registered
    } catch (notFound& e) {
        cout << e.what() << endl;
    }

    Address a1("5ka", "Innopolis, street Sportivnaya 25/1", 5.59, 55.30);
    Address a2("uni", "Innopolis, street University 1", 5.89,55.9);
    PassengerGateway::linkAddress(p1,a1);
    PassengerGateway::pinAddress(p1,a1);
    PassengerGateway::linkAddress(p1, a2);

    PassengerGateway::getAddresses(p1);
    PassengerGateway::getPinnedAddresses(p1);

    PassengerGateway::unPinAddress(p1,a1);
    PassengerGateway::getPinnedAddresses(p1);

    PassengerGateway::setDefaultPaymentMethod(p1, "card");
    Order o1 = PassengerGateway::addOrder(p1,a1,a2,"business");
    PassengerGateway::getOrderHistory(p1);

    Car car("M563OP77","RED","WENDEX SELF-DRIVING","business",5.39,55.9);
    DriverGateway::linkCar(d1,car);
    DriverGateway::seeCars(d1);
    DriverGateway::setStatus(d1, "free");

    Admin adm = AdminGateway::createAccount("Elena", 7979);
    AdminGateway::blockCar(adm,car); //However, car was blocked since creation. But admin can block manually at any moment.
    AdminGateway::validateCar(adm, car);

    DriverGateway::seeCars(d1);
    DriverGateway::getOrder(d1);
    return 0;
}