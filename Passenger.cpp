//
// Created by Professional on 14.04.2021.
//

#include "Passenger.h"
json Passenger::getJson() {
    json orders = json::parse(this->ordersIds.begin(), this->ordersIds.end());
    json pinned = json::parse(this->pinnedAddressesIds.begin(), this->pinnedAddressesIds.end());
    json addresses = json::parse(this->addressesIds.begin(), this->addressesIds.end());
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