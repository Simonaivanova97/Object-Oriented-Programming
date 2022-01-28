#include <iostream>
#include "Employee.hpp"
#include "ITSpecialist.hpp"
#include "Programmer.hpp"
#include "QA.hpp"
#include "Manager.hpp"
#include "Company.hpp"
using namespace std;

int main() {
    // Може да създадем масив от работници по следните два начина.
    // 1 начин: (Без delete arr[0] , ... защото ако масивът в създаден по този първи начин, елементите не са заделени в динамичната памет.
    /*Manager boss("Petya Ivanova", 38, 9000, 45);
    Manager subBoss("Ivo Nikolov", 180, 7000, 35);
    Programmer p1("Stefan Aleksandrov", 14, 1800, "Steal Kredit Cards", "C++, JavaScript");
    Programmer p2("Mariya Petrova", 6, 800, "Web-site maintenance", "HTML && CSS");
    Programmer p3("Dimitar Slavchev", 2, 500, "Steal Kredit Cards", "C++");
    QA tester("Daniela Martinova", 18, 2500, "Cloud system", TypeQa::autumation);
    Employee* arr[6]={&boss, &subBoss, &p1, &p2, &p3, &tester};*/
    
    // 2 начин:
    Employee* arr[6];
    arr[0]=new Manager("Petya Ivanova", 38, 9000, 45);
    arr[1]=new Manager("Ivo Nikolov", 180, 7000, 35);
    arr[2]=new Programmer("Stefan Aleksandrov", 14, 1800, "Steal Kredit Cards", "C++, JavaScript");
    arr[3]=new Programmer("Mariya Petrova", 6, 800, "Web-site maintenance", "HTML && CSS");;
    arr[4]=new Programmer("Dimitar Slavchev", 2, 500, "Steal Kredit Cards", "C++");
    arr[5]=new QA("Daniela Martinova", 18, 2500, "Cloud system", TypeQa::autumation);
    
    Company c(2);
    for(int i=0;i<6;i++){
        c.addEmployee(arr[i]);
    }
    
    c.print();
    cout<<endl;
    
    cout<<"Delete new employees"<<endl;
    c.removeNewEmployee();
    c.print();
    
    cout<<"\nSum of all salaries: "<<c.sumSalaries()<<endl;
    cout<<"\nAvg salaries: "<<c.avgSalary()<<endl;
    cout<<endl;
    
    c.removeHTMLProgrammer();
    c.print();
    delete arr[0], arr[1], arr[2], arr[3], arr[4], arr[5];
    
    return 0;
}
