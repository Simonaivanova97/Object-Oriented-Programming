#include <iostream>
using namespace std;

class Employee{
public:
    void read();
    void print()const;
private:
    struct{
        char first[21];
        char last[21];
    } name;
    
    struct{
        int hours;
        double salary;
    } work;
};
void Employee::read(){
    cout<<"Enter first name: ";
    cin>>name.first;
    cout<<"Enter last name: ";
    cin>>name.last;
    cout<<"Enter hours: ";
    cin>>work.hours;
    cout<<"Enter salary: ";
    cin>>work.salary;
}
void Employee::print()const{
    cout<<"Employee "<<name.first<<" "<<name.last<<" receives the following salary: "<<work.hours*work.salary<<endl;
}
int main() {
    Employee e;
    e.read();
    e.print();
    return 0;
}
