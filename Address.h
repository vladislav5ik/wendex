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

class Address {
private:
    friend class Gateway;
    int id;
    string title, full;
    double x,y;
    json getJson();
};


#endif //HOMEWORK4_ADDRESS_H
