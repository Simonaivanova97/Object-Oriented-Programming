#include "Manga.hpp"
Manga::Manga() : PrintEdition(), Book(), Magazine(){}
Manga::Manga(const char* t, int y, double p, const char* a, Periodicity per) : PrintEdition(t, y, p), Book(t, y, p, a), Magazine(t, y, p, per){}
Manga::~Manga(){}
void Manga::print() const{
    //PrintEdition::print();
    Book::print();
    //Magazine::print();
    Magazine::printOwlyPeriodicity();
}
bool Manga::weeklyManga() const{
    return getPeriod()==Periodicity::Weekly;
}
PrintEdition* Manga::clone(){
    return new Manga(*this);
}
