#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : deck(nullptr), players(nullptr), currentPlayer(nullptr), turnBit(0) {}

Game::Game(Deck* deck,Player** players) : deck(deck), players(players), currentPlayer(players[0]), turnBit(0) {}
Game::~Game() {
        delete deck;
        for (int i = 0; i < numOfPlayers; ++i) {
            delete players[i];
        }
        delete[] players;
}


void Game::initializeGame() {
    string name1, name2;
    cout<<"Enter Player #1 name: ";
    cin>>name1;
    cout<<endl;
    cout<<"Enter Player #2 name: ";
    cin>>name2;
    cout<<endl;
    auto *player1 = new Player(name1);
    auto *player2 = new Player(name2);
    players = new Player*[2];
    players[0] = player1;
    players[1] = player2;
    currentPlayer = players[0];
    Card** cards = new Card*[16];
    int j = 0;
    for (int i = 1; i <= 6; ++i) {
        cards[j] = new StandardCard(i);
        cards[++j] = new StandardCard(i);
        j++;
    }
    cards[j] = new BonusCard(7);
    cards[++j] = new BonusCard(7);
    cards[++j] = new PenaltyCard(8);
    cards[++j] = new PenaltyCard(8);
    deck = new Deck(cards, 16);
    deck->Shuffle();
    deck->displayGrid();
    startGameLoop();
}

Deck* Game::getDeck() const {
    return deck;
}

void Game::displayScores() const {
    cout<<players[0]->getName()<<"'s score: "<<players[0]->getScore()<<endl;
    cout<<players[1]->getName()<<"'s score: "<<players[1]->getScore()<<endl;
}

void Game::calculatePoints(Card *c1, Card *c2) const {
    int points;
    if(c1->isStandard() && c2->isStandard()){
        if(*c1 == *c2) currentPlayer->increaseScore(1);
        players[0]->displayScore();
        players[1]->displayScore();
        return;
    }
//    if(c1->getNumber() == 7 && c2->getNumber() == 7) HandleBonus(c1, c2);
//    else if(c1->getNumber() == 8 && c2->getNumber() == 8) HandlePenalty(c1, c2);

}

int Game::askCoordinates() {
    string coordinates;
    cout<<"Enter x,y coordinates: ";
    cin>>coordinates;
    int x = coordinates[0];
    int y = coordinates[2];
    int card;
    if(y==0) card = x-1;
    else{
        card = (x+(y*4))-1;
    }
    return card;
}

void Game::switchTurn() {
    cout<<"Press Enter to switch turns";
    cin.ignore();

}

bool Game::isGameOver() const {
    bool flag = true;
    for(int i = 0; i < deck->getSize(); i++){
        if(!deck->getCard(i)->isRemoved()){
            flag = false;
            break;
        }
    }
    return flag;
}

void Game::startGameLoop(){
    int card1 = askCoordinates();
    int card2 = askCoordinates();
    Card *c1 = deck->getCard(card1);
    Card *c2 = deck->getCard(card2);
    c1->reveal();
    c2->reveal();
    deck->displayGrid();
    calculatePoints(c1, c2);


    if(!isGameOver()) {
        switchTurn();
        startGameLoop();
    }
}

