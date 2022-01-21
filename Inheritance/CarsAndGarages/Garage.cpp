#include "Garage.hpp"
void Garage::copyGarage(const Garage& other){
    name=new char[strlen(other.name)+1];
    assert(name!=NULL);
    strcpy(name, other.name);
    currentNumberOfCar=other.currentNumberOfCar;
    maxNumberOfCar=other.maxNumberOfCar;
    arr=new Car[maxNumberOfCar];
    assert(arr!=NULL);
    for(int i=0;i<currentNumberOfCar;i++){
        arr[i]=other.arr[i];
    }
}
bool Garage::containsCar(const char* serialN) const{
    for(int i=0;i<currentNumberOfCar;i++){
        if(strcmp(arr[i].getSerialNumber(), serialN)==0){
            return true;
            break;
        }
    }
    return false;
}
Garage::Garage(){
    name=new char[strlen("Unknown")+1];
    assert(name!=NULL);
    strcpy(name, "Unknown");
    currentNumberOfCar=0;
    maxNumberOfCar=0;
    arr=NULL;
}
Garage::Garage(const char* n, int currentN, int maxN, const Car* a){
    name=new char[strlen(n)+1];
    assert(name!=NULL);
    strcpy(name, n);
    currentNumberOfCar=currentN;
    maxNumberOfCar=maxN;
    arr=new Car[maxNumberOfCar];
    assert(arr!=NULL);
    for(int i=0;i<currentNumberOfCar;i++){
        arr[i]=a[i];
    }
}
Garage::Garage(const Garage& other){
    copyGarage(other);
}
Garage& Garage::operator=(const Garage& other){
    if(this!=&other){
        delete []name;
        delete []arr;
        copyGarage(other);
    }
    return *this;
}
Garage::~Garage(){
    delete []name;
    delete []arr;
}
void Garage::addCar(const Car& c){
    if(currentNumberOfCar+1>maxNumberOfCar){
        //cout<<"Garage is full. Resize garage capacity!"<<endl;
        Car* copyArr=arr;
        if(maxNumberOfCar==0){
            maxNumberOfCar=1;
        }
        else{
            maxNumberOfCar*=2;
        }
        arr=new Car[maxNumberOfCar];
        assert(arr!=NULL);
        for(int i=0;i<currentNumberOfCar;i++){
            arr[i]=copyArr[i];
        }
        copyArr=NULL;
        delete []copyArr;
    }
    arr[currentNumberOfCar]=c;
    currentNumberOfCar++;
}
void Garage::removeCar(const char* serialN){
    if(containsCar(serialN)){
        int indexCar=0;
        while(strcmp(arr[indexCar].getSerialNumber(), serialN)!=0){
            indexCar++;
        }
        int i=indexCar;
        indexCar++;
        for(indexCar;indexCar<currentNumberOfCar;indexCar++){
            arr[i]=arr[indexCar];
            i++;
        }
        currentNumberOfCar--;
    }
}
int Garage::getCurrentNmberOfCar() const{
    return currentNumberOfCar;
}
Car Garage::operator[](int index){
    if(index<=currentNumberOfCar){
        return arr[index-1];
    }
    else{
        cout<<"Car with this index, not found!"<<endl;
        return Car();
    }
}
void Garage::print()const{
    cout<<"========== "<<name<<" ==========\n"<<endl;
    cout<<"Max number of cars in garage: "<<maxNumberOfCar<<endl;
    cout<<"Current number of cars in garage: "<<currentNumberOfCar<<endl;
    cout<<"\n------------------------------"<<endl;
    for(int i=0;i<currentNumberOfCar;i++){
        arr[i].print();
        cout<<"------------------------------"<<endl;
    }
}
