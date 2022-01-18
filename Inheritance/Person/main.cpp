#include <iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Worker.hpp"
using namespace std;

int main() {
    Person petya("Penya", "Atanasova", 21);
    petya.print();
    cout<<"\n--------------------"<<endl;
    
    Student georgi("Georgi", "Georgiev", 20, "Computer science",4.32);
    georgi.print();
    cout<<"\n--------------------"<<endl;

    Worker nina("Nina", "Dobreva", 28, 9.78, 128);
    nina.print();
    return 0;
}
