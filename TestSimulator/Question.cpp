#include "Question.hpp"

Question::Question(){
    point=0;
}
Question::Question(const Sentence& q, const Sentence& cA, int p){
    quest=q;
    correctAnswer=cA;
    point=p;
}
Question::~Question(){}
const Sentence Question::getQuest() const{
    return quest;
}
const Sentence Question::getCorrectAnswer() const{
    return correctAnswer;
}
int Question::getPoint() const{
    return point;
}
