#include <iostream>
#include "Worker.hpp"
#include "Employee.hpp"
#include "Expert.hpp"
#include "Manager.hpp"
using namespace std;

int main() {
    
    Worker boyan("Boyan Boyanov", 0, 0, 2);
    Expert vasilka("vasilka Vasileva", 0, 0);
    Expert nasko("Atanas Nikolaev",0 ,0);
    Worker dimitar("Dimitar Dimitrov", 0, 0, 2);
    Employee* firstArr[1]={&dimitar};
    Manager georgi("Georgi Georgiev", 0, 0, firstArr, 1, 1);
    Employee* secondArr[2]={&boyan, &georgi};
    Manager angel("Angel Angelov",0, 0, secondArr,2 ,2);
    cout<<angel<<endl;
    
    angel.addSubordinate(&vasilka);
    cout<<angel<<endl;
    
    angel.readAndExecuteTasksFromFile("tasks.txt");
    cout<<endl;
    angel.printStatus();
    cout<<endl;
    
    angel.deleteSubordinate("Georgi Georgiev");
    cout<<angel<<endl;
    return 0;
}
