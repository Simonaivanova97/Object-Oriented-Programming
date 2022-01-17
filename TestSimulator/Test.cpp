#include "Test.hpp"
void Test::copyTest(const Test& other){
    numberOfQuestion=other.numberOfQuestion;
    arr=new Question*[numberOfQuestion];
    assert(arr!=NULL);
    for(int i=0;i<numberOfQuestion;i++){
        arr[i]=other.arr[i]->clone();
    }
}
int Test::countQuestion(const char* fileName){
    int count=0;
    fstream myFile(fileName, ios::in);
    string tempRow;
    while(getline(myFile, tempRow)){
        do{
            getline(myFile, tempRow);
        }while (tempRow!="");
        count++;
    }
    myFile.close();
    return count;
}
Test::Test(){
    numberOfQuestion=0;
    arr=NULL;
}
Test::Test(const char* fileName){
    numberOfQuestion=countQuestion(fileName);
    arr=new Question*[numberOfQuestion];
    assert(arr!=NULL);
    fstream myFile(fileName, ios::in);
    string tempRow;
    int countQuest=0;
    while(getline(myFile, tempRow)){
        Sentence tempQuest, tempCorrectAnswer;
        int tempPoint, tempPosibleAnswer=0;
        tempQuest.setSentence(tempRow);
        int numberPossibleAnsw=0, row=2;
        Sentence* tempArr=NULL;
        do{
            getline(myFile, tempRow);
            if(row==2){
                tempRow.erase(0, 16);
                tempCorrectAnswer.setSentence(tempRow);
            }
            else if (row==3){
                tempRow.erase(0, 11);
                tempPoint=stoi(tempRow);
            }
            if(tempRow!=""){
                if (row==4){
                    tempRow.erase(0, 27);
                    tempPosibleAnswer=stoi(tempRow);
                }
                else if(row==5){
                    tempArr=new Sentence[tempPosibleAnswer];
                    assert(tempArr!=NULL);
                    tempRow.erase(0,10);
                    int countOptions=0;
                    int i=0;
                    while(tempRow[i]!='\0'){
                        char tempOption[200];
                        int j=0;
                        while(tempRow[i]!=']'){
                            tempOption[j]=tempRow[i];
                            j++;
                            i++;
                        }
                        if(tempRow[i+1]!='\0'){
                            i+=4;
                        }
                        else{
                            i++;
                        }
                        tempOption[j]='\0';
                        Sentence s(tempOption);
                        tempArr[countOptions]=s;
                        countOptions++;
                    }
                }
            }
            row++;
        }while (tempRow!="");
        if(tempArr!=NULL){
            CloseQuestion c(tempQuest, tempCorrectAnswer, tempPoint, tempPosibleAnswer, tempArr);
            arr[countQuest]=c.clone();
        }
        else{
            OpenQuestion o(tempQuest, tempCorrectAnswer, tempPoint);
            arr[countQuest]=o.clone();
        }
        countQuest++;
        tempArr=NULL;
        delete tempArr;
    }
    myFile.close();
}
Test::Test(const Test& other){
    copyTest(other);
}
Test& Test::operator=(const Test& other){
    if(this!=&other){
        delete []arr;
        copyTest(other);
    }
    return *this;
}
Test::~Test(){
    delete []arr;
}
int Test::startTest()const{
    int countPoint=0;
    for(int i=0;i<numberOfQuestion;i++){
        countPoint+=arr[i]->ask();
    }
    return countPoint;
}
void Test::shuffleQuestion(){
    srand(std::time(0));
    for (int i=0; i<numberOfQuestion; i++) {
        int r = i + (rand() % (numberOfQuestion-i));
        Question* temp=arr[i]->clone();
        arr[i]=arr[r]->clone();
        arr[r]=temp->clone();
        temp=NULL;
        delete temp;
    }
}
void Test::writeQuestionsToFile(const char* fileName) const{
    ofstream myfile;
    myfile.open (fileName);
    for(int i=0;i<numberOfQuestion;i++){
        if(i==numberOfQuestion-1){
            arr[i]->print(myfile);
        }
        else{
            arr[i]->print(myfile);
            myfile<<endl;
        }
    }
    myfile.close();
}
void Test::print() const{
    for(int i=0;i<numberOfQuestion;i++){
        arr[i]->print(cout);
    }
}

