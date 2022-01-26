#include <iostream>
#include "Car.hpp"
#include "Garage.hpp"
using namespace std;
    
void sortArrayOfCars(Car* arr, int numberOfCars){
    Car min;
    for(int i=0;i<numberOfCars-1;i++){
        int positionMin=i;
        for(int j=i+1;j<numberOfCars;j++){
            if(arr[j]<arr[positionMin]){
                positionMin=j;
            }
        }
        Car temp=arr[i];
        arr[i]=arr[positionMin];
        arr[positionMin]=temp;
    }
}

int main() {
    
    int n;
    cout<<"Entev value for n: ";
    cin>>n;
    cin.ignore();
    
    int sizeArrFastCars=n/2, sizeArrSlowCars;
    if(n%2==0){
        sizeArrSlowCars=n/2;
    }
    else{
        sizeArrSlowCars=n/2+1;
    }
    
    Car* arr=new Car[n];
    for(int i=0;i<n;i++){
        arr[i].read();
        cin.ignore();
    }
    sortArrayOfCars(arr, n);

    Garage g1("Garage with slow cars", 0,sizeArrSlowCars,NULL);
    Garage g2("Garage with fast cars", 0,sizeArrFastCars,NULL);
    int i;
    for(i=0;i<sizeArrSlowCars;i++){
        g1.addCar(arr[i]);
    }
    for(int j=0;j<sizeArrFastCars;j++){
        g2.addCar(arr[i]);
        i++;
    }
    arr=NULL;
    delete []arr;
    
    cout<<endl;
    g1.print();
    cout<<endl<<endl;
    g2.print();
    cout<<endl<<endl;
    
    int numberOldCars=0;
    for(int i=0;i<sizeArrFastCars;i++){
        if(g2[i+1].getYear()<2005){
            numberOldCars++;
        }
    }
    
    Garage g3=Garage("Garage with fast but old cars", 0, numberOldCars, NULL);
    if(numberOldCars!=0){
        for(int i=0;i<sizeArrFastCars;i++){
            if(g2[i+1].getYear()<2005){
                g3.addCar(g2[i+1]);
            }
        }
        i=0;
        while(i<g2.getCurrentNmberOfCar()){
            if(g2[i+1].getYear()<2005){
                g2.removeCar(g2[i+1].getSerialNumber());
                i=0;
            }
            else{
                i++;
            }
        }
    }
    
    g3.print();
    cout<<endl<<endl;
    g2.print();
    
    /*Car c1("Toyota corolla verso", 240, 2008);
    c1.print();
    cout<<"\n--------------------\n";

    Car c2("Toyota corolla", 220, 2003);
    c2.print();
    cout<<"\n--------------------\n";

    Car c3("Ford focus", 220, 2000);
    c3.print();
    cout<<"\n--------------------\n";
    
    Car c4("Fiat Punto", 200, 1998);
    c4.print();
    cout<<"\n--------------------\n";
    
    Garage g;
    g.addCar(c1);
    g.addCar(c2);
    g.addCar(c3);
    g.addCar(c4);

    
    g.print();
    cout<<"\n--------------------\n";

    g.removeCar("Toyota corolla1");
    g.print();
    cout<<"\n--------------------\n";

    cout<<"Number of cars in garage: "<<g.getCurrentNmberOfCar()<<endl;
    cout<<"\n--------------------\n";

    g[2].print();*/
    
    return 0;
}

