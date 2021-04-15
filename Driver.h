//
// Created by Professional on 14.04.2021.
//

#ifndef HOMEWORK4_DRIVER_H
#define HOMEWORK4_DRIVER_H
#include "string"
#include "vector"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Driver {
private:
    friend class Gateway;
    friend class DriverGateway;
    int id, carId, securityPin;
    double rating;
    string status, name;
    vector<int> ordersIds;
    json getJson();

    Driver(int id, int carId, int securityPin, double rating, const string &status, const string &name,
           const vector<int> &ordersIds);
};


#endif //HOMEWORK4_DRIVER_H
