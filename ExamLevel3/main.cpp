#include <iostream>
#include "PowerSpec.hpp"
#include "Transformer.hpp"
#include "prob4-test.hpp"
using namespace std;

int main() {
    /*PowerSpec p1=PowerSpec("DC", 230, 1);
    PowerSpec p2=PowerSpec("AC", 220, 3);
    
    PowerSpec p3=p2;
    PowerSpec p4=PowerSpec("DC", 250, 5);

    Transformer t1("Siemens", p1, p2);
    t1.print();
    cout<<endl;
    
    Transformer t2("Mitsubishi Electric", p3, p4);
    t2.print();
    cout<<endl;

    Transformer t=(t1*t2);
    t.print();*/
    
    RunTests();
    return 0;
}

