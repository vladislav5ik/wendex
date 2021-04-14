//
// Created by Professional on 14.04.2021.
//

#include "Passenger.h"

Passenger::Passenger(int id, int securityPin, double rating, const string &name, const string &defaultPaymentMethod,
                     const vector<int> &addressesIds, const vector<int> &pinnedAddressesIds,
                     const vector<int> &ordersIds) : id(id), securityPin(securityPin), rating(rating), name(name),
                                                     defaultPaymentMethod(defaultPaymentMethod),
                                                     addressesIds(addressesIds), pinnedAddressesIds(pinnedAddressesIds),
                                                     ordersIds(ordersIds) {}

json Passenger::getJson() {
    json orders = ordersIds;
    json pinned = pinnedAddressesIds;
    json addresses = addressesIds;
    json passenger = {
            {"id", this->id},
            {"name", this->name},
            {"securityPin" , this->securityPin},
            {"rating", this->rating},
            {"addressesIds", addresses},
            {"pinnedAddressesIds" , pinned},
            {"defaultPaymentMethod", this->defaultPaymentMethod},
            {"ordersIds" , orders}
    };
    return passenger;
}