#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
private:
    Card** cards;
    const int gridSize = 4;

public:
    Deck();
    ~Deck();
    Deck(Card** cards);

    void Shuffle();
    void displayGrid();
    Card* getCard(int row, int col) const;
    int getSize() const;

};



#endif //DECK_H
