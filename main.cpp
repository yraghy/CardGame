#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
using namespace std;


class Card {
protected:
    int number;
    bool faceUp;

public:
    Card() : number(0), faceUp(false) {}
    Card(int number) : number(number), faceUp(false) {}
    virtual ~Card() {}

    int getNumber() { return number; }
    void setNumber(int num) { number = num; }
    bool isFaceUp() { return faceUp; }
    void setFaceUp(bool up) { faceUp = up; }
//    void display() { cout << "Number: " << number << " Face Up: " << faceUp << endl; }
    void display() {
        if(faceUp) cout<<getNumber();
        else cout<<" * ";
    }
};

class StandardCard : public Card {
public:
    StandardCard() : Card() {}
    StandardCard(int num) : Card(num) {}
    ~StandardCard() {}
};

class BonusCard : public Card {
public:
    BonusCard() : Card() {}
    BonusCard(int num) : Card(num) {}
    ~BonusCard() {}
};

class PenaltyCard : public Card {
public:
    PenaltyCard() : Card() {}
    PenaltyCard(int num) : Card(num) {}
    ~PenaltyCard() {}


};

class Deck {
private:
    Card** cards;
    int size;

public:
    Deck() : cards(nullptr), size(0) {}
    Deck(Card** initialCards, int initialSize) : cards(initialCards), size(initialSize) {}
    ~Deck() {
        for (int i = 0; i < size; ++i) {
            delete cards[i];
        }
        delete[] cards;
    }

    void Shuffle() {
        for (int i = 0; i < size; ++i) {
            int randIndex = rand() % size;
            std::swap(cards[i], cards[randIndex]);
        }
    }


    void displayGrid() const {
        const int GRID_SIZE = 4;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                int index = i * GRID_SIZE + j;
                cards[index]->display();
            }
            cout << endl;
        }
    }

    Card* getCard(int index) const {
        if (index >= 0 && index < size) {
            return cards[index];
        }
        return nullptr;
    }

    int getSize() const { return size; }
};

class Player {
private:
    string name;
    int score;

public:
    Player() : name(""), score(0) {}
    Player(string name) : name(name), score(0) {}
    ~Player() {}

    string getName() { return name; }
    void setName(string name) { this->name = name; }
    int getScore() { return score; }
    void setScore(int newScore) { score = newScore; }
    void displayScore() {
        cout << "Player: " << name << " Score: " << score << endl;

    }
};

class Game {
private:
    Deck* deck;
    Player** players;
    int playerCount;

public:
    Game() : deck(nullptr), players(nullptr), playerCount(0) {}
    Game(Player** gamePlayers, int count) : deck(nullptr), players(gamePlayers), playerCount(count) {}
    ~Game() {
        delete deck;
        for (int i = 0; i < playerCount; ++i) {
            delete players[i];
        }
        delete[] players;
    }

    void initializeGame() {
        Card** cards = new Card*[16];
        for (int i = 0; i < 8; ++i) {
            cards[i * 2] = new StandardCard(i + 1);
            cards[i * 2 + 1] = new StandardCard(i + 1);
        }

        deck = new Deck(cards, 16);
        deck->Shuffle();
        deck->displayGrid();
    }

    Deck* getDeck() const {
        return deck;
    }
};



int main() {
    Game game;
    game.initializeGame();
    return 0;
}
