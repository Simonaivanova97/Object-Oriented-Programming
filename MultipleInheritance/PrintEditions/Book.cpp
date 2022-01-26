#include "Book.hpp"
void Book::copyBook(const Book& other){
    author=new char[strlen(other.author)+1];
    assert(author!=NULL);
    strcpy(author, other.author);
}
Book::Book() : PrintEdition(){
    author=new char[strlen("Unknown")+1];
    assert(author!=NULL);
    strcpy(author, "Unknown");
}
Book::Book(const char* t, int y, double p, const char* a) : PrintEdition(t, y, p){
    author=new char[strlen(a)+1];
    assert(author!=NULL);
    strcpy(author, a);
}
Book::Book(const Book& other) : PrintEdition(other){
    copyBook(other);
}
Book& Book::operator=(const Book& other){
    if(this!=&other){
        delete []author;
        PrintEdition::operator=(other);
        copyBook(other);
    }
    return *this;
}
Book::~Book(){
    delete []author;
}
void Book::print() const{
    PrintEdition::print();
    cout<<"Author: "<<author<<endl;
}
PrintEdition* Book::clone(){
    return new Book(*this);
}
