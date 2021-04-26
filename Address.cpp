//
// Created by Professional on 14.04.2021.
//

#include "Address.h"

Address::Address(const string &title, const string &full, double x, double y) {
    this->id = -1; //id updates only if address is saved in database
    this->title = title;
    this->full = full;
    this->x = x;
    this->y = y;
}

json Address::toJson(Address address) {
    json jsonAddress = {
            {"id" , address.id},
            { "title", address.title },
            { "full" , address.full },
            { "x", address.x},
            { "y", address.y }
    };
    return jsonAddress;
}

Address Address::toInstance(json jsonAddress) {
    Address address(jsonAddress.at("title"),
                    jsonAddress.at("full"),
                    jsonAddress.at("x"),
                    jsonAddress.at("y"));
    address.id = jsonAddress.at("id");
    return address;
}