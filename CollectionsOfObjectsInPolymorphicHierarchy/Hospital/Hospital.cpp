#include "Hospital.hpp"
void Hospital::copyHospital(const Hospital& other){
    maxCapacity=other.maxCapacity;
    numberDoctors=other.numberDoctors;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberDoctors;i++){
        arr[i]=other.arr[i]->clone();
    }
}
void Hospital::resize(){
    Doctor** copyArr=arr;
    maxCapacity*=2;
    //erase();
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberDoctors;i++){
        arr[i]=copyArr[i];
    }
    delete []copyArr;
}
void Hospital::erase(){
    for(int i=0;i<numberDoctors;i++){
        delete arr[i];
    }
    delete []arr;
}
Hospital::Hospital(){
    maxCapacity=0;
    numberDoctors=0;
    arr=NULL;
}
Hospital::Hospital(int c){
    maxCapacity=c;
    numberDoctors=0;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
}
Hospital::Hospital(const Hospital& other){
    copyHospital(other);
}
Hospital& Hospital::operator=(const Hospital& other){
    if(this!=&other){
        erase();
        copyHospital(other);
    }
    return *this;
}
Hospital::~Hospital(){
    erase();
}
void Hospital::print() const{
    cout<<"Max capacity of doctors: "<<maxCapacity<<endl;
    cout<<"Current number of doctors: "<<numberDoctors<<endl;
    for(int i=0;i<numberDoctors;i++){
        arr[i]->print();
        cout<<"Salary: "<<arr[i]->getSalary()<<endl;
        cout<<"==============================\n\n";
    }
}
void Hospital::addDoctor(Doctor* d){
    if(numberDoctors==maxCapacity){
        resize();
    }
    arr[numberDoctors]=d->clone();
    numberDoctors++;
}
void Hospital::removeDoctor(int salary){
    Doctor** temp=arr;
    int j=0;
    int newNumberOfDoctor=numberDoctors;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberDoctors;i++){
        if(temp[i]->getSalary()<=salary){
            arr[j]=temp[i];
            j++;
        }
        else{
            newNumberOfDoctor--;
        }
    }
    delete []temp;
    numberDoctors=newNumberOfDoctor;
}
void Hospital::removeDentist(int nP){
    Doctor** copyArr=arr;
    int j=0;
    int newNumberOfDoctor=numberDoctors;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    Dentist* d=NULL;
    for(int i=0;i<numberDoctors;i++){
        d=dynamic_cast<Dentist*>(copyArr[i]);
        if(d && d->getNumberOfPatientsExamined()<nP){
            newNumberOfDoctor--;
        }
        else{
            arr[j]=copyArr[i];
            j++;
        }
    }
    delete []copyArr;
    numberDoctors=newNumberOfDoctor;
}
void Hospital::removeSurgeon(int nO){
    Doctor** copyArr=arr;
    int j=0;
    int newNumberOfDoctor=numberDoctors;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    Surgeon* s=NULL;
    for(int i=0;i<numberDoctors;i++){
        s=dynamic_cast<Surgeon*>(copyArr[i]);
        if(s && s->getNumberOfOperations()<nO){
            newNumberOfDoctor--;
        }
        else{
            arr[j]=copyArr[i];
            j++;
        }
    }
    delete []copyArr;
    numberDoctors=newNumberOfDoctor;
}
void Hospital::removeNurse(int nP){
    Doctor** copyArr=arr;
    int j=0;
    int newNumberOfDoctor=numberDoctors;
    arr=new Doctor*[maxCapacity];
    assert(arr!=NULL);
    Nurse* n=NULL;
    for(int i=0;i<numberDoctors;i++){
        n=dynamic_cast<Nurse*>(copyArr[i]);
        if(n && n->getNumberOfPatients()<nP){
            newNumberOfDoctor--;
        }
        else{
            arr[j]=copyArr[i];
            j++;
        }
    }
    delete []copyArr;
    numberDoctors=newNumberOfDoctor;
}

