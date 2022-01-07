#include <iostream>
using namespace std;

struct Person{
    char foreName[16];
    char lastName[16];
};

struct Client{
    Person name;
    char bankAccount[16];
    double amount;
};

void readPerson(Person& n){
    cout<<"Forename: ";
    cin>>n.foreName;
    cout<<"Last name: ";
    cin>>n.lastName;
}

void printPerson(const Person& n){
    cout<<n.foreName<<" "<<n.lastName<<endl;
}

void readClient(Client& c){
    readPerson(c.name);
    cout<<"Bank account: ";
    cin>>c.bankAccount;
    cout<<"Amount: ";
    cin>>c.amount;
    cout<<endl;
}

void printClient(const Client& c){
    printPerson(c.name);
    cout<<"Bank account: "<<c.bankAccount<<endl;
    cout<<"Amount: "<<c.amount<<endl;
}

int main() {

    Client arr[20];
    
    int numberOfClient;
    cout<<"Number of clients?: ";
    cin>>numberOfClient;
    
    for(int i=0;i<numberOfClient;i++){
        readClient(arr[i]);
    }
    
    for(int i=0;i<numberOfClient;i++){
        printClient(arr[i]);
    }
    
    double sum=0;
    for(int i=0;i<numberOfClient;i++){
        if(arr[i].amount<0){
            sum+=arr[i].amount;
        }
    }
    cout<<sum<<endl;
    return 0;
}
