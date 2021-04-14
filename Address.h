//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_ADDRESS_H
#define HOMEWORK4_ADDRESS_H
#include "string"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Gateway;
class PassengerGateway;
class Address {
public:
    Address(const string &title, const string &full, double x, double y);
private:
    friend class Gateway;
    friend class PassengerGateway;
    int id;
    string title, full;
    double x,y;
    json getJson();
};


#endif //HOMEWORK4_ADDRESS_H
