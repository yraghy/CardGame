#include "Game.h"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Game::Game() : deck(nullptr), players(nullptr), currentPlayer(nullptr), turnBit(0) {}

Game::Game(Deck* deck, Player** players) : deck(deck), players(players), currentPlayer(players[0]), turnBit(0) {}

Game::~Game() {
    delete deck;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
    delete[] players;
}

void Game::initializeGame() {
    string name1, name2;
    cout << "Enter Player #1 name: ";
    cin >> name1;
    cout << "\nEnter Player #2 name: ";
    cin >> name2;
    cout<<endl;

    auto* player1 = new Player(name1);
    auto* player2 = new Player(name2);
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
    cout << players[0]->getName() << "'s score: " << players[0]->getScore() << endl;
    cout << players[1]->getName() << "'s score: " << players[1]->getScore() << endl;
}

void Game::calculatePoints(Card* c1, Card* c2) {
    if (c1->isStandard() && c2->isStandard()) {
        if (*c1 == *c2) {
            currentPlayer->increaseScore(1);
            c1->remove();
            c2->remove();
            cout << "Match found! " << currentPlayer->getName() << " gains 1 point and plays again.\n";
            return; // Player gets another turn.
        }
    } else if (c1->isBonus() && c2->isBonus()) {
        int choice;
        cout << "Two Bonus Cards revealed! Choose an option:\n";
        cout << "1. Gain 2 points\n2. Gain 1 point and take another turn\n";
        cin >> choice;
        if (choice == 1) {
            currentPlayer->increaseScore(2);
        } else {
            currentPlayer->increaseScore(1);
            turnBit = (turnBit + 1) % 2; // Keep current player.
        }
        c1->remove();
        c2->remove();
        return;
    } else if (c1->isPenalty() && c2->isPenalty()) {
        int choice;
        cout << "Two Penalty Cards revealed! Choose an option:\n";
        cout << "1. Lose 2 points\n2. Lose 1 point and skip the next turn\n";
        cin >> choice;
        if (choice == 1) {
            currentPlayer->decreaseScore(2);
        } else {
            currentPlayer->decreaseScore(1);
            turnBit = (turnBit + 1) % 2; // Skip the next turn.
        }
        c1->remove();
        c2->remove();
        return;
    } else if ((c1->isBonus() && c2->isPenalty()) || (c1->isPenalty() && c2->isBonus())) {
        cout << "Bonus and Penalty cards cancel each other out. Both cards are removed from the grid.\n";
        c1->remove();
        c2->remove();
        return;
    } else if (c1->isBonus() || c2->isBonus()) {
        currentPlayer->increaseScore(1);
        if (c1->isBonus()) c1->remove();
        else c2->remove();
        cout << "Bonus Card revealed! " << currentPlayer->getName() << " gains 1 point.\n";
    } else if (c1->isPenalty() || c2->isPenalty()) {
        currentPlayer->decreaseScore(1);
        cout << "Penalty Card revealed! " << currentPlayer->getName() << " loses 1 point.\n";
    }

    c1->hide();
    c2->hide();
}

int Game::askCoordinates() {
    string coordinates;
    while (true) {
        cout << "Enter x,y coordinates (1-4 for both x and y): ";
        cin >> coordinates;
        cout<<endl;
        if (coordinates.size() == 3 && coordinates[1] == ',' &&
            isdigit(coordinates[0]) && isdigit(coordinates[2])) {
            int x = coordinates[0] - '1';
            int y = coordinates[2] - '1';
            if (x >= 0 && x < 4 && y >= 0 && y < 4) {
                return (y * 4 + x);
            }
        }
        cout << "Invalid input. Please try again.\n";
    }
}

void Game::switchTurn() {
    turnBit = (turnBit + 1) % 2;
    currentPlayer = players[turnBit];
    cout << "Turn ends. Switching to " << currentPlayer->getName() << "'s turn. Press Enter to continue.";
    cin.ignore();
    cin.get();
}

bool Game::isGameOver() const {
    for (int i = 0; i < deck->getSize(); i++) {
        if (!deck->getCard(i)->isRemoved()) {
            return false;
        }
    }
    return true;
}

void Game::playTurn() {
    cout << currentPlayer->getName() << "'s turn!\n";
    deck->displayGrid();
    displayScores();

    int card1 = askCoordinates();
    int card2 = askCoordinates();
    while (card1 == card2 || deck->getCard(card1)->isRemoved() || deck->getCard(card2)->isRemoved()) {
        cout << "Invalid selection. Please choose two different, available cards.\n";
        card1 = askCoordinates();
        card2 = askCoordinates();
    }
    cout<<endl;
    Card* c1 = deck->getCard(card1);
    Card* c2 = deck->getCard(card2);
    c1->reveal();
    c2->reveal();
    deck->displayGrid();

    calculatePoints(c1, c2);

    // Switch turn unless the current player gets another turn.
    if (!(turnBit % 2 == 1)) {
        turnBit = (turnBit + 1) % 2;
        currentPlayer = players[turnBit];
        cout << "Turn ends. Switching to " << currentPlayer->getName() << "'s turn. Press Enter to continue.";
        cin.ignore();
        cin.get();
        cout<<endl;
    }
}

void Game::startGameLoop() {
    while (!isGameOver()) {
        playTurn();
    }

    cout << "Game Over!\n";
    displayScores();
    if (players[0]->getScore() > players[1]->getScore()) {
        cout << players[0]->getName() << " wins with " << players[0]->getScore() << " points!\n";
    } else if (players[0]->getScore() < players[1]->getScore()) {
        cout << players[1]->getName() << " wins with " << players[1]->getScore() << " points!\n";
    } else {
        cout << "It's a tie! Both players have " << players[0]->getScore() << " points.\n";
    }
}
