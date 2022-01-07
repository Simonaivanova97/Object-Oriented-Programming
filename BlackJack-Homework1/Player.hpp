#ifndef Player_hpp
#define Player_hpp

#include "DeckOfCards.hpp"

class Player{
public:
    Player();
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    
    const char* getFirstName() const;
    const char* getSecondName() const;
    int getCurrentPoint() const;
    int getNumberOfWins() const;
    double getCoefficientOfWins() const;
    
    void setCurrentPoint(int& p);
    void setNumberOfWins(int nWins);
    void setCoefficientOfWins(double coefWins);
    void setAge(unsigned short a);
    void setFirstName(const char* fName);
    void setSecondName(const char* sName);
    void readPlayerName();
    
    bool sameNames(const char* fName,const char* sName);
    void print();
private:
    char* firstName;
    char* secondName;
    unsigned short age;
    int numberOfWins;
    double coefficientOfWins;
    int currentPoints;
    
    void copy(const Player& other);
};

#endif /* Player_hpp */
