//
//  Dictionary.cpp
//  Test1
//
//  Created by Simona Ivanova on 10.01.22.
//

#include "Dictionary.hpp"
void Dictionary::copyDictionary(const Dictionary& other){
    size=other.size;
    arr=new CoupleWords[size];
    assert(arr!=NULL);
    for(int i=0;i<size;i++){
        arr[i]=other.arr[i];
    }
}
Dictionary::Dictionary(){
    size=0;
    arr=NULL;
}
Dictionary::Dictionary(int s, const CoupleWords* a){
    size=s;
    arr=new CoupleWords[size];
    assert(arr!=NULL);
    for(int i=0;i<size;i++){
        arr[i]=a[i];
    }
}
Dictionary::Dictionary(const Dictionary& other){
    copyDictionary(other);
}
Dictionary& Dictionary::operator=(const Dictionary& other){
    if(this!=&other){
        delete []arr;
        copyDictionary(other);
    }
    return *this;
}
Dictionary::~Dictionary(){
    delete []arr;
}
void Dictionary::print()const{
    if(size>0){
        for(int i=0;i<size;i++){
            arr[i].print();
        }
    }
    else{
        cout<<"There are no words in the dictionary yet!"<<endl;
    }
}
void Dictionary::addCoupleWords(const CoupleWords& cW){
    CoupleWords* copyArr=arr;
    size++;
    arr=new CoupleWords[size];
    assert(arr!=NULL);
    for(int i=0;i<size-1;i++){
        arr[i]=copyArr[i];
    }
    arr[size-1]=cW;
    copyArr=NULL;
    delete copyArr;
}
void Dictionary::deleteCoupleWords(const CoupleWords& cW){
    CoupleWords* copyArr=arr;
    size--;
    arr=new CoupleWords[size];
    assert(arr!=NULL);
    int j=0,i=0;
    for(i=0;i<size && !(strcmp(copyArr[i].getWord(), cW.getWord())==0 && strcmp(copyArr[i].getMeaning(), cW.getMeaning())==0);i++){
        arr[i]=copyArr[i];
        j++;
    }
    j++;
    for(i;i<size;i++,j++){
        arr[i]=copyArr[j];
    }
    copyArr=NULL;
    delete copyArr;
}
const char* Dictionary::operator[](const char* w){
    bool haveWord=false;
    for(int i=0;i<size;i++){
        if(strcmp(arr[i].getWord(), w)==0){
            haveWord=true;
            cout<<"Meaning of "<<w<<" - ";
            return arr[i].getMeaning();
            break;
        }
    }
    return "Word is not in dictionary!";
}
