#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Deck* deck;
    Player** players;
    Player* currentPlayer;
    int turnBit; //is either 0 or 1 indicating which player is the current player
    const int numOfPlayers = 2;
    int remainingCards;
public:
    Game();
    Game(Deck* deck, Player** players);
    ~Game();
    void initializeGame();
    Deck* getDeck() const;
    void displayScores() const;
    void calculatePoints(Card* c1, Card* c2);
    int HandleBonus(Card* c1, Card* c2) const;
    int HandlePenalty(Card* c1, Card* c2) const;
    void playTurn();
    void startGameLoop();
    int askCoordinates();
    void switchTurn();
    bool isGameOver() const;
    void checkRemainingCards();
};
#endif //GAME_H
