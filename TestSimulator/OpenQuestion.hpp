#ifndef OpenQuestion_hpp
#define OpenQuestion_hpp

#include <stdio.h>
#include "Question.hpp"

class OpenQuestion : public Question{
public:
    OpenQuestion();
    OpenQuestion(const Sentence&, const Sentence&, int);
    virtual ~OpenQuestion();
    
    virtual void print(ostream& os) const override;
    virtual void read(istream& is) override;
    virtual unsigned ask() override;
    virtual Question* clone() override;

};

#endif /* OpenQuestion_hpp */
