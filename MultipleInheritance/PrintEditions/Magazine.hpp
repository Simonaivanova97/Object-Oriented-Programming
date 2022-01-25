#ifndef Magazine_hpp
#define Magazine_hpp

#include <stdio.h>
#include "PrintEdition.hpp"

enum class Periodicity{
    Weekly, Monthly, Yearly
};

class Magazine : virtual public PrintEdition{
public:
    Magazine();
    Magazine(const char*, int, double, Periodicity);
    
    virtual void print() const override;

private:
    Periodicity period;
    const char* periodicities[3]={"Weekly", "Monthly", "Yearly"};
protected:
    void printOwlyPeriodicity() const;
    const Periodicity getPeriod() const;
};
#endif /* Magazine_hpp */
