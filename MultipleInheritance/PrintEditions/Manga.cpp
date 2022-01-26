#include "Manga.hpp"
Manga::Manga() : PrintEdition(), Book(), Magazine(){}
Manga::Manga(const char* t, int y, double p, const char* a, Periodicity per) : PrintEdition(t, y, p), Book(t, y, p, a), Magazine(t, y, p, per){}
void Manga::print() const{
    Book::print();
    Magazine::printOwlyPeriodicity();
}
