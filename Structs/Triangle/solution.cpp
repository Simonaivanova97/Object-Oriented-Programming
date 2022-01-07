#include <iostream>
#include <cmath>
using namespace std;

struct Triangle{
    double a,b,c;
};

void printTriangle(const Triangle& t){
    cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
}

void initTriangle(Triangle& t){
    do{
        cout<<"Enter value for sides of triangle"<<endl;
        cin>>t.a;
        cin>>t.b;
        cin>>t.c;
        if((t.a>=t.b+t.c) || (t.b>=t.a+t.c) || (t.c>=t.a+t.b)){
            cout<<"In a triangle, each side must be less than the sum of the other two sides!"<<endl;
        }
    }while(t.a<=0 || t.b<=0 || t.c<=0 ||
           (t.a>=t.b+t.c) ||
           (t.b>=t.a+t.c) ||
           (t.c>=t.a+t.b));
}

double findArea(const Triangle& t){
    return t.a+t.b+t.c;
}

double findSurface(const Triangle& t){
    double p=findArea(t)/2;
    return sqrt((p*(p-t.a)*(p-t.b)*(p-t.c)));
}

int main() {
    
    Triangle t;
    initTriangle(t);
    printTriangle(t);
    cout<<"Area of triangle is: "<<findArea(t)<<endl;
    cout<<"Surface of triangle is: "<<findSurface(t)<<endl;
    
    return 0;
}
