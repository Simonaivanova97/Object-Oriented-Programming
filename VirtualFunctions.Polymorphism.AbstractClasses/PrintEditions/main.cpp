#include <iostream>
#include "PrintEdition.hpp"
#include "Book.hpp"
#include "Magazine.hpp"
#include "Manga.hpp"
using namespace std;

int main() {
    Book theLittlePrince("The Little Prince", 2016, 23.99, "Antoine de Saint-Exupery");
    Book davidCopperfield("David Copperfield", 2016, 25.99, "Charles Dickens");
    Magazine nationaGeographic("National Georgrafic Kids", 2002, 3.50, Periodicity::Monthly);
    Magazine eva("Eva", 1998, 5.67, Periodicity::Monthly);
    Manga strangerThings("Stranger Things", 2019, 22.90, "TaylorTom", Periodicity::Yearly);
    
    PrintEditions* arrayPrintEditions[5]={&theLittlePrince, &davidCopperfield, &nationaGeographic, &eva, &strangerThings};
    
    for(int i=0;i<5;i++){
        arrayPrintEditions[i]->print();
    }
    
    // ИЛИ
    
    PrintEditions** dynamicArrayPrintEditions = new PrintEditions*[3];
    dynamicArrayPrintEditions[0] = new Book("The Little Prince", 2016, 23.99, "Antoine de Saint-Exupery");
    dynamicArrayPrintEditions[1]=new Magazine("National Georgrafic Kids", 2002, 3.50, Periodicity::Monthly);
    dynamicArrayPrintEditions[2]=new Manga("Stranger Things", 2019, 22.90, "TaylorTom", Periodicity::Yearly);

    for(int i=0;i<3;i++){
        dynamicArrayPrintEditions[i]->print();
    }
    
    delete dynamicArrayPrintEditions[0], dynamicArrayPrintEditions[1], dynamicArrayPrintEditions[2];
    delete []dynamicArrayPrintEditions;
    return 0;
}
