#include "Game.h"
Player::Player(int id) {
    playerID = id;
    score = 0;
    next = NULL;
}
Game::Game() {
    current = NULL;
}
void Game::addPlayer(int id) {
    Player* newPlayer = new Player(id);

    if (current == NULL) {
        current = newPlayer;
        newPlayer->next = newPlayer;
    } else {
        Player* temp = current;

        while (temp->next != current)
            temp = temp->next;

        temp->next = newPlayer;
        newPlayer->next = current;
    }
}
void Game::removePlayer(int id) {
    if (current == NULL) {
        cout << "No players.\n";
        return;
    }
    Player* temp = current;
    Player* prev = NULL;

    do {
        if (temp->playerID == id) {
            if (temp->next == temp) {
                delete temp;
                current = NULL;
                return;
            }
            if (temp == current) {
                Player* last = current;
                while (last->next != current)
                    last = last->next;

                current = current->next;
                last->next = current;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;

    } while (temp != current);
    cout << "Player not found.\n";
}
void Game::nextTurn() {
    if (current != NULL) {
        current = current->next;
        cout << "Player " << current->playerID << "'s turn\n";
    }
}
void Game::skipPlayer() {
    if (current != NULL) {
        current = current->next->next;
        cout << "Skipped! Now Player " << current->playerID << "'s turn\n";
    }
}
void Game::display() {
    if (current == NULL) {
        cout << "No players.\n";
        return;
    }
    Player* temp = current;
    do {
        cout << "Player ID: " << temp->playerID << endl;
        temp = temp->next;
    } while (temp != current);
}
void Game::checkWinner() {
    if (current != NULL && current->next == current) {
        cout << "Winner is Player " << current->playerID << endl;
    }
}