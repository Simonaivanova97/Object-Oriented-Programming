#ifndef CloseQuestion_hpp
#define CloseQuestion_hpp

#include <stdio.h>
#include "Question.hpp"

class CloseQuestion : public Question{
public:
    CloseQuestion();
    CloseQuestion(const Sentence&, const Sentence&, int, int, const Sentence*);
    CloseQuestion(const CloseQuestion&);
    CloseQuestion& operator=(const CloseQuestion&);
    virtual ~CloseQuestion();
    
    virtual void print(ostream& os) const override;
    virtual void read(istream& is) override;
    virtual unsigned ask() override;
    virtual Question* clone() override;
    
private:
    Sentence* possibleAnswer;
    int numberOfPossibleAnswer;
    
    void copyCloseQuestion(const CloseQuestion&);
    void shuffleAnswers();
};
#endif /* CloseQuestion_hpp */
