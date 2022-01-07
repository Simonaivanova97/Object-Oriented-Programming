#include <iostream>
#include<fstream>
#include"Player.hpp"

double convertCharToDouble(const char* number){
    int digitBeforeDot=0;
    int digitAfterDot=0;
    int i=0;
    while(number[i]!='.' && number[i]!='\0'){
        digitBeforeDot++;
        i++;
    }
    if(number[i]=='.'){
        i++;
        while(number[i]!='\0'){
            digitAfterDot++;
            i++;
        }
    }
    int degree=(digitBeforeDot+digitAfterDot)-1;
    int numerator=0;
    i=0;
    while(number[i]!='\0'){
        if(number[i]!='.'){
            numerator+=((number[i]-48)*pow(10,degree));
            degree--;
        }
        i++;
    }
    return numerator/pow(10,digitAfterDot);
}

int main() {
    ifstream file;
    file.open("users.txt");
    
    if(!file){
        cout<<"File could not be opened!"<<endl;
        exit(1);
    }
    else{
        string row;
        bool haveName=false;
        ofstream fout("temp.txt");
        if(file.peek() != std::ifstream::traits_type::eof()){
            while(getline(file,row)){
                cout<<row<<endl;
            }
            file.clear();
            file.seekg(0);
        }
        cout<<"Chose a player or enter a new player: ";
        Player p1;
        p1.readPlayerName();
        double lose;
        if(file.peek() != std::ifstream::traits_type::eof()){
                while(getline(file,row)){
                char fName[50];
                char sName[50];
                int i=0;
                while(row[i]!=' '){
                    fName[i]=row[i];
                    i++;
                }
                fName[i]='\0';
                i++;
                int j=0;
                while(row[i]!=' '){
                    sName[j]=row[i];
                    j++;
                    i++;
                }
                sName[j]='\0';
                i++;
                int l=0;
                char numWins[10];
                while(row[i]!=' '){
                    numWins[l]=row[i];
                    i++;
                    l++;
                }
                numWins[l]='\0';
                i++;
                int nWin=convertCharToDouble(numWins);
                char doubleNumber[15];
                int k=0;
                while(row[i]!='\0'){
                    doubleNumber[k]=row[i];
                    k++;
                    i++;
                }
                doubleNumber[k]='\0';
                double coefWin=convertCharToDouble(doubleNumber);
                Player tempFromFile;
                tempFromFile.setFirstName(fName);
                tempFromFile.setSecondName(sName);
                tempFromFile.setNumberOfWins(nWin);
                tempFromFile.setCoefficientOfWins(coefWin);
            
                if(p1.sameNames(tempFromFile.getFirstName(), tempFromFile.getSecondName())){
                    haveName=true;
                    p1.setFirstName(tempFromFile.getFirstName());
                    p1.setSecondName(tempFromFile.getSecondName());
                    p1.setNumberOfWins(tempFromFile.getNumberOfWins());
                    p1.setCoefficientOfWins(tempFromFile.getCoefficientOfWins());
                }
            }
        }
        p1.print();
        bool playerLoose=false;
        bool dealerLoose=false;
        bool playerWin=false;
        bool dealerWin=false;
        int sizeOfDeck;
        //Player p;
        Player d;
        do{
            cout<<"Choose the size of the deck: ";
            cin>>sizeOfDeck;
        }while(sizeOfDeck<=0);
        DeckOfCards deck=DeckOfCards(sizeOfDeck);
        //deck.print();
        
        cout<<"Start!"<<endl;
        Card firstCard=deck.getFirstCard();
        deck.deleteFirstCard();
        int point=firstCard.point();
        int pointDealer=d.getCurrentPoint();
        firstCard.print();
        cout<<"(Points: "<<point<<")"<<endl;
        char option[12];
        bool playerPlay=true;
        bool dealerPlay=false;
        do{
            cout<<"Hit/Stand/Probability"<<endl;
            cin>>option;
            option[11]='\0';
            if(strcmp(option,"Hit")==0){
                Card tempFirstCard=deck.getFirstCard();
                deck.deleteFirstCard();
                point+=tempFirstCard.point();
                p1.setCurrentPoint(point);
                tempFirstCard.print();
                cout<<"(Points: "<<p1.getCurrentPoint()<<")"<<endl;
            }
            else if(strcmp(option,"Probability")==0){
                cout<<deck.getProbability(point)<<endl;
            }
            else{
                playerPlay=false;
                dealerPlay=true;
            }
        }while(playerPlay && p1.getCurrentPoint()<=21);
        
        if(p1.getCurrentPoint()<21){
        cout<<"The dealer's draw: ";
        do{
            if(d.getCurrentPoint()<17){
                Card tempFirstCard=deck.getFirstCard();
                deck.deleteFirstCard();
                pointDealer+=tempFirstCard.point();
                d.setCurrentPoint(pointDealer);
                tempFirstCard.print();
            }
            else{
                dealerPlay=false;
            }
        }while(dealerPlay);
        
        cout<<"(Points: "<<d.getCurrentPoint()<<")"<<endl;
        }
        if (p1.getCurrentPoint()>21){
            playerLoose=true;
            dealerWin=true;
            //cout<<"You lose!"<<endl;
        }
        else if(p1.getCurrentPoint()==21 || d.getCurrentPoint()>21){
            playerLoose=false;
            dealerWin=false;
            //cout<<"You win!"<<endl;
        }
        else if (d.getCurrentPoint()>=17 && d.getCurrentPoint()<=21){
            if(p1.getCurrentPoint()>=d.getCurrentPoint()){
                playerLoose=false;
                dealerWin=false;
            }
            else{
                playerLoose=true;
                dealerWin=true;
            }
        }
        int one=1;
        double first=static_cast<double>(one)-p1.getCoefficientOfWins();
        double second=static_cast<double>(p1.getNumberOfWins());
        double thirth=first*second;
        lose=thirth/p1.getCoefficientOfWins();
        if(isnan(lose)){
            lose=0.0;
        }
        //cout<<"Number of lose: "<<lose<<endl;
        if(playerLoose==true){
            cout<<"You lose!"<<endl;
            double coef=p1.getNumberOfWins()/(p1.getNumberOfWins()+lose+1);
            p1.setCoefficientOfWins(coef);
        }
        else if (dealerWin==false){
            cout<<"You win!"<<endl;
            double coef=(p1.getNumberOfWins()+1)/(p1.getNumberOfWins()+lose+1);
            p1.setCoefficientOfWins(coef);
            p1.setNumberOfWins(p1.getNumberOfWins()+1);
        }
        //p1.print();
        if(!haveName){
            file.clear();
            file.seekg(0);
            string row;
            while(getline(file, row)){
                fout<<row<<endl;
            }
            fout<<p1.getFirstName()<<" "<<p1.getSecondName()<<" "<<p1.getNumberOfWins()<<" "<<
            p1.getCoefficientOfWins()<<endl;
        }
        else{
            file.clear();
            file.seekg(0);
            string row;
            while(getline(file, row)){
                char fName[50];
                char sName[50];
                int i=0;
                while(row[i]!=' '){
                    fName[i]=row[i];
                    i++;
                }
                fName[i]='\0';
                i++;
                int j=0;
                while(row[i]!=' '){
                    sName[j]=row[i];
                    j++;
                    i++;
                }
                sName[j]='\0';
                if(p1.sameNames(fName, sName)){
                    fout<<p1.getFirstName()<<" "<<p1.getSecondName()<<" "<<p1.getNumberOfWins()<<" "<<
                    p1.getCoefficientOfWins()<<endl;
                }
                else{
                    fout<<row<<endl;
                }
            }
        }
        fout.close();
        file.close();
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    return 0;
}

