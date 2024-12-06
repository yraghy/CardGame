#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Deck* deck;
    Player** players;
    int numOfPlayers;
public:
    Game();
    Game(Deck* deck, Player** players, int numOfPlayers);
    ~Game();
    void initializeGame();
    Deck* getDeck() const;
};








#endif //GAME_H
