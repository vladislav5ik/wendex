
# WEndex taxi
### What's this?
This program allows you to build relationships between drivers and passengers. Simplicity and convenience creates an entire taxi system that is scalable.
### Installation
The program uses a [json](https://github.com/nlohmann/json#stl-like-access) library which is already in the repository files, just copy them all. Use C++ 17 with standard libraries on your computer. The following lines should be included in the main file at the beginning:
``` C++
#include "PassengerGateway.h"  
#include "DriverGateway.h"  
  
using namespace std;
```


### How to start using?
- There are two gates in the program: for `passengers` and for `drivers`. Further work will be conducted with them.
- When creating instances of gates, specify the names of the files where the data will be saved. These should be json files.
``` C++
DriverGateway driveApp = DriverGateway("users.json", "orders.json", "addresses.json", "cars.json"); 
PassengerGateway userApp = PassengerGateway("users.json", "orders.json", "addresses.json", "cars.json");
```
- Register your first users and drivers. Bind the addresses and cars to them accordingly. 
- Use a `security pin` to protect accounts
```C++
Passenger studentka = userApp.createAccount("Anna K.", 123);  
  
Address a = Address("University", "Innopolis, University st. 1", 123, 456);  
Address b = Address("5ka", "Innopolis, Sportivnaya 152", 120, 450);
userApp.addAddress(studentka, a);  
userApp.addAddress(studentka, b);
```
```C++
Car myBusinessCar = driveApp.createCar("white", "WEndex self-driving", "a404ru", "Business");  
Driver drifter = driveApp.createAccount("Drifter Driftovich", myBusinessCar, 1234);
```
### Detailed guide 
Let's take a look at the primary methods.
#### Account info
After registering, if you wish, you can set up a sign-in to your account using the `login` method.
``` C++
if (userApp.login(studentka, 123))
{ ... }
```
To pay for trips, select the default method of payment from the user using the method `setDefaultPaymentMethod`
``` C++
userApp.setDefaultPaymentMethod(studentka, "card");
```
At the driver, don't forget to switch status 
``` C++
driveApp.setStatus(drifter, "in ride");
driveApp.setStatus(drifter, "Ready to work!");
```
####  Adresses
- The address includes the `title`, the `full` street name, and the `x` and `y` coordinates
- To store it in the database, you need to attach this address to someone's account using the `addAddress` method.
 ```C++
Address a = Address("University", "Innopolis, University st. 1", 123, 456);
userApp.addAddress(studentka, a); 
```
Addresses can be displayed on the screen to see full information about them. For convenience, the address can be `pinned`, so that it is faster to find it among the others.
```C++
userApp.pinAddress(studentka, a);
userApp.getAddresses(studentka);
userApp.getPinnedAddresses(studentka);
userApp.unPinAddress(studentka, a);
```
#### Ordering a Taxi
Method is called `orderTaxi`. The user needs to specify the departure and destination points and one of four car `types`: *Economy, Comfort,
ComfortPlus, Business*
```C++
Order order = userApp.orderTaxi(studentka, a, b, "Business");
```
The result of the method call should be stored in an instance of the `Order` class. The driver will be able to accept the order using `getOrder` method.
```C++
driveApp.getOrder(drifter, order);
```
- Driver and passenger ratings are randomly selected, as well as point coordinates.
- Immediately after the trip, both parties can see the order history using the getOrderHistory method
```C++
userApp.getOrderHistory(studentka);
driveApp.getOrderHistory(drifter);
```
*Enjoy using the program!*
