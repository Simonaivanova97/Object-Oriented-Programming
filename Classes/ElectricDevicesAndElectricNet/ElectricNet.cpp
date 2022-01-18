#include "ElectricNet.hpp"
void ElectricNet::copyElectricNet(const ElectricNet& other){
    arr=new ElectricDevice[other.numberOfDevice];
    assert(arr!=NULL);
    for(int i=0;i<other.numberOfDevice;i++){
        arr[i]=other.arr[i];
    }
    numberOfDevice=other.numberOfDevice;
    currentPower=other.currentPower;
    maxPower=other.maxPower;
}
bool ElectricNet::containsDevice(const char* devName){
    for(int i=0;i<numberOfDevice;i++){
        if(strcmp(arr[i].getnameOfDevice(), devName)==0){
            return true;
            break;
        }
    }
    return false;
}
ElectricNet::ElectricNet(){
    numberOfDevice=0;
    currentPower=0;
    maxPower=0;
    arr=NULL;
}
ElectricNet::ElectricNet(int max){
    maxPower=max;
}
ElectricNet::ElectricNet(const ElectricNet& other){
    copyElectricNet(other);
}
ElectricNet& ElectricNet::operator=(const ElectricNet& other){
    if(this!=&other){
        delete []arr;
        copyElectricNet(other);
    }
    return *this;
}
ElectricNet::~ElectricNet(){
    delete []arr;
}
void ElectricNet::operator+=(const ElectricDevice& dev){
    if(currentPower+dev.getElectricPower()<=maxPower){
        numberOfDevice++;
        ElectricDevice* copyArr=arr;
        arr=new ElectricDevice[numberOfDevice];
        assert(arr!=NULL);
        for(int i=0;i<numberOfDevice-1;i++){
            arr[i]=copyArr[i];
        }
        arr[numberOfDevice-1]=dev;
        currentPower+=dev.getElectricPower();
        copyArr=NULL;
        delete copyArr;
    }
    else{
        cout<<"Cannot add device "<<dev.getnameOfDevice()<<", because maximum power is exceeded!"<<endl;
    }
}
void ElectricNet::print()const{
    cout<<"Max power: "<<maxPower<<endl;
    cout<<"Current power: "<<currentPower<<endl;
    for(int i=0;i<numberOfDevice;i++){
        arr[i].print();
    }
}
ElectricNet& ElectricNet::operator-=(const char* devName){
    if(containsDevice(devName)){
        ElectricDevice* copyArr=arr;
        numberOfDevice--;
        arr=new ElectricDevice[numberOfDevice];
        assert(arr!=NULL);
        int i=0;
        for(i;strcmp(copyArr[i].getnameOfDevice(), devName)!=0;i++){
            arr[i]=copyArr[i];
        }
        currentPower-=copyArr[i].getElectricPower();
        int j=i+1;
        for(i;i<numberOfDevice;i++){
            arr[i]=copyArr[j];
            j++;
        }
        copyArr=NULL;
        delete copyArr;
    }
    else{
        cout<<"Device - "<<devName<<" is not in electric net!"<<endl;
    }
    return *this;
}
ElectricDevice ElectricNet::operator[](const char* devName){
    if(containsDevice(devName)){
        int i=0;
        for(i;strcmp(arr[i].getnameOfDevice(), devName)!=0;i++){
        }
        return arr[i];
    }
    else{
        cout<<"Device - "<<devName<<" is not in electric net!"<<endl;
        return ElectricDevice();
    }
}
bool ElectricNet::operator!()const{
    return currentPower>0;
}
ElectricNet& ElectricNet::operator++(){
    maxPower*=2;
    return *this;
}

