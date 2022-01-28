#ifndef QA_hpp
#define QA_hpp

#include <stdio.h>
#include "ITSpecialist.hpp"

enum class TypeQa{
    autumation, manualTester
};

class QA : public ITSpecialist{
public:
    QA();
    QA(const char*, int, double, const char*, TypeQa);
    virtual ~QA();
    
    virtual void print() const override;
    virtual Employee* clone() override;

private:
    TypeQa type;
    const char* types[2]={"autumation", "manual tester"};
};

#endif /* QA_hpp */
