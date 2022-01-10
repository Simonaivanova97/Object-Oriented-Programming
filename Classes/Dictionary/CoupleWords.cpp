//
//  CoupleWords.cpp
//  Test1
//
//  Created by Simona Ivanova on 10.01.22.
//

#include "CoupleWords.hpp"
void CoupleWords::copyCoupleWords(const CoupleWords& other){
    word=new char[strlen(other.word)+1];
    assert(word!=NULL);
    strcpy(word, other.word);
    meaning=new char[strlen(other.meaning)+1];
    assert(meaning!=NULL);
    strcpy(meaning, other.meaning);
}
CoupleWords::CoupleWords(){
    word=new char[strlen("Unknown")+1];
    assert(word!=NULL);
    strcpy(word, "Unknown");
    meaning=new char[strlen("Unknown")+1];
    assert(meaning!=NULL);
    strcpy(meaning, "Unknown");
}
CoupleWords::CoupleWords(const char* w, const char* m){
    word=new char[strlen(w)+1];
    assert(word!=NULL);
    strcpy(word, w);
    meaning=new char[strlen(m)+1];
    assert(meaning!=NULL);
    strcpy(meaning, m);
}
CoupleWords::CoupleWords(const CoupleWords& other){
    copyCoupleWords(other);
}
CoupleWords& CoupleWords::operator=(const CoupleWords& other){
    if(this!=&other){
        delete []word;
        delete []meaning;
        copyCoupleWords(other);
    }
    return *this;
}
CoupleWords::~CoupleWords(){
    delete []word;
    delete []meaning;
}
const char* CoupleWords::getWord() const{
    return word;
}
const char* CoupleWords::getMeaning() const{
    return meaning;
}
void CoupleWords::setWord(const char* w){
    delete word;
    word=new char[strlen(w)+1];
    assert(word!=NULL);
    strcpy(word, w);
}
void CoupleWords::setMeaning(const char* m){
    delete []meaning;
    meaning=new char[strlen(m)+1];
    assert(meaning!=NULL);
    strcpy(meaning, m);
}
void CoupleWords::print() const{
    cout<<word<<setw(30-strlen(word))<<"| "<<meaning<<endl;
}
