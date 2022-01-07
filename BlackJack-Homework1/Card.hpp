#ifndef Card_hpp
#define Card_hpp

#include <iostream>
using namespace std;
const int MAX_Serial_Number=16;
const int Max_Seria=11;

enum cardsType { spade, heart, diamond, club};
enum cardsValue { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

class Card{
public:
    Card();
    
    cardsType getType() const;
    cardsValue getValue() const;
    const char* getSerialNumber()const;
    
    void setCardType(cardsType type);
    void setCardValue(cardsValue value);
    void setSerialNumber(const char* s);
    
    int point();
    void print() const;
    
private:
    cardsType cardType;
    cardsValue cardValue;
    char serialNumber[MAX_Serial_Number];
};

#endif /* Card_hpp */
