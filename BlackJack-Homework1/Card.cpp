#include "Card.hpp"

ostream &operator<<( ostream& out, cardsType cType){
   const string nameTypes[] = { "spade", "heart", "diamond", "club"};
   return out << nameTypes[cType];
}

ostream &operator<<( ostream& out, cardsValue cValue){
   const string nameValues[] = { "2", "3", "4", "5","6","7","8","9","10","J","Q","K","A"};
   return out << nameValues[cValue];
}
Card::Card(){
    cardType=spade;
    cardValue=two;
    strcpy(serialNumber,"");
    serialNumber[MAX_Serial_Number-1]='\0';
}

cardsType Card::getType() const{
    return cardType;
}
cardsValue Card::getValue() const{
    return cardValue;
}
const char* Card::getSerialNumber()const{
    return serialNumber;
}

void Card::setCardType(cardsType type){
    cardType=type;
}
void Card::setCardValue(cardsValue value){
    cardValue=value;
}
void Card::setSerialNumber(const char* s){
    strcpy(serialNumber, s);
}

int Card::point(){
    //return getValue();
    int currentPoint;
    switch (getValue()) {
        case 0:
            currentPoint=2;
            break;
        case 1:
            currentPoint=3;
            break;
        case 2:
            currentPoint=4;
            break;
        case 3:
            currentPoint=5;
            break;
        case 4:
            currentPoint=6;
            break;
        case 5:
            currentPoint=7;
            break;
        case 6:
            currentPoint=8;
            break;
        case 7:
            currentPoint=9;
            break;
        case 8:
            currentPoint=10;
            break;
        case 9:
            currentPoint=10;
            break;
        case 10:
            currentPoint=10;
            break;
        case 11:
            currentPoint=10;
            break;
        case 12:
            int p;
            do{
                cout<<"Choose point of ace: "<<endl;
                cin>>p;
            }while(p!=1 && p!=11);
            currentPoint=p;
            break;
    }
    return currentPoint;
}

void Card::print() const{
    cout<<cardValue<<" ("<<cardType<<") ";
    //cout<<serialNumber;
}
