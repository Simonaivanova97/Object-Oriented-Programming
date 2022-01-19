#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Truck.hpp"
#include "Motocycle.hpp"
using namespace std;

int main() {
    Car car1("Toyota", "corolla", "gray", 2003, 10200);
    car1.details();
    cout<<"\n--------------------\n";
    
    Truck truck1("Mercedes","actros", "white", 2006, 50967, 6867);
    truck1.details();
    cout<<"\n--------------------\n";

    Motocycle motocycle1("Aprilia", "RSV4", "red", 2021, 9786, "Chopper");
    motocycle1.details();
    
    return 0;
}
