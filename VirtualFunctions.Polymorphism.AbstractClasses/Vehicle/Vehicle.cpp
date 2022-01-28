#include "Vehicle.hpp"
void Vehicle::copyVehicle(const Vehicle& other){
    make=new char[strlen(other.make)+1];
    assert(make!=NULL);
    strcpy(make, other.make);
    model=new char[strlen(other.model)+1];
    assert(model!=NULL);
    strcpy(model, other.model);
    color=new char[strlen(other.color)+1];
    assert(color!=NULL);
    strcpy(color, other.color);
    year=other.year;
    mileage=other.mileage;
}
Vehicle::Vehicle(){
    make=new char[strlen("Unknown")+1];
    assert(make!=NULL);
    strcpy(make, "Unknown");
    model=new char[strlen("Unknown")+1];
    assert(model!=NULL);
    strcpy(model, "Unknown");
    color=new char[strlen("Unknown")+1];
    assert(color!=NULL);
    strcpy(color, "Unknown");
    year=0;
    mileage=0;
}
Vehicle::Vehicle(const char* m, const char* mod, const char* c, int y, double mil){
    make=new char[strlen(m)+1];
    assert(make!=NULL);
    strcpy(make, m);
    model=new char[strlen(mod)+1];
    assert(model!=NULL);
    strcpy(model, mod);
    color=new char[strlen(c)+1];
    assert(color!=NULL);
    strcpy(color, c);
    year=y;
    mileage=mil;
}
Vehicle::Vehicle(const Vehicle& other){
    copyVehicle(other);
}
Vehicle& Vehicle::operator=(const Vehicle& other){
    if(this!=&other){
        delete []make;
        delete []model;
        delete []color;
        copyVehicle(other);
    }
    return *this;
}
Vehicle::~Vehicle(){
    delete []make;
    delete []model;
    delete []color;
}
const char* Vehicle::getMake() const{
    return make;
}
const char* Vehicle::getModel() const{
    return model;
}
const char* Vehicle::getColor() const{
    return color;
}
int Vehicle::getYear() const{
    return  year;
}
double Vehicle::getMileage() const{
    return mileage;
}
void Vehicle::setMake(const char* m){
    delete []make;
    make=new char[strlen(m)+1];
    assert(make!=NULL);
    strcpy(make, m);
}
void Vehicle::setModel(const char* m){
    delete []model;
    model=new char[strlen(m)+1];
    assert(model!=NULL);
    strcpy(model, m);
}
void Vehicle::setColor(const char* c){
    delete []color;
    color=new char[strlen(c)+1];
    assert(color!=NULL);
    strcpy(color, c);
}
void Vehicle::setYear(int y){
    year=y;
}
void Vehicle::setMileage(double m){
    mileage=m;
}
void Vehicle::details() const{
    cout<<"Brand: "<<getMake()<<endl;
    cout<<"Model: "<<getModel()<<endl;
    cout<<"Color: "<<getColor()<<endl;
    cout<<"Year: "<<getYear()<<endl;
    cout<<"Mileage: "<<getMileage()<<endl;
}

