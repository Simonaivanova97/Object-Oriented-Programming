#include "CloseQuestion.hpp"
void CloseQuestion::copyCloseQuestion(const CloseQuestion& other){
    numberOfPossibleAnswer=other.numberOfPossibleAnswer;
    possibleAnswer=new Sentence[numberOfPossibleAnswer];
    assert(possibleAnswer!=NULL);
    for(int i=0;i<numberOfPossibleAnswer;i++){
        possibleAnswer[i]=other.possibleAnswer[i];
    }
}
void CloseQuestion::shuffleAnswers(){
    srand(std::time(0));
    for (int i=0; i<numberOfPossibleAnswer; i++) {
        int r = i + (rand() % (numberOfPossibleAnswer-i));
        Sentence temp = possibleAnswer[i];
        possibleAnswer[i] = possibleAnswer[r];
        possibleAnswer[r] = temp;
    }
}
CloseQuestion::CloseQuestion() : Question(){
    numberOfPossibleAnswer=0;
    possibleAnswer=NULL;
}
CloseQuestion::CloseQuestion(const Sentence& q, const Sentence& cA, int p, int n, const Sentence* arr) : Question(q, cA, p){
    numberOfPossibleAnswer=n;
    possibleAnswer=new Sentence[numberOfPossibleAnswer];
    assert(possibleAnswer!=NULL);
    for(int i=0;i<numberOfPossibleAnswer-1;i++){
        possibleAnswer[i]=arr[i];
    }
    possibleAnswer[numberOfPossibleAnswer-1]=correctAnswer;
}
CloseQuestion::CloseQuestion(const CloseQuestion& other) : Question(other){
    copyCloseQuestion(other);
}
CloseQuestion& CloseQuestion::operator=(const CloseQuestion& other){
    if(this!=&other){
        Question::operator=(other);
        delete []possibleAnswer;
        copyCloseQuestion(other);
    }
    return *this;
}
CloseQuestion::~CloseQuestion(){
    delete []possibleAnswer;
}

void CloseQuestion::print(ostream& os) const{
    os<<getQuest().getSentence()<<endl;
    os<<"Correct answer: "<<getCorrectAnswer().getSentence()<<endl;
    os<<"Max point: "<<getPoint()<<endl;
    os<<"Number of possible answer: "<<numberOfPossibleAnswer<<endl;
    os<<"Options: ";
    for(int i=0;i<numberOfPossibleAnswer;i++){
        if(strcmp(possibleAnswer[i].getSentence(), correctAnswer.getSentence())!=0){
            if(i==numberOfPossibleAnswer-1 || (i==numberOfPossibleAnswer-2 && strcmp(possibleAnswer[i+1].getSentence(), correctAnswer.getSentence())==0)){
                os<<"["<<possibleAnswer[i].getSentence()<<"]"<<endl;
            }
            else{
                os<<"["<<possibleAnswer[i].getSentence()<<"]; ";
            }
        }
    }
}
void CloseQuestion::read(istream& is){
    cout<<"Enter condition of task: ";
    quest.read(is);
    cout<<"Enter correct answer: ";
    correctAnswer.read(is);
    cout<<"Enter max point: ";
    is>>point;
    cout<<"Enter number of possible answers: ";
    is>>numberOfPossibleAnswer;
    possibleAnswer=new Sentence[numberOfPossibleAnswer];
    assert(possibleAnswer!=NULL);
    cin.ignore();
    for(int i=0;i<numberOfPossibleAnswer-1;i++){
        cout<<"Enter option: ";
        possibleAnswer[i].read(cin);
    }
    possibleAnswer[numberOfPossibleAnswer-1]=correctAnswer;
}
unsigned CloseQuestion::ask(){
    getQuest().print(cout);
    char tempLetter;
    shuffleAnswers();
    for(int i=0;i<numberOfPossibleAnswer;i++){
        tempLetter=97+i;
        cout<<tempLetter<<") ";
        possibleAnswer[i].print(cout);
    }
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
Question* CloseQuestion::clone(){
    return new CloseQuestion(*this);
}
