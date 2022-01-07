#ifndef Song_hpp
#define Song_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Song{
public:
    Song();
    Song(const char*, const char*, const char*, int);
    Song(const Song&);
    Song& operator=(const Song&);
    ~Song();
    
    const char* getSongName() const;
    const char* getSongAuthor() const;
    const char* getNameOfAlbum() const;
    int getLen() const;
    
    void setSongName(const char*);
    void setSongAuthor(const char*);
    void setNameOfAlbum(const char*);
    void setLen(int);
    
    void print() const;
private:
    char* songName;
    char* songAuthor;
    char* nameOfAlbum;
    int len;
    
    void copySong(const Song&);
};

#endif /* Song_hpp */
