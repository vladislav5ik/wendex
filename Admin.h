//
// Created by Professional on 26.04.2021.
//

#ifndef HOMEWORK4_ADMIN_H
#define HOMEWORK4_ADMIN_H
#include "string"
#include "json.hpp"
using namespace nlohmann;
using namespace std;
//#include "Gateway.h"

class Gateway;
class AdminGateway;
class Admin {
    friend class Gateway;
    friend class AdminGateway;
private:
    Admin(string name, int securityPin, int id);
    string name;
    int securityPin, id;
    static json toJson(Admin admin);
    static Admin toInstance(json jsonAdmin);
};


#endif //HOMEWORK4_ADMIN_H
