#include "ElectricDevice.hpp"
void ElectricDevice::copyElectricDevice(const ElectricDevice& other){
    nameOfDevice=new char[strlen(other.nameOfDevice)+1];
    assert(nameOfDevice!=NULL);
    strcpy(nameOfDevice, other.nameOfDevice);
    electricPower=other.electricPower;
}
ElectricDevice::ElectricDevice(){
    nameOfDevice=new char[strlen("Unknown")+1];
    assert(nameOfDevice!=NULL);
    strcpy(nameOfDevice, "Unknown");
    electricPower=0;
}
ElectricDevice::ElectricDevice(const char* nD, int p){
    nameOfDevice=new char[strlen(nD)+1];
    assert(nameOfDevice!=NULL);
    strcpy(nameOfDevice, nD);
    electricPower=p;
}
ElectricDevice::ElectricDevice(const ElectricDevice& other){
    copyElectricDevice(other);
}
ElectricDevice& ElectricDevice::operator=(const ElectricDevice& other){
    if(this!=&other){
        delete []nameOfDevice;
        copyElectricDevice(other);
    }
    return *this;
}
ElectricDevice::~ElectricDevice(){
    delete []nameOfDevice;
}
const char* ElectricDevice::getnameOfDevice() const{
    return nameOfDevice;
}
int ElectricDevice::getElectricPower() const{
    return electricPower;
}
void ElectricDevice::print() const{
    cout<<nameOfDevice<<" "<<electricPower<<endl;
}
