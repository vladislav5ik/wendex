//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_GATEWAY_H
#define HOMEWORK4_GATEWAY_H
#include <utility>

#include "fstream"
#include "iostream"
#include "json.hpp"
#include "Address.h"
#include "Car.h"
#include "Order.h"
#include "Driver.h"
#include "Passenger.h"

using namespace nlohmann;
using namespace std;

struct notFound : public exception{
    string parameterName;
    notFound(string parameterName = "Parameter"){
       this->parameterName = parameterName;
    };
    const char* what() const throw (){
        string message = "Error. " + parameterName + " not found.";
        return message.c_str();
    }
}; //for example, user not found in database
struct alreadyExists : public exception{
    string parameterName;
    alreadyExists(string parameterName = "Parameter"){
        this->parameterName = parameterName;
    };
    const char* what() const throw (){
        string message = "Error. " + parameterName + " is already exists.";
        return message.c_str();
    }
};
struct loginError : public exception{
    const char* what() const throw (){
        return "Error. Security pin is wrong.";
    }
};

class Gateway {
public:
    Gateway();
    static json findAddress(int id);
    static json findPassenger(int id);
    static json findDriver(int id);
    static json findOrder(int id);
    static json findCar(int id);

    static int getPassengersCount();
    static int getDriversCount();
    static int getOrdersCount();
    static int getAddressesCount();
    static int getCarsCount();

    static Address getAddress(string title);
    static Car getCar(string number);

private:
    static string fileNameUsers, fileNameOrders, fileNameAddresses, fileNameCars;
    static json jsonUsers, jsonOrders, jsonAddresses, jsonCars;

protected:
    static Passenger getPassenger(string name); //protected because password check in derived classes

    static Driver getDriver(string name);

    static void addAddress(Address& address);

    static void addCar(Car& car);

    static void addOrder(Order& order); //getRecipe will be (like toString)?

    static void addDriver(Driver& driver);

    static void addPassenger(Passenger& passenger);

    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    static void saveUsers();
    static void saveAddresses();
    static void saveCars();
    static void saveOrders();

    static void updatePassenger(json jsonPassenger);
    static void updateDriver(json jsonDriver);
    static void updateOrder(json jsonOrder);
    static void updateCar(json jsonCar);
};




#endif //HOMEWORK4_GATEWAY_H
