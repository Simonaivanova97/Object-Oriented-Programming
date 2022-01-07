#include "BankAccount.hpp"

void BankAccount::copyBankAccount(const BankAccount& other){
    clientName=new char[strlen(other.clientName)+1];
    assert(clientName!=NULL);
    strcpy(clientName, other.clientName);
    accountNumber=new char[strlen(other.accountNumber)+1];
    assert(accountNumber!=NULL);
    strcpy(accountNumber, other.accountNumber);
    amountAvailable=other.amountAvailable;
}
BankAccount::BankAccount(){
    clientName=new char[strlen("Unknown")+1];
    assert(clientName!=NULL);
    strcpy(clientName, "Unknown");
    accountNumber=new char[strlen("Unknown")+1];
    assert(accountNumber!=NULL);
    strcpy(accountNumber, "Unknown");
    amountAvailable=0;
}
BankAccount::BankAccount(const char* cN, const char* aN, double a){
    clientName=new char[strlen(cN)+1];
    assert(clientName!=NULL);
    strcpy(clientName, cN);
    accountNumber=new char[strlen(aN)+1];
    assert(accountNumber!=NULL);
    strcpy(accountNumber, aN);
    amountAvailable=a;
}
BankAccount::BankAccount(const BankAccount& other){
    copyBankAccount(other);
}
BankAccount& BankAccount::operator=(const BankAccount& other){
    if(this!=&other){
        delete []clientName;
        delete []accountNumber;
        copyBankAccount(other);
    }
    return *this;
}
BankAccount::~BankAccount(){
    delete []clientName;
    delete []accountNumber;
}
const char* BankAccount::getClientName() const{
    return clientName;
}
void BankAccount::print() const{
    cout<<"Client name is: "<<clientName<<endl;
    cout<<"Account number: "<<accountNumber<<endl;
    cout<<"Amount available: "<<amountAvailable<<endl;
}
void BankAccount::depositsMoney(double money){
    if(money>0){
        amountAvailable+=money;
    }
    else{
        cout<<"Invalid transaction!"<<endl;
    }
}
void BankAccount::withdrawMoney(double money){
    if(money>=amountAvailable || money==0){
        cout<<"Invalid transaction!"<<endl;
    }
    else{
        amountAvailable-=money;
    }
}

