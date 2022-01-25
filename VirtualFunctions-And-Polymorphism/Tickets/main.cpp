#include <iostream>
#include "Ticket.hpp"
#include "DiscountedTicket.hpp"
#include "GroupTicket.hpp"
using namespace std;

void arrTickets(Ticket** arr, int numberOfTickets){
    int numberOfSpectators=0;
    for(int i=0;i<numberOfTickets;i++){
        numberOfSpectators+=arr[i]->howManySpectators();
    }
    cout<<"Number of spectators: "<<numberOfSpectators<<endl;
    
    double sumOfTickets=0;
    for(int i=0;i<numberOfTickets;i++){
        if(arr[i]->howManySpectators()>1){
            sumOfTickets+=arr[i]->howManySpectators()*arr[i]->getPrice();
        }
        else{
            sumOfTickets+=arr[i]->getPrice();
        }
    }
    cout<<"Sum of all tickets: "<<sumOfTickets<<endl;
}

int main() {
    Ticket t1("Vazov's people",50);
    DiscountedTicket d1("Vazov's people",50);
    GroupTicket g1("Vazov's people",50,22);

    Ticket* allTypesOfTickets[3]={&t1, &d1, & g1};
    arrTickets(allTypesOfTickets, 3);
    return 0;
}
