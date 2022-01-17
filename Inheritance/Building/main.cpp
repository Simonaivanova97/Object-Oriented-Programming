#include <iostream>
#include "Building.hpp"
#include "House.hpp"
using namespace std;

House theMostSpaciousHouse(House* arr, int numberOfHause){
    House max=arr[0];
    for(int i=0;i<numberOfHause;i++){
        if(arr[i].getHeight()/arr[i].getNumberOfFloors()>max.getHeight()/max.getNumberOfFloors()){
            max=arr[i];
        }
    }
    return max;
}

int main() {
    
    Building building(30, 650.43, "st. \"acad. Jacques Nathan\"");
    building.print();
    cout << "----------\n";

    House house(5, 120.64, "st. \"Dimcho Debelyanov\"", 2, "Atanas Nikolov");
    house.print();

    House houseTwo(10, 154, "st. Hirsto Botev 124", 3, "Ivan Petrov");
    House houseThree(10, 165, "st. Hirsto Botev 124", 4, "Ivan Petrov");
    House arr[2]={houseTwo,houseThree};
    
    cout << "\n---------- The most spacious house ---------- \n";
    theMostSpaciousHouse(arr,2).print();
    return 0;
}
