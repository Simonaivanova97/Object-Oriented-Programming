#ifndef Question_hpp
#define Question_hpp

#include <stdio.h>
#include "Sentence.hpp"

class Question{
public:
    Question();
    Question(const Sentence&, const Sentence&, int);
    virtual ~Question();
    
    const Sentence getQuest() const;
    const Sentence getCorrectAnswer() const;
    int getPoint() const;
    
    virtual void print(ostream& os) const = 0;
    virtual void read(istream& is) = 0;
    virtual unsigned ask() = 0;
    virtual Question* clone() = 0;
    
protected:
    Sentence quest;
    Sentence correctAnswer;
    int point;
};

#endif /* Question_hpp */
