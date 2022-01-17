#include "House.hpp"
void House::copyHouse(const House& other){
    numberOfFloors=other.numberOfFloors;
    ownerName=new char[strlen(other.ownerName)+1];
    assert(ownerName!=NULL);
    strcpy(ownerName, other.ownerName);
}
House::House() : Building(){
    numberOfFloors=0;
    ownerName=new char[strlen("Unknown")+1];
    assert(ownerName!=NULL);
    strcpy(ownerName, "Unknown");
}
House::House(int h, double a, const char* addr, int nF, const char* oN) : Building(h, a, addr){
    numberOfFloors=nF;
    ownerName=new char[strlen(oN)+1];
    assert(ownerName!=NULL);
    strcpy(ownerName, oN);
}
House::House(const House& other) : Building(other){
    copyHouse(other);
}
House& House::operator=(const House& other){
    if(this!=&other){
        delete []ownerName;
        Building::operator=(other);
        copyHouse(other);
    }
    return *this;
}
House::~House(){
    delete []ownerName;
}
int House::getNumberOfFloors() const{
    return numberOfFloors;
}
const char* House::getOwnerName() const{
    return ownerName;
}
void House::setNumberOfFloors(int nF){
    numberOfFloors=nF;
}
void House::setOwnerName(const char* newOwnerName){
    delete []ownerName;
    ownerName=new char[strlen(newOwnerName)+1];
    assert(ownerName!=NULL);
    strcpy(ownerName, newOwnerName);
}
void House::print() const{
    Building::print();
    cout<<"Number of floors = "<<numberOfFloors<<endl;
    cout<<"Owner's name: "<<ownerName<<endl;
}

