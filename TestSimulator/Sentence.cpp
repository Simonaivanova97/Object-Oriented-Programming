#include "Sentence.hpp"
void Sentence::copySentence(const Sentence& other){
    str=new char[strlen(other.str)+1];
    assert(str!=NULL);
    strcpy(str, other.str);
}
Sentence::Sentence(){
    str=new char[strlen("Unknown")+1];
    assert(str!=NULL);
    strcpy(str, "Unknown");
}
Sentence::Sentence(const char* s){
    str=new char[strlen(s)+1];
    assert(str!=NULL);
    strcpy(str, s);
}
Sentence::Sentence(const Sentence& other){
    copySentence(other);
}
Sentence& Sentence::operator=(const Sentence& other){
    if(this!=&other){
        delete []str;
        copySentence(other);
    }
    return *this;
}
Sentence::~Sentence(){
    delete []str;
}
const char* Sentence::getSentence() const{
    return str;
}
void Sentence::setSentence(const string& s){
    delete []str;
    str=new char[s.length()+1];
    assert(str!=NULL);
    strcpy(str,s.c_str());
}
void Sentence::print(ostream& os) const{
    os<<str<<endl;
}
void Sentence::read(istream& is){
    //cout<<"Enter sentence: ";
    char s[200];
    is.getline(s, 200);
    str=new char[strlen(s)+1];
    assert(str!=NULL);
    strcpy(str, s);
}
