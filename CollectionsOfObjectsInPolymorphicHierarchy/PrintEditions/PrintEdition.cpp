#include "PrintEdition.hpp"
void PrintEdition::copyPrintEdition(const PrintEdition& other){
    title=new char[strlen(other.title)+1];
    assert(title!=NULL);
    strcpy(title, other.title);
    year=other.year;
    price=other.price;
}
PrintEdition::PrintEdition(){
    title=new char[strlen("Unknown")+1];
    assert(title!=NULL);
    strcpy(title, "Unknown");
    year=0;
    price=0;
}
PrintEdition::PrintEdition(const char* t, int y, double p){
    title=new char[strlen(t)+1];
    assert(title!=NULL);
    strcpy(title, t);
    year=y;
    price=p;
}
PrintEdition::PrintEdition(const PrintEdition& other){
    copyPrintEdition(other);
}
PrintEdition& PrintEdition::operator=(const PrintEdition& other){
    if(this!=&other){
        delete []title;
        copyPrintEdition(other);
    }
    return *this;
}
PrintEdition::~PrintEdition(){
    delete []title;
}
const char* PrintEdition::getTitile() const{
    return title;
}
void PrintEdition::print() const{
    cout<<"Title: "<<title<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Price: "<<price<<endl;
}
