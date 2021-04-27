
# WEndex taxi
### What's this?
This program allows you to build relationships between drivers and passengers. Simplicity and convenience creates an entire taxi system that is scalable.
### Installation
The program uses a [json](https://github.com/nlohmann/json#stl-like-access) library which is already in the repository files, just copy them all. Use C++ 17 with standard libraries on your computer. The following lines should be included in the main file at the beginning:
``` C++
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "AdminGateway.h"
```


### How to start using?
- There are three gates in the program: for `passengers` ,`drivers` and `admins`. Further work will be conducted with them.
- Register your first users. Bind the addresses and cars to them like in example below. 
- Use a `security pin` to protect accounts
```C++
Passenger p1 = PassengerGateway::createAccount("Vladislav", 1234);
Driver d1 = DriverGateway::createAccount("Alex", 7777);
Address a1("5ka", "Innopolis, street Sportivnaya 25/1", 5.59, 55.30);
Car car("M563OP77","RED","WENDEX SELF-DRIVING","business",5.39,55.9);
```
Note that you can't manually create users, because of security reasons. You must login every time program starts to get instance.
``` C++
Passenger p1 = PassengerGateway::login("Vladislav", 1234);
```
Cars and Addresses, unlike users, are creatable. But you need to link them to users, overwise information will be loosed when program will be close. 
``` C++
Address a2("uni", "Innopolis, street University 1", 5.89,55.9);
PassengerGateway::linkAddress(p1, a2)
Car car("M563OP77","RED","WENDEX SELF-DRIVING","business",5.39,55.9);
DriverGateway::linkCar(d1,car);
```
### Detailed guide
Before you start, absolutely all data in the program is saved after each command executed. This means that the program can be turned off or used on other devices and no data is lost.

Let's take a look at the primary methods.
#### Account info

To pay for trips, select the default method of payment from the user using the method `setDefaultPaymentMethod`
``` C++
PassengerGateway::setDefaultPaymentMethod(p1, "card");
```
At the driver, don't forget to switch status.
``` C++
DriverGateway::setStatus(d1, "free");
DriverGateway::setStatus(d1, "in ride");
```
One driver can have multiple cars, they can see all theirs cars with method `seeCars`.
```C++
DriverGateway::seeCars(d1);
```

All users can see their order history with method `getOrderHistory`.
```c++
DriverGateway::getOrderHistory(d1);
PassengerGateway::getOrderHistory(p1);
```

Admin have grant to all information in the system with method `seeAllData.`
```c++
AdminGateway::seeAllData(adm);
```
Also all saved data can be erased with method `reset`. Be careful using it.
```c++
Gateway::reset();
```
####  Adresses
The address includes the `title`, the `full` street name, and the `x` and `y` coordinates
To store it in the database, you need to attach this address to someone's account using the `linkAddress` method.
 ```C++
Address a2("uni", "Innopolis, street University 1", 5.89,55.9);
```
Addresses can be displayed on the screen to see full information about them. For convenience, the address can be `pinned`, so that it is faster to find it among the others.
```C++
PassengerGateway::linkAddress(p1, a2);
PassengerGateway::unPinAddress(p1,a1);
PassengerGateway::getAddresses(p1);
PassengerGateway::getPinnedAddresses(p1);
```
####  Cars
The cars parameters are
- `carType`, can be Business, Comfort, ComfortPlus, and Economy. Cost depends upon that parameter.
- `number` is unique string.
- `model`, `color`, `freeBottleOfWater`, coordinates `x` and `y`.

Cars should be **validated** by Admin after creation to take any order.
```c++
AdminGateway::blockCar(adm,car);
AdminGateway::validateCar(adm, car);
```
#### Ordering a Taxi
Method is called `addOrder`. The user needs to specify the departure and destination points and car type.
```C++
PassengerGateway::addOrder(p1,a1,a2,"business");
```
After that, order will be places in order wheel among drivers.
Driver have method `getOrder`, that uses interaction with console. Driver can choose order they want or discard.
```C++
DriverGateway::getOrder(d1);
```
- If driver's interests equal to passenger's interests, system sent to passenger notification about matching.
- In the end of the ride, user can leave feedback, changing drivers's rating.
- Immediately after the trip, both parties can see the order history that is saved in file.

#### Error handling
Some methods may give rise to unavoidable errors. For example, if two users want to choose the same name in the system. Or if the user entered the data such as wrong pin code.
There are three types of errors in the program: `notFound`, `alreadyExists` and `loginError`.

Examples:
```c++
try {
    Passenger p1 = PassengerGateway::createAccount("Vladislav", 1234);
    Passenger p2 = PassengerGateway::createAccount("Vladislav", 4321);
} catch (alreadyExists& e) { //same name
    cout << e.what();
}

try {
    d1 = DriverGateway::login("Alex", 5656);
} catch (loginError& e) { //incorrect security pin
    cout << e.what();
}

try {
    Driver d2 = DriverGateway::login("Max", 1111);
} catch (notFound& e) { //not registered
    cout << e.what();
}
```
Try to use error interceptors everywhere.

*Enjoy using the program!*
