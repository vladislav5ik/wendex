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
class AdminGateway;

class Driver {
private:
    friend class Gateway;
    friend class DriverGateway;
    friend class AdminGateway;

    Driver(int id, vector<int> carIds, int securityPin, double rating, const string &status, const string &name,
           const vector<int> &ordersIds);
    int id, securityPin;
    double rating;
    string status, name;
    vector<int> ordersIds, carIds;
    static json toJson(Driver driver);
    static Driver toInstance(json jsonDriver);

};


#endif //HOMEWORK4_DRIVER_H
