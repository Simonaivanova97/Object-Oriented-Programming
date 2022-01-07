#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class BankAccount{
public:
    BankAccount();
    BankAccount(const char*, const char*, double);
    BankAccount(const BankAccount&);
    BankAccount& operator=(const BankAccount&);
    ~BankAccount();
    
    const char* getClientName() const;
    void print() const;
    void depositsMoney(double);
    void withdrawMoney(double);
    
private:
    char* clientName;
    char* accountNumber;
    double amountAvailable;
    
    void copyBankAccount(const BankAccount&);
};

#endif /* BankAccount_hpp */

