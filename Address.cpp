//
// Created by Professional on 14.04.2021.
//

#include "Address.h"

Address::Address(const string &title, const string &full, double x, double y) {
    this->id = -1;
    this->title = title;
    this->full = full;
    this->x = x;
    this->y = y;
}

json Address::getJson() {
    json address = {
            {"id" , this->id},
            { "title", this->title },
            { "full" , this->full },
            { "x", this->x},
            { "y", this->y }
    };
    return address;
}