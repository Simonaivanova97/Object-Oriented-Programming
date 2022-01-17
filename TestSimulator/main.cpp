#include <iostream>
#include <fstream>
#include "Sentence.hpp"
#include "Question.hpp"
#include "CloseQuestion.hpp"
#include "OpenQuestion.hpp"
#include "Test.hpp"
using namespace std;

int main() {
    Test t("question.txt");
    cout<<"----------START TEST----------"<<endl;
    int points=t.startTest();
    cout<<"\nRESULT: "<<points<<endl;
    
    t.shuffleQuestion();
    cout<<"\n----------SHUFFLE TEST'S QUESTIONS----------"<<endl;
    t.print();
    
    cout<<"\n----------WRITE TEST TO FILE----------"<<endl;
    t.writeQuestionsToFile("question.txt");
    return 0;
}
