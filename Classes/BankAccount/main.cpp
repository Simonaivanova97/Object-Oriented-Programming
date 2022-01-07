
#include <iostream>
#include "BankAccount.hpp"
using namespace std;

int main(){
    BankAccount b1("Petya","BG123456789",1654.89);
    BankAccount b2("Atanas","BG987654321",593.25);
    b1.print();
    b2.print();

    cout<<"\nFirst transaction of "<<b1.getClientName()<<endl;
    b1.depositsMoney(0);
    b1.print();
    cout<<"\nSecond transaction of "<<b1.getClientName()<<endl;
    b1.depositsMoney(150);
    b1.print();
        
    cout<<"\nFirst transaction of "<<b2.getClientName()<<endl;
    b2.withdrawMoney(0);
    b2.print();
    cout<<"\nSecond transaction of "<<b2.getClientName()<<endl;
    b2.withdrawMoney(594);
    b2.print();
    cout<<"\nThirth transaction of "<<b2.getClientName()<<endl;
    b2.withdrawMoney(150);
    b2.print();
        
    return 0;
}
