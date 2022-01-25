#include "Manager.hpp"
void Manager::copyManager(const Manager& other){
    maxSubordinate=other.maxSubordinate;
    currentSubordinate=other.currentSubordinate;
    arr=new Employee*[maxSubordinate];
    assert(arr!=NULL);
    for(int i=0;i<currentSubordinate;i++){
        arr[i]=other.arr[i]->clone();
    }
}
void Manager::erase(){
    for(int i=0;i<currentSubordinate;i++){
        delete arr[i];
    }
    delete []arr;
}
bool Manager::havaSubordinate(const char* n) const{
    for(int i=0;i<currentSubordinate;i++){
        if(strcmp(n, arr[i]->getName())==0){
            return true;
        }
    }
    return false;
}
Manager::Manager() : Employee() {
    maxSubordinate=5;
    currentSubordinate=0;
    arr=new Employee*[maxSubordinate];
    assert(arr!=NULL);
}
Manager::Manager(const char* n, int nT, int sT, Employee** a, int cS, int mS) : Employee(n, nT, sT){
    maxSubordinate=mS;
    currentSubordinate=cS;
    arr=new Employee*[maxSubordinate];
    assert(arr!=NULL);
    for(int i=0;i<currentSubordinate;i++){
        arr[i]=a[i]->clone();
    }
}
Manager::Manager(const Manager& other) : Employee(other){
    copyManager(other);
}
Manager& Manager::operator=(const Manager& other){
    if(this!=&other){
        erase();
        Employee::operator=(other);
        copyManager(other);
    }
    return *this;
}
Manager::~Manager(){
    erase();
}

bool Manager::execute(const char* task){
    int minIndex=0;
    int min=arr[0]->getNumberOfExecuteTasks();
    for(int i=0;i<currentSubordinate;i++){
        if(arr[i]->getNumberOfExecuteTasks()<min){
            min=arr[i]->getNumberOfExecuteTasks();
            minIndex=i;
        }
    }
    numberOfExecuteTasks++;
    if(arr[minIndex]->execute(task)){
        successfullyCompletedTasks++;
        return true;
    }
    else{
        return false;
    }
}
double Manager::successRate() const{
    if(numberOfExecuteTasks==0){
        return 0;
    }
    return (double)successfullyCompletedTasks/numberOfExecuteTasks;
}
Employee* Manager::clone(){
    return new Manager(*this);
}
void Manager::print() const{
    cout<<*this;
}
void Manager::printStatus() const{
    cout<<"The success of all subordinates of the manager: "<<getName()<<endl;
    for(int i=0;i<currentSubordinate;i++){
        cout<<arr[i]->getName()<<" successRate: "<<arr[i]->successRate()<<endl;
    }
}
void Manager::addSubordinate(Employee* e){
    if(currentSubordinate==maxSubordinate){
        Employee** copyArr=arr;
        maxSubordinate*=2;
        arr=new Employee*[maxSubordinate];
        for(int i=0;i<currentSubordinate;i++){
            arr[i]=copyArr[i]->clone();
        }
        for(int i=0;i<currentSubordinate;i++){
            delete copyArr[i];
        }
        delete []copyArr;
    }
    arr[currentSubordinate]=e->clone();
    currentSubordinate++;
}
void Manager::deleteSubordinate(const char* name){
    if(havaSubordinate(name)){
        Employee** copyArr=new Employee*[currentSubordinate-1];
        assert(copyArr!=NULL);
        int j=0;
        for(int i=0;i<currentSubordinate;i++){
            if(strcmp(arr[i]->getName(),name)!=0){
                copyArr[j]=arr[i]->clone();
                j++;
            }
        }
        erase();
        currentSubordinate--;
        arr=new Employee*[maxSubordinate];
        assert(arr!=NULL);
        for(int i=0;i<currentSubordinate;i++){
            arr[i]=copyArr[i]->clone();
        }
        for(int i=0;i<currentSubordinate;i++){
            delete copyArr[i];
        }
        delete []copyArr;
    }
    else{
        cout<<"Employee "<<name<<" is not subodinate of "<<getName()<<endl;
    }
}
ostream& operator<<(ostream& out, const Manager& m){
    out<<"manager: "<<m.currentSubordinate<<" "<<m.getName()<<endl;
    for(int i=0;i<m.currentSubordinate;i++){
        m.arr[i]->print();
    }
    return out;
}
void Manager::readAndExecuteTasksFromFile(const char* fileName){
    fstream myFile(fileName, ios::in);
    string tempRow;
    while(getline(myFile, tempRow)){
        if(execute(tempRow.c_str())){
            cout<<"Task: \""<<tempRow<<"\" successfully completed!"<<endl;
        }
        else{
            cout<<"Task: "<<tempRow<<" NOT successfully completed!"<<endl;
        }
    }
    myFile.close();
}
