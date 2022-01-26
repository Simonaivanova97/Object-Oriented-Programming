#include "Bookstore.hpp"
void Bookstore::copyBookstore(const Bookstore& other){
    numberOfElement=other.numberOfElement;
    capacity=other.capacity;
    arr=new PrintEdition*[capacity];
    assert(arr!=NULL);
    for(int i=0;i<numberOfElement;i++){
        arr[i]=other.arr[i]->clone();
    }
}
void Bookstore::erase(){
    for(int i=0;i<numberOfElement;i++){
        delete arr[i];
    }
    delete []arr;
}
Bookstore::Bookstore(){
    numberOfElement=0;
    capacity=0;
    arr=NULL;
}
Bookstore::Bookstore(PrintEdition** a, int n, int c){
    capacity=c;
    numberOfElement=n;
    arr=new PrintEdition*[capacity];
    assert(arr!=NULL);
    for(int i=0;i<numberOfElement;i++){
        arr[i]=a[i]->clone();
    }
}
Bookstore::Bookstore(const Bookstore& other){
    copyBookstore(other);
}
Bookstore& Bookstore::operator=(const Bookstore& other){
    if(this!=&other){
        erase();
        copyBookstore(other);
    }
    return *this;
}
Bookstore::~Bookstore(){
    erase();
}
void Bookstore::print() const{
    for(int i=0;i<numberOfElement;i++){
        arr[i]->print();
        cout<<"\n--------------------\n";
    }
}
void Bookstore::addPrintedition(PrintEdition* pE){
    if(numberOfElement==capacity){
        capacity*=2;
        PrintEdition** copyArr=arr;
        arr=new PrintEdition*[capacity];
        assert(arr!=NULL);
        for(int i=0;i<numberOfElement;i++){
            arr[i]=copyArr[i]->clone();
        }
        for(int i=0;i<numberOfElement;i++){
            delete copyArr[i];
        }
        delete []copyArr;
    }
    arr[numberOfElement]=pE->clone();
    numberOfElement++;
}
const PrintEdition* Bookstore::operator[](const char* t){
    for(int i=0;i<numberOfElement;i++){
        if(strcmp(arr[i]->getTitile(), t)==0){
            return arr[i];
            break;
        }
    }
    return NULL;
}
int Bookstore::numberMangaWeekly() const{
    int count=0;
    for(int i=0;i<numberOfElement;i++){
        Manga* m=dynamic_cast<Manga*>(arr[i]);
        if(m && m->weeklyManga()){
            count++;
        }
        m=NULL;
        delete m;
    }
    return count;
}
