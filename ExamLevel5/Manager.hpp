#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>
#include <fstream>
#include "Employee.hpp"

class Manager : public Employee{
public:
    Manager();
    Manager(const char*,int, int, Employee**, int, int);
    Manager(const Manager&);
    Manager& operator=(const Manager&);
    virtual~Manager();
    
    virtual bool execute(const char*) override;
    virtual double successRate() const override;
    virtual Employee* clone() override;
    virtual void print() const override;
    
    void addSubordinate(Employee*);
    void deleteSubordinate(const char*);
    void printStatus() const;
    void readAndExecuteTasksFromFile(const char*);
    friend ostream& operator<<(ostream&, const Manager&);

private:
    Employee** arr;
    int maxSubordinate;
    int currentSubordinate;
    
    void copyManager(const Manager&);
    void erase();
    bool havaSubordinate(const char*) const;
};

#endif /* Manager_hpp */
