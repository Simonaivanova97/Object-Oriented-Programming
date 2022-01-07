#include <iostream>
using namespace std;

struct Product{
    char description[32];
    int partNum;
    double cost;
    
    void print() const;
};

void Product::print()const{
    cout<<"--- Product information ---"<<endl;
    cout<<description<<" | "<<" "<<partNum<<" | "<<cost<<endl;
}

int main() {
    Product p1={"screw-driver",456,5.50};
    Product p2={"hammer",324,8.20};
    
    p1.print();
    cout<<endl;
    p2.print();
    cout<<endl;
    
    Product firstArr[10];
    
    for (int i=0;i<10;i++){
        strcpy(firstArr[i].description, "Unknown");
        firstArr[i].partNum=0;
        firstArr[i].cost=0.0;
    }
    
    Product secondArr[5]={{"screw-driver",456,5.50},
                          {"hammer",324,8.20},
                          {"socket",458,5.75},
                          {"plier",929,10.50},
                          {"hand-saw",536,7.45}};
    
    for(int i=0;i<5;i++){
        secondArr[i].print();
    }
    return 0;
}
