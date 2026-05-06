#include <iostream>
using namespace std;
class Song {
public:
    int songID;
    string songName;
    float duration;
    Song* next;
    Song* prev;
    Song(int id, string name, float dur);
};
class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;
public:
    Playlist();
    void addSong(int id, string name, float duration);
    void deleteSong(string name);
    void playNext();
    void playPrevious();
    void reversePlaylist();
    void display();
};