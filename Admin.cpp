//
// Created by Professional on 26.04.2021.
//

#include "Admin.h"
Admin::Admin(string name, int securityPin, int id) {
    this->name = name;
    this->securityPin = securityPin;
    this->id = id;
}
json Admin::toJson(Admin admin) {
    json jsonAdmin = {
            {"name", admin.name},
            {"securityPin" , admin.securityPin},
            {"id",admin.id}
    };
    return jsonAdmin;
}

Admin Admin::toInstance(json jsonAdmin) {
    Admin admin = Admin(jsonAdmin.at("name"),jsonAdmin.at("securityPin"), jsonAdmin.at("id"));
    return admin;
}