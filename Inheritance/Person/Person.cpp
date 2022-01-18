#include "Person.hpp"
void Person::copyPerson(const Person& other){
    forename=new char[strlen(other.forename)+1];
    assert(forename!=NULL);
    strcpy(forename, other.forename);
    lastname=new char[strlen(other.lastname)+1];
    assert(lastname!=NULL);
    strcpy(lastname, other.lastname);
    age=other.age;
}
Person::Person(){
    forename=new char[strlen("Unknown")+1];
    assert(forename!=NULL);
    strcpy(forename, "Unknown");
    lastname=new char[strlen("Unknown")+1];
    assert(lastname!=NULL);
    strcpy(lastname, "Unknown");
    age=0;
}
Person::Person(const char* fN, const char* lN, int a){
    forename=new char[strlen(fN)+1];
    assert(forename!=NULL);
    strcpy(forename, fN);
    lastname=new char[strlen(lN)+1];
    assert(lastname!=NULL);
    strcpy(lastname, lN);
    age=a;
}
Person::Person(const Person& other){
        copyPerson(other);
}
Person& Person::operator=(const Person& other){
    if(this!=&other){
        delete []forename;
        delete []lastname;
        copyPerson(other);
    }
    return *this;
}
Person::~Person(){
    delete []forename;
    delete []lastname;
}
void Person::print() const{
    cout<<"Name: "<<forename<<" "<<lastname<<endl;
    cout<<"Age: "<<age<<endl;
}
