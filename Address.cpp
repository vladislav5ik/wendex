//
// Created by Professional on 14.04.2021.
//

#include "Address.h"
json Address::getJson() {
    json address ={
            {"id" , this->id},
            { "title", this->title },
            { "full" , this->full },
            { "x", this->x},
            { "y", this->y }
    };
    return address;
}