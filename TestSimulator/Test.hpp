#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <fstream>
#include "CloseQuestion.hpp"
#include "OpenQuestion.hpp"

class Test{
public:
    Test();
    Test(const char*);
    Test(const Test&);
    Test& operator=(const Test&);
    ~Test();
    
    int startTest()const;
    void shuffleQuestion();
    void print() const;
    void writeQuestionsToFile(const char*) const;
    
private:
    Question** arr;
    int numberOfQuestion;
    
    void copyTest(const Test&);
    int countQuestion(const char*);
};

#endif /* Test_hpp */
