#include "Player.hpp"
Player::Player(){
        firstName=new char[strlen("Simona"+1)];
        if(!firstName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(firstName,"Simona");
        
        secondName=new char[strlen("Ivanova")+1];
        if(!secondName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(secondName,"Ivanova");
        
        age=23;
        currentPoints=0;
        numberOfWins=0;
        coefficientOfWins=0.0;
    }
    
Player::Player(const Player& other){
        copy(other);
    }
    Player& Player::operator=(const Player& other){
        if(this!=&other){
            delete[]firstName;
            delete []secondName;
            copy(other);
        }
        return *this;
    }
Player::~Player(){
        delete []firstName;
        delete []secondName;
    }
    
    void Player::readPlayerName(){
        char fName[50];
        //cout<<"Enter player's name: ";
        cin>>fName;
        char sName[50];
        cin>>sName;
        cin.ignore();
        
        //cout<<strlen(fName)<<" "<<strlen(sName)<<endl;
        fName[strlen(fName)+1]='\0';
        sName[strlen(sName)+1]='\0';
        
        int a;
        do{
            cout<<"Enter age of player: ";
            cin>>a;
        }while(a<18 || a>90);
        setFirstName(fName);
        setSecondName(sName);
        setAge(a);
    }
    
    const char* Player::getFirstName() const{
        return firstName;
    }
    const char* Player::getSecondName() const{
        return secondName;
    }
    int Player::getCurrentPoint() const{
        return currentPoints;
    }
    int Player::getNumberOfWins() const{
        return numberOfWins;
    }
    double Player::getCoefficientOfWins() const{
        return coefficientOfWins;
    }
    
    void Player::setCurrentPoint(int& p){
        currentPoints=p;
    }
    void Player::setNumberOfWins(int nWins){
        numberOfWins=nWins;
    }
    void Player::setCoefficientOfWins(double coefWins){
        coefficientOfWins=coefWins;
    }
    void Player::setAge(unsigned short a){
        age=a;
    }
    void Player::setFirstName(const char* fName){
        delete[]firstName;
        firstName=new char[strlen(fName)+1];
        if(!firstName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(firstName, fName);
    }
    void Player::setSecondName(const char* sName){
        delete[]secondName;
        secondName=new char[strlen(sName)+1];
        if(!secondName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(secondName, sName);
    }
    
    bool Player::sameNames(const char* fName,const char* sName){
        if(strcmp(firstName,fName)==0 && strcmp(secondName,sName)==0){
            return true;
        }
        return false;
    }
    
    void Player::print(){
        cout<<"--- Player ---"<<endl;
        cout<<"Name: "<<firstName<<" "<<secondName<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Current point: "<<currentPoints<<endl;
        cout<<"Number of wins: "<<numberOfWins<<endl;
        cout<<"Coefficient of wins: "<<coefficientOfWins<<endl;
    }
    
    void Player::copy(const Player& other){
        firstName=new char[strlen(other.firstName)+1];
        if(!firstName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(firstName,other.firstName);
        
        secondName=new char[strlen(other.secondName)+1];
        if(!secondName){
            cout<<"Error related with dynamic memory!"<<endl;
            exit(1);
        }
        strcpy(secondName,other.secondName);
        
        age=other.age;
        currentPoints=other.currentPoints;
        numberOfWins=other.numberOfWins;
        coefficientOfWins=other.coefficientOfWins;
    }
