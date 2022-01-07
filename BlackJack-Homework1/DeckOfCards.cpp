#include "DeckOfCards.hpp"
DeckOfCards::DeckOfCards(){
    sizeOfDeck=52;
    deckOfCards= new Card[sizeOfDeck];
    initDeckOfCard(sizeOfDeck);
    strcpy(seria,"Default");
    seria[Max_Seria-1]='\0';
}
DeckOfCards::DeckOfCards(int k){
    sizeOfDeck=k;
    deckOfCards=new Card[sizeOfDeck];
    strcpy(seria,"Custom");
    seria[Max_Seria-1]='\0';
    initDeckOfCard(sizeOfDeck);
}
DeckOfCards::DeckOfCards(int k, const char* s){
    sizeOfDeck=k;
    deckOfCards=new Card[sizeOfDeck];
    initDeckOfCard(sizeOfDeck);
    strcpy(seria,s);
    seria[Max_Seria-1]='\0';
}
DeckOfCards::DeckOfCards(const DeckOfCards& other){
    copy(other);
}
DeckOfCards& DeckOfCards::operator=(const DeckOfCards& other){
    if(this!=&other){
        delete []deckOfCards;
        copy(other);
    }
    return *this;
}
DeckOfCards::~DeckOfCards(){
    delete []deckOfCards;
}

void DeckOfCards::draw(){
    //Card* tempDeckOfCard=deckOfCards;
    DeckOfCards tempDeckOfCards=*this;
    //tempDeckOfCards.print();
    delete []deckOfCards;
    deckOfCards=new Card[sizeOfDeck];
    for(int i=0;i<sizeOfDeck-1;i++){
        deckOfCards[i]=tempDeckOfCards.deckOfCards[i+1];
    }
    deckOfCards[sizeOfDeck-1]=tempDeckOfCards.deckOfCards[0];
    delete []tempDeckOfCards.deckOfCards;
    tempDeckOfCards.deckOfCards=nullptr;
}

void DeckOfCards::swap(int firstIndex, int secondIndex){
    if(firstIndex<=sizeOfDeck && secondIndex<=sizeOfDeck && firstIndex>0 && secondIndex>0 ){
        DeckOfCards tempDeckOfCards=*this;
        delete []deckOfCards;
        
        deckOfCards=new Card[sizeOfDeck];
        for(int i=0;i<sizeOfDeck;i++){
            if(i==firstIndex-1){
                Card copyCard=tempDeckOfCards.deckOfCards[firstIndex-1];
                deckOfCards[i]=tempDeckOfCards.deckOfCards[secondIndex-1];
                deckOfCards[secondIndex-1]=copyCard;
            }
            else if(i!=secondIndex-1 && i!=firstIndex-1){
                deckOfCards[i]=tempDeckOfCards.deckOfCards[i];
            }
        }
        delete []tempDeckOfCards.deckOfCards;
        tempDeckOfCards.deckOfCards=nullptr;
    }
    else{
        cout<<"Can't swap this card, becouse of invalid index!"<<endl;
    }
}

int DeckOfCards::suit_count(const cardsType& type){
    int count=0;
    for(int i=0;i<sizeOfDeck;i++){
        if(deckOfCards[i].getType()==type){
            count++;
        }
    }
    return count;
}

void DeckOfCards::deleteFirstCard(){
    DeckOfCards temp=*this;
    delete []deckOfCards;
    sizeOfDeck=temp.sizeOfDeck-1;
    deckOfCards=new Card[sizeOfDeck];
    for(int i=1;i<temp.sizeOfDeck;i++){
        deckOfCards[i-1]=temp.deckOfCards[i];
    }
    delete []temp.deckOfCards;
    temp.deckOfCards=nullptr;
}

Card DeckOfCards::getFirstCard() const{
    return deckOfCards[0];
}

int DeckOfCards::rank_count(int value) const{
    int count=0;
    for(int i=0;i<sizeOfDeck;i++){
        if(deckOfCards[i].getValue()==ace){
            //cout<<"Aso"<<endl;
            if(value==1 || value==11){
                count++;
            }
        }
        else if(deckOfCards[i].point()==value){
            count++;
        }
    }
    //cout<<count<<endl;
    return count;
}

double DeckOfCards::getProbability(int currentPoint) const{
    int matchPoint=21-currentPoint;
    //cout<<"Rest point to 21: "<<matchPoint<<endl;
    int matchNumberOfCards=rank_count(matchPoint);
    //cout<<matchNumberOfCards<<" "<<sizeOfDeck<<endl;
    return (double)matchNumberOfCards/sizeOfDeck;
}

void DeckOfCards::print() const{
    cout<<"--- Information about this deck of cards ---"<<endl;
    cout<<"Seria: "<<seria<<endl;
    cout<<"Size of deck: "<<sizeOfDeck<<endl;
    cout<<"--- Content ---"<<endl;
    for(int i=0;i<sizeOfDeck;i++){
        deckOfCards[i].print();
    }
    cout<<endl;
}

