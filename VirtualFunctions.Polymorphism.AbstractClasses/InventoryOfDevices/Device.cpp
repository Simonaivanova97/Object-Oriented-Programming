#include "Device.hpp"
void Device::copyDevice(const Device& other){
    manufacturer=new char[strlen(other.manufacturer)+1];
    assert(manufacturer!=NULL);
    strcpy(manufacturer, other.manufacturer);
}
Device::Device(){
    manufacturer=new char[strlen("Unknown")+1];
    assert(manufacturer!=NULL);
    strcpy(manufacturer, "Unknown");
}
Device::Device(const char* m){
    manufacturer=new char[strlen(m)+1];
    assert(manufacturer!=NULL);
    strcpy(manufacturer, m);
}
Device::Device(const Device& other){
    copyDevice(other);
}
Device& Device::operator=(const Device& other){
    if(this!=&other){
        delete []manufacturer;
        copyDevice(other);
    }
    return *this;
}
Device::~Device(){
    delete []manufacturer;
}
void Device::print() const{
    cout<<"Manufacturer: "<<manufacturer<<endl;
}

