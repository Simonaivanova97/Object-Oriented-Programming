#include "Company.hpp"
void Company::copyCompany(const Company& other){
    maxCapacity=other.maxCapacity;
    numberOfEmployees=other.numberOfEmployees;
    arr=new Employee*[maxCapacity];
    assert(arr!=NULL);
    for(int i=0;i<numberOfEmployees;i++){
        arr[i]=other.arr[i]->clone();
    }
}
void Company::erase(){
    for(int i=0;i<numberOfEmployees;i++){
        delete arr[i];
    }
    delete []arr;
}
void Company::resize(){
    maxCapacity*=2;
    Employee** copyArr=arr;
    arr=new Employee*[maxCapacity];
    for(int i=0;i<numberOfEmployees;i++){
        arr[i]=copyArr[i];
    }
    delete []copyArr;
}
bool Company::containsEmployee(const char* name){
    for(int i=0;i<numberOfEmployees;i++){
        if(strcmp(arr[i]->getName(), name)==0){
            return true;
        }
    }
    return false;
}
Company::Company(){
    maxCapacity=0;
    numberOfEmployees=0;
    arr=NULL;
}
Company::Company(int capacity){
    maxCapacity=capacity;
    numberOfEmployees=0;
    arr=new Employee*[maxCapacity];
}
Company::Company(const Company& other){
    copyCompany(other);
}
Company& Company::operator=(const Company& other){
    if(this!=&other){
        erase();
        copyCompany(other);
    }
    return *this;
}
Company::~Company(){
    erase();
}
void Company::print() const{
    cout<<"Max number of employees: "<<maxCapacity<<endl;
    cout<<"Current number of employees "<<numberOfEmployees<<endl;
    for(int i=0;i<numberOfEmployees;i++){
        cout<<"==============================\n";
        arr[i]->print();
    }
}
void Company::addEmployee(Employee* e){
    if(numberOfEmployees==maxCapacity){
        resize();
    }
    arr[numberOfEmployees]=e->clone();
    numberOfEmployees++;
}
void Company::removeEmployee(const char* name){
    if(containsEmployee(name)){
        Employee** temp=arr;
        int j=0;
        arr=new Employee*[maxCapacity];
        assert(arr!=NULL);
        for(int i=0;i<numberOfEmployees;i++){
            if(strcmp(temp[i]->getName(), name)!=0){
                arr[j]=temp[i];
                j++;
            }
        }
        numberOfEmployees--;
        delete []temp;
    }
}
void Company::removeNewEmployee(){
    for(int i=0;i<numberOfEmployees;i++){
        if(arr[i]->getExperience()<3){
            removeEmployee(arr[i]->getName());
            i--;
        }
    }
}
double Company::sumSalaries() const{
    double sum=0;
    for(int i=0;i<numberOfEmployees;i++){
        sum+=arr[i]->getSalary();
    }
    return sum;
}
double Company::avgSalary() const{
    return sumSalaries()/numberOfEmployees;
}
void Company::removeHTMLProgrammer(){
    Programmer* ptr=NULL;
    for(int i=0;i<numberOfEmployees;i++){
        ptr=dynamic_cast<Programmer*>(arr[i]);
        if(ptr && strcmp(ptr->getProgrammingLanguage(), "HTML && CSS")==0){
            removeEmployee(arr[i]->getName());
            i--;
        }
    }
}