cardsValue DeckOfCards::findCardValue(int i) const{
    cardsValue result;
    switch (i) {
        case 0:
            result=two;
            break;
        case 1:
            result=three;
            break;
        case 2:
            result=four;
            break;
        case 3:
            result=five;
            break;
        case 4:
            result=six;
            break;
        case 5:
            result=seven;
            break;
        case 6:
            result=eight;
            break;
        case 7:
            result=nine;
            break;
        case 8:
            result=ten;
            break;
        case 9:
            result=jack;
            break;
        case 10:
            result=queen;
            break;
        case 11:
            result=king;
            break;
        case 12:
            result=ace;
            break;
    }
    return result;
}

cardsType DeckOfCards::findCardType(int i) const{
    cardsType result;
    switch (i) {
        case 0:
            result=spade;
            break;
        case 1:
            result=diamond;
            break;
        case 2:
            result=heart;
            break;
        case 3:
            result=club;
            break;
    }
    return result;
}

int DeckOfCards::occurenceOfCard(Card c, const Card* dCard, int dCardSize){
    int count=0;
    for(int i=0;i<dCardSize;i++){
        if(dCard[i].getType()==c.getType() && dCard[i].getValue()==c.getValue()){
            count++;
        }
    }
    return count;
}

bool DeckOfCards::havethisCard(Card c, const Card* dCard,int dCardSize){
    for(int i =0;i<dCardSize;i++){
        if(dCard[i].getType()==c.getType() && dCard[i].getValue()==c.getValue()){
            return true;
        }
    }
    return false;
}

bool DeckOfCards::haveThisSeriaNumber(const char* s,const Card* dCard,int dCardSize){
    for(int i=0;i<dCardSize;i++){
        if(strcmp(dCard[i].getSerialNumber(),s)==0){
            return true;
        }
    }
    return false;
}


void DeckOfCards::initDeckOfCard(int size){
    sizeOfDeck=size;
    deckOfCards= new Card[sizeOfDeck];
    int maxOccurance=((size-1)/52)+1;
    int repeatCard=sizeOfDeck-52;
    int maxCardType=4;
    int maxValue=13;
    srand(time(0));
    for(int i=0;i<sizeOfDeck;i++){
        int type=rand()%maxCardType;
        int value=rand()%maxValue;
        cardsType currentCardType=findCardType(type);
        cardsValue currentCardValue=findCardValue(value);
        Card tempCard;
        tempCard.setCardType(currentCardType);
        tempCard.setCardValue(currentCardValue);
        if(havethisCard(tempCard, deckOfCards, i) && repeatCard==0){
            do{
                type=rand()%maxCardType;
                value=rand()%maxValue;
                currentCardType=findCardType(type);
                currentCardValue=findCardValue(value);
                tempCard.setCardType(currentCardType);
                tempCard.setCardValue(currentCardValue);
            }while(havethisCard(tempCard, deckOfCards, i));
        }
        else if(havethisCard(tempCard, deckOfCards, i) && repeatCard>0){
            deckOfCards[i].setCardType(currentCardType);
            deckOfCards[i].setCardValue(currentCardValue);
            repeatCard--;
        }
        deckOfCards[i].setCardType(currentCardType);
        deckOfCards[i].setCardValue(currentCardValue);
        char* temp=generateChars(15-strlen(seria));
        //cout<<seria<<temp<<endl;
        char* uniqueSeria=new char[15+1];
        int j=0;
        for(int i=0;i<15;i++){
            if(i<strlen(seria)){
                uniqueSeria[i]=seria[i];
            }
            else{
                uniqueSeria[i]=temp[j];
                j++;
            }
        }
        if(haveThisSeriaNumber(uniqueSeria, deckOfCards, i)){
            do{
                delete []temp;
                temp=generateChars(15-strlen(seria));
                delete []uniqueSeria;
                uniqueSeria=new char[15+1];
                int j=0;
                for(int i=0;i<15;i++){
                    if(i<strlen(seria)){
                        uniqueSeria[i]=seria[i];
                    }
                    else{
                        uniqueSeria[i]=temp[j];
                        j++;
                    }
                }
            }while(haveThisSeriaNumber(uniqueSeria, deckOfCards, i));
        }
        deckOfCards[i].setSerialNumber(uniqueSeria);
        delete []temp;
        temp=nullptr;
        delete []uniqueSeria;
        uniqueSeria=nullptr;
    }
}

void DeckOfCards::copy(const DeckOfCards& other){
    sizeOfDeck=other.sizeOfDeck;
    strcpy(seria,other.seria);
    seria[Max_Seria-1]='\0';
    deckOfCards=new Card[other.sizeOfDeck];
    for(int i=0;i<sizeOfDeck;i++){
        deckOfCards[i]=other.deckOfCards[i];
    }
}

char* DeckOfCards::generateChars(int len){
    char* result;
    result=new char[len+1];
    char c;
    int r;
    //srand(time(0));
    for(int i=0;i<len;i++){
        r=rand()%26;
        //cout<<r<<endl;
        c='a'+r;
        result[i]=c;
    }
    return result;
}
