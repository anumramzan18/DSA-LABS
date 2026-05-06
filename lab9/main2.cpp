#include "Game.h"
int main() {
    Game g;
    g.addPlayer(1);
    g.addPlayer(2);
    g.addPlayer(3);
    g.display();
    g.nextTurn();
    g.skipPlayer();
    g.removePlayer(2);
    g.display();
    g.removePlayer(1);
    g.checkWinner();
    return 0;
}