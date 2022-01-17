#include "OpenQuestion.hpp"
OpenQuestion::OpenQuestion() : Question(){}
OpenQuestion::OpenQuestion(const Sentence& q, const Sentence& cA, int p) : Question(q,cA,p){}
OpenQuestion::~OpenQuestion(){}

void OpenQuestion::print(ostream& os) const{
    os<<getQuest().getSentence()<<endl;
    os<<"Correct answer: "<<getCorrectAnswer().getSentence()<<endl;
    os<<"Max point: "<<getPoint()<<endl;
}
void OpenQuestion::read(istream& is){
    cout<<"Enter condition of task: ";
    quest.read(is);
    cout<<"Enter correct answer: ";
    correctAnswer.read(is);
    cout<<"Enter max point: ";
    is>>point;
}
unsigned OpenQuestion::ask(){
    getQuest().print(cout);
    cout<<"Enter your answer: ";
    Sentence tempAnsw;
    tempAnsw.read(cin);
    if(strcmp(tempAnsw.getSentence(), getCorrectAnswer().getSentence())==0){
        cout<<"Correct answer!"<<endl;
        return getPoint();
    }
    else{
        return 0;
    }
}
Question* OpenQuestion::clone(){
    return new OpenQuestion(*this);
}
