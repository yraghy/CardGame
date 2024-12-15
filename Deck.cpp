#include <iostream>
#include "Deck.h"
using namespace std;

    Deck::Deck() : cards(nullptr) {}
    Deck::Deck(Card** cards, int size) : cards(cards), size(size) {}
    Deck::~Deck() {
        for (int i = 0; i < size; ++i) {
            delete cards[i];
        }
        delete[] cards;
    }

    void Deck::Shuffle() {
        for (int i = 0; i < size; ++i) {
            int randIndex = rand() % size;
            std::swap(cards[i], cards[randIndex]);
        }
    }

    void Deck::displayGrid() const {
        const int GRID_SIZE = 4;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                int index = i * GRID_SIZE + j;
                cards[index]->display();
            }
            cout << endl;
        }
    }

    void Deck::resetGrid() const {
        for (int i = 0; i < size; ++i) {
            cards[i]->hide();
        }
    }

    Card* Deck::getCard(int index) const {
        if (index >= 0 && index < size) {
            return cards[index];
        }
        return nullptr;
    }

    void Deck::removeCard(int index) {
        card[index]->remove();
        card[index]->display();
    }

    int Deck::getSize() const { return size; }
