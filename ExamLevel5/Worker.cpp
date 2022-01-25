#include "Worker.hpp"
Worker::Worker() : Employee(){
    k=0;
    currentExecuteTasks=0;
}
Worker::Worker(const char* n, int nT, int sT, int valueForK) : Employee(n, nT, sT){
    k=valueForK;
    currentExecuteTasks=0;
}
bool Worker::execute(const char* task){
    currentExecuteTasks++;
    numberOfExecuteTasks++;
    if(currentExecuteTasks==k){
        currentExecuteTasks=0;
        return false;
    }
    else{
        successfullyCompletedTasks++;
        return true;
    }
}
double Worker::successRate() const{
    if(numberOfExecuteTasks==0){
        return 0;
    }
    return (double)successfullyCompletedTasks/numberOfExecuteTasks;
}
void Worker::print() const{
    cout<<*this<<endl;
}
Employee* Worker::clone(){
    return new Worker(*this);
}
ostream& operator<<(ostream& out , const Worker& w){
    out<<"worker: "<<w.k<<" "<<w.getName();
    return out;
}

