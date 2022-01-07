#ifndef Playlist_hpp
#define Playlist_hpp

#include <stdio.h>
#include "Song.hpp"

class Playlist{
public:
    Playlist();
    Playlist(const char*, const Song*, int, int);
    Playlist(const Playlist&);
    Playlist& operator=(const Playlist&);
    ~Playlist();
    
    int getNumberOfSong() const;
    const Song* getArrayOfSongs() const;
    Song getSong(int index) const;
    void print() const;
        
    void swapSong(int firstIndex, int secondIndex);

private:
    char* playlistName;
    Song* arr;
    int numberOfSong;
    int capacityOfPlaylist;
    
    void copyPlaylist(const Playlist&);
};

#endif /* Playlist_hpp */

