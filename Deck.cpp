#include <iostream>
#include <random>
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
        //(Mersenne Twister)
        std::random_device rd;  // Obtain a random seed from hardware or system entropy (huhhh)
        std::mt19937 gen(rd());  //Mersenne Twister engine using the seed from random_device
        std::uniform_int_distribution<> dis(0, size - 1);  // Distribution for picking a random index

        // Perform the shuffle using the Mersenne Twister random number generator
        for (int i = 0; i < size; ++i) {
            int randIndex = dis(gen);  // Generate a random index using the distribution
            std::swap(cards[i], cards[randIndex]);  // Swap the current card with the randomly selected one
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
        cards[index]->remove();
        cards[index]->display();
    }

    int Deck::getSize() const { return size; }
