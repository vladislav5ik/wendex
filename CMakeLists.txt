cmake_minimum_required(VERSION 3.17)
project(homework4)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework4 main.cpp Address.cpp Address.h Gateway.cpp Gateway.h PassengerGateway.cpp PassengerGateway.h Order.cpp Order.h Driver.cpp Driver.h Passenger.cpp Passenger.h DriverGateway.cpp DriverGateway.h Car.cpp Car.h)
