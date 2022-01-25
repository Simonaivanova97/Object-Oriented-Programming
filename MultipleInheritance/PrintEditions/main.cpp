#include <iostream>
#include "PrintEdition.hpp"
#include "Book.hpp"
#include "Magazine.hpp"
#include "Manga.hpp"
#include "Bookstore.hpp"
using namespace std;

int main() {
    Book theLittlePrince("The Little Prince", 2016, 23.99, "Antoine de Saint-Exupery");
    Book davidCopperfield("David Copperfield", 2016, 25.99, "Charles Dickens");
    Magazine nationaGeographic("National Georgrafic Kids", 2002, 3.50, Periodicity::Monthly);
    Magazine eva("Eva", 1998, 5.67, Periodicity::Monthly);
    Manga strangerThings("Stranger Things", 2019, 22.90, "TaylorTom", Periodicity::Yearly);

    /*theLittlePrince.print();
    cout<<"\n--------------------\n";
    
    nationaGeographic.print();
    cout<<"\n--------------------\n";
    
    strangerThings.print();*/
    
    PrintEdition* arr[4]={&theLittlePrince, &davidCopperfield, &nationaGeographic, &eva};
    
    Bookstore b1(arr, 4, 4);
    
    b1.addPrintedition(&strangerThings);
    
    b1.print();
    cout<<endl;
    
    b1["National Georgrafic Kids"]->print();
    
    cout<<"\nNumber of weekly manga: "<<b1.numberMangaWeekly()<<endl;
