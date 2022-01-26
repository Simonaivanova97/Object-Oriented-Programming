#include "Car.hpp"
int Car::nextId=0;

void Car::copyCar(const Car& other){
    model=new char[strlen(other.model)+1];
    assert(model!=NULL);
    strcpy(model, other.model);
    maxSpeed=other.maxSpeed;
    year=other.year;
    id=other.id;
    string s=to_string(id);
    serialNumber=new char[strlen(model)+s.length()+1];
    assert(serialNumber!=NULL);
    strcpy(serialNumber, model);
    int j=0;
    for(int i=strlen(model);i<strlen(model)+s.length()+1;i++){
        serialNumber[i]=s[j];
        j++;
    }
}
Car::Car() {
    id=++nextId;
    model=NULL;
    maxSpeed=0;
    year=0;
    serialNumber=NULL;
}
Car::Car(const char* m, int maxS, int y){
    model=new char[strlen(m)+1];
    assert(model!=NULL);
    strcpy(model, m);
    maxSpeed=maxS;
    year=y;
    id=++nextId;
    string s=to_string(id);
    serialNumber=new char[strlen(model)+s.length()+1];
    assert(serialNumber!=NULL);
    strcpy(serialNumber, model);
    int j=0;
    for(int i=strlen(model);i<strlen(model)+s.length()+1;i++){
        serialNumber[i]=s[j];
        j++;
    }
}
Car::Car(const Car& other){
    copyCar(other);
}
Car& Car::operator=(const Car& other){
    if(this!=&other){
        delete []model;
        delete []serialNumber;
        copyCar(other);
    }
    return *this;
}
Car::~Car(){
    delete []model;
    delete []serialNumber;
}
bool Car::operator<(const Car& c) const{
    return maxSpeed<c.maxSpeed;
}
void Car::print() const{
    if(model!=NULL){
        cout<<"Model: "<<model<<endl;
        cout<<"Max speed: "<<maxSpeed<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Serial number: "<<serialNumber<<endl;
    }
}
void Car::read(){
    if(model!=NULL){
        cout<<"Already constructed valid vehicle!"<<endl;
        return;
    }
    char buffer[1024];
    cout<<"Enter car model: ";
    cin.getline(buffer, 1024);
    model=new char[strlen(buffer)+1];
    strcpy(model, buffer);
    cout<<"Enter max speed: ";
    cin>>maxSpeed;
    cout<<"Enter year: ";
    cin>>year;
    string s=to_string(id);
    serialNumber=new char[strlen(model)+s.length()+1];
    assert(serialNumber!=NULL);
    strcpy(serialNumber, model);
    int j=0;
    for(int i=strlen(model);i<strlen(model)+s.length()+1;i++){
        serialNumber[i]=s[j];
        j++;
    }
}
const char* Car::getModel() const{
    return model;
}
int Car::getMaxSpeed() const{
    return maxSpeed;
}
int Car::getYear() const{
    return year;
}
const char* Car::getSerialNumber() const{
    return serialNumber;
}

