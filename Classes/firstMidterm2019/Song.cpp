#include "Song.hpp"

void Song::copySong(const Song& other){
    songName=new char[strlen(other.songName)+1];
    assert(songName!=NULL);
    strcpy(songName, other.songName);
    songAuthor=new char[strlen(other.songAuthor)+1];
    assert(songAuthor!=NULL);
    strcpy(songAuthor, other.songAuthor);
    nameOfAlbum=new char[strlen(other.nameOfAlbum)+1];
    assert(nameOfAlbum!=NULL);
    strcpy(nameOfAlbum, other.nameOfAlbum);
    len=other.len;
}
Song::Song(){
    songName=new char[strlen("Unknown")+1];
    assert(songName!=NULL);
    strcpy(songName, "Unknown");
    songAuthor=new char[strlen("Unknown")+1];
    assert(songAuthor!=NULL);
    strcpy(songAuthor, "Unknown");
    nameOfAlbum=new char[strlen("Unknown")+1];
    assert(nameOfAlbum!=NULL);
    strcpy(nameOfAlbum, "Unknown");
    len=0;
}
Song::Song(const char* sN, const char* sA, const char* nA, int l){
    songName=new char[strlen(sN)+1];
    assert(songName!=NULL);
    strcpy(songName, sN);
    songAuthor=new char[strlen(sA)+1];
    assert(songAuthor!=NULL);
    strcpy(songAuthor, sA);
    nameOfAlbum=new char[strlen(nA)+1];
    assert(nameOfAlbum!=NULL);
    strcpy(nameOfAlbum, nA);
    len=l;
}
Song::Song(const Song& other){
    copySong(other);
}
Song& Song::operator=(const Song& other){
    if(this!=&other){
        delete []songName;
        delete []songAuthor;
        delete []nameOfAlbum;
        copySong(other);
    }
    return *this;
}
Song::~Song(){
    delete []songName;
    delete []songAuthor;
    delete []nameOfAlbum;
}
const char* Song::getSongName() const{
    return songName;
}
const char* Song::getSongAuthor() const{
    return songAuthor;
}
const char* Song::getNameOfAlbum() const{
    return nameOfAlbum;
}
int Song::getLen() const{
    return len;
}
void Song::setSongName(const char* sN){
    delete []songName;
    songName=new char[strlen(sN)+1];
    assert(songName!=NULL);
    strcpy(songName, sN);
}
void Song::setSongAuthor(const char* sA){
    delete []songAuthor;
    songAuthor=new char[strlen(sA)+1];
    assert(songAuthor!=NULL);
    strcpy(songAuthor, sA);
}
void Song::setNameOfAlbum(const char* nA){
    delete []nameOfAlbum;
    nameOfAlbum=new char[strlen(nA)+1];
    assert(nameOfAlbum!=NULL);
    strcpy(nameOfAlbum, nA);
}
void Song::setLen(int l){
    len=l;
}
void Song::print() const{
    cout<<"Song name: "<<songName<<endl;
    cout<<"Song author: "<<songAuthor<<endl;
    cout<<"Name of album: "<<nameOfAlbum<<endl;
    cout<<"Length of song: "<<len<<endl;
}

