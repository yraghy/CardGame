#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
private:
    Card** cards;
    const int gridSize = 4;
    int size;

public:
    Deck();
    ~Deck();
    Deck(Card** cards, int size);

    void Shuffle();
    void displayGrid() const;
    void resetGrid() const;
    Card* getCard(int index) const;
    void removeCard(int index);
    int getSize() const;

};
#endif //DECK_H
