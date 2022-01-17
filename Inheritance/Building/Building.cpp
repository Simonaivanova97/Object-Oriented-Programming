#include "Building.hpp"
void Building::copyBuilding(const Building& other){
    height=other.height;
    area=other.area;
    address=new char[strlen(other.address)+1];
    assert(address!=NULL);
    strcpy(address, other.address);
}
Building::Building(){
    height=0;
    area=0.0;
    address=new char[strlen("Unknown")+1];
    assert(address!=NULL);
    strcpy(address, "Unknown");
}
Building::Building(int h, double a, const char* addr){
    height=h;
    area=a;
    address=new char[strlen(addr)+1];
    assert(address!=NULL);
    strcpy(address, addr);
}
Building::Building(const Building& other){
    copyBuilding(other);
}
Building& Building::operator=(const Building& other){
    if(this!=&other){
        delete []address;
        copyBuilding(other);
    }
    return *this;
}
Building::~Building(){
    delete []address;
}
int Building::getHeight() const{
    return height;
}
double Building::getArea() const{
    return area;
}
const char* Building::getAddress() const{
    return address;
}
void Building::setHeight(int h){
    height=h;
}
void Building::setArea(double a){
    area=a;
}
void Building::setAddress(const char* newAddress){
    delete []address;
    address=new char[strlen(newAddress)+1];
    assert(address!=NULL);
    strcpy(address, newAddress);
}
void Building::print() const{
    cout<<"Height = "<<height<<endl;
    cout<<"Area = "<<area<<endl;
    cout<<"Address: "<<address<<endl;
}
