#include "Playlist.h"
int main() {
    Playlist p;
    p.addSong(1, "Song A", 3.5);
    p.addSong(2, "Song B", 4.0);
    p.addSong(3, "Song C", 2.8);
    p.display();
    p.playNext();
    p.playNext();
    p.playPrevious();
    p.deleteSong("Song B");
    p.display();
    p.reversePlaylist();
    p.display();
    return 0;
}