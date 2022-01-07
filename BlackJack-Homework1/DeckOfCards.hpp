#ifndef DeckOfCards_hpp
#define DeckOfCards_hpp

#include"Card.hpp"
class DeckOfCards{
public:
    DeckOfCards();
    DeckOfCards(int k);
    DeckOfCards(int k, const char* s);
    DeckOfCards(const DeckOfCards& other);
    DeckOfCards& operator=(const DeckOfCards& other);
    ~DeckOfCards();
    
    void draw();
    void swap(int firstIndex, int secondIndex);
    int suit_count(const cardsType& type);
    void deleteFirstCard();
    Card getFirstCard() const;
    int rank_count(int value) const;
    double getProbability(int currentPoint) const;
    
    void print() const;
private:
    Card* deckOfCards;
    char seria[Max_Seria];
    int sizeOfDeck;
    
    cardsValue findCardValue(int i) const;
    cardsType findCardType(int i) const;
    int occurenceOfCard(Card c, const Card* dCard, int dCardSize);
    bool havethisCard(Card c, const Card* dCard,int dCardSize);
    void initDeckOfCard(int size);
    void copy(const DeckOfCards& other);
    char* generateChars(int len);
    bool haveThisSeriaNumber(const char* s,const Card* dCard,int dCardSize);
};

#endif /* DeckOfCards_hpp */
