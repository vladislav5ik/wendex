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

json Passenger::toJson(Passenger passenger) {
    json orders = passenger.ordersIds;
    json pinned = passenger.pinnedAddressesIds;
    json addresses = passenger.addressesIds;
    json jsonPassenger = {
            {"id", passenger.id},
            {"name", passenger.name},
            {"securityPin" , passenger.securityPin},
            {"rating", passenger.rating},
            {"addressesIds", addresses},
            {"pinnedAddressesIds" , pinned},
            {"defaultPaymentMethod", passenger.defaultPaymentMethod},
            {"ordersIds" , orders}
    };
    return jsonPassenger;
}

Passenger Passenger::toInstance(json jsonPassenger) {
    Passenger passenger = Passenger(jsonPassenger.at("id"),
                                    jsonPassenger.at("securityPin"),
                                    jsonPassenger.at("rating"),
                                    jsonPassenger.at("name"),
                                    jsonPassenger.at("defaultPaymentMethod"),
                                    jsonPassenger.at("addressesIds"),
                                    jsonPassenger.at("pinnedAddressesIds"),
                                    jsonPassenger.at("ordersIds"));
    return passenger;
}