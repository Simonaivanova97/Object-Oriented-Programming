#include <iostream>
#include "Playlist.hpp"
using namespace std;

void printSongBetweenInterval(const Playlist& p,int firstInex, int secondIndex){
    for(int i=0;i<p.getNumberOfSong();i++){
        if(p.getSong(i+1).getLen()>=firstInex && p.getSong(i+1).getLen()<=secondIndex){
            p.getSong(i+1).print();
        }
    }
}

void sortByLen(Playlist& p){
    int i,j,minIndex;
    for(int i=0;i<p.getNumberOfSong()-1;i++){
        minIndex=i;
        for(int j=i+1;j<p.getNumberOfSong();j++){
            if(p.getArrayOfSongs()[j].getLen()<p.getArrayOfSongs()[minIndex].getLen()){
                minIndex=j;
            }
        }
        p.swapSong(minIndex, i);
    }
}

int main() {
    Song s1("It's my life","Bon Jovi","Crush",345);
    Song s2("Jalebi Baby","Tesher","Jalebi Baby",191);
    Song s3("Stayin Alive","Bee Gees","Album1",345);
    Song s4("Dance monkey","Tones and I","The Kids Are Coming",209);
    Song s5("Friday","Riton X Nightcrawlers","Album1",304);
    Song s6("Only you","Gims ft. dhurata","ALbum2",265);
    Song s7("Old town road","Lil Nas x ft. Billy Ray Cyrus","Albuym2",402);
    Song s8("House arrest","Sofi Tukker and Gorgon city","Album1",329);
    Song s9("Take my breath","The weeknd","Album1",273);
    Song s10("Love again","Dua Lipa","Album3",300);
    Song s11("Detente","Claydee","Album2",257);
    
    Song arr[11]={s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11};
    Playlist p("First PlayList",arr,11,11);
    p.print();

    int index;
    cout<<"Index of song?: ";
    cin>>index;
    (p.getSong(index)).print();
    
    cout<<"\nLength between 300 and 400"<<endl;
    printSongBetweenInterval(p, 300, 400);
    
    cout<<"\nSort songs in playlist by length"<<endl;
    sortByLen(p);
    p.print();
    return 0;
}

