#include <iostream>
using namespace std;
class Player {
public:
    int playerID;
    int score;
    Player* next;

    Player(int id);
};
class Game {
private:
    Player* current;
public:
    Game();
    void addPlayer(int id);
    void removePlayer(int id);
    void nextTurn();
    void skipPlayer();
    void display();
    void checkWinner();
};
