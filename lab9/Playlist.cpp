#include "Playlist.h"
Song::Song(int id, string name, float dur) {
    songID = id;
    songName = name;
    duration = dur;
    next = NULL;
    prev = NULL;
}
Playlist::Playlist() {
    head = tail = current = NULL;
}
void Playlist::addSong(int id, string name, float duration) {
    Song* newSong = new Song(id, name, duration);

    if (head == NULL) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}
void Playlist::deleteSong(string name) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    Song* temp = head;
    while (temp != NULL) {
        if (temp->songName == name) {
            if (temp == head) {
                head = head->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            if (current == temp)
                current = temp->next;
                delete temp;
            cout << "Song deleted.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Song not found.\n";
}
void Playlist::playNext() {
    if (current == NULL) {
        cout << "No song to play.\n";
        return;
    }
    if (current->next != NULL) {
        current = current->next;
        cout << "Now playing: " << current->songName << endl;
    } else {
        cout << "Already at last song.\n";
    }
}
void Playlist::playPrevious() {
    if (current == NULL) {
        cout << "No song to play.\n";
        return;
    }
    if (current->prev != NULL) {
        current = current->prev;
        cout << "Now playing: " << current->songName << endl;
    } else {
        cout << "Already at first song.\n";
    }
}
void Playlist::reversePlaylist() {
    Song* temp = NULL;
    Song* currentNode = head;
    while (currentNode != NULL) {
        temp = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = temp;
        currentNode = currentNode->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }

    cout << "Playlist reversed.\n";
}
void Playlist::display() {
    Song* temp = head;
    if (temp == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    while (temp != NULL) {
        cout << "ID: " << temp->songID
             << ", Name: " << temp->songName
             << ", Duration: " << temp->duration << " mins\n";
        temp = temp->next;
    }
