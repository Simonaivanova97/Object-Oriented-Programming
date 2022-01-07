#include "Playlist.hpp"

void Playlist::copyPlaylist(const Playlist& other){
    playlistName=new char[strlen(other.playlistName)+1];
    assert(playlistName!=NULL);
    strcpy(playlistName,other.playlistName);
    capacityOfPlaylist=other.capacityOfPlaylist;
    numberOfSong=other.numberOfSong;
    arr=new Song[capacityOfPlaylist];
    assert(arr!=NULL);
    for(int i=0;i<numberOfSong;i++){
        arr[i]=other.arr[i];
    }
}
Playlist::Playlist(){
    playlistName=new char[strlen("New playlist")+1];
    assert(playlistName!=NULL);
    strcpy(playlistName, "New playlist");
    int max;
    cout<<"Enter capacity of playlist: ";
    cin>>max;
    capacityOfPlaylist=max;
    numberOfSong=0;
    arr=new Song[capacityOfPlaylist];
    assert(arr!=NULL);
}
Playlist::Playlist(const char* pN, const Song* a, int nS, int cA){
    playlistName=new char[strlen(pN)+1];
    assert(playlistName!=NULL);
    strcpy(playlistName, pN);
    capacityOfPlaylist=cA;
    numberOfSong=nS;
    arr=new Song[capacityOfPlaylist];
    assert(arr!=NULL);
    for(int i=0;i<numberOfSong;i++){
        arr[i]=a[i];
    }
}
Playlist::Playlist(const Playlist& other){
    copyPlaylist(other);
}
Playlist& Playlist::operator=(const Playlist& other){
    if(this!=&other){
        delete []playlistName;
        delete []arr;
        copyPlaylist(other);
    }
    return *this;
}
Playlist::~Playlist(){
    delete []playlistName;
    delete []arr;
}

int Playlist::getNumberOfSong() const{
    return numberOfSong;
}
const Song* Playlist::getArrayOfSongs() const{
    return arr;
}
Song Playlist::getSong(int index) const{
    Song s;
    if(index<=0 || index>numberOfSong){
        cout<<"Invalid index!"<<endl;
    }
    else{
        for(int i=0;i<numberOfSong;i++){
            if(index==i+1){
                s=arr[i];
            }
        }
    }
    return s;
}
void Playlist::print() const{
    cout<<"---------- Information about "<<playlistName<<". ---------- "<<endl;
    cout<<"\nNumber os songs: "<<numberOfSong<<endl;
    cout<<"\n---------- Content of playlist. ----------"<<endl;
    for(int i=0;i<numberOfSong;i++){
        arr[i].print();
        cout<<endl;
    }
}
    
void Playlist::swapSong(int firstIndex, int secondIndex){
    Song temp=arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}

