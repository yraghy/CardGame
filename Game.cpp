#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : deck(nullptr), players(nullptr), numOfPlayers(0) {}

Game::Game(Deck* deck,Player** gamePlayers, int count) : deck(deck), players(gamePlayers), numOfPlayers(count) {}
Game::~Game() {
        delete deck;
        for (int i = 0; i < numOfPlayers; ++i) {
            delete players[i];
        }
        delete[] players;
}

void Game::initializeGame() {
    Card** cards = new Card*[16];
    for (int i = 0; i < 8; ++i) {
        cards[i * 2] = new StandardCard(i + 1);
        cards[i * 2 + 1] = new StandardCard(i + 1);
    }

    deck = new Deck(cards, 16);
    deck->Shuffle();
    deck->displayGrid();
}
Deck* Game::getDeck() const {
    return deck;
}
