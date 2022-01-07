#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int width;
};

void print_rectangle(Rectangle r){
    cout<<"length: "<<r.length<<endl;
    cout<<"width: "<<r.width<<endl;
}

void init_rectangle(Rectangle& r){
    do{
        cout<<"Enter length of rectangle: ";
        cin>>r.length;
    }while(r.length<=0);
    do{
        cout<<"Enter width of rectangle: ";
        cin>>r.width;
    }while(r.width<=0);
}

Rectangle init_rectangle(){
    Rectangle r;
    init_rectangle(r);
    return r;
}

int main() {
    Rectangle r1;
    init_rectangle(r1);
    print_rectangle(r1);
    
    Rectangle r2=init_rectangle();
    print_rectangle(r2);
    return 0;
}
