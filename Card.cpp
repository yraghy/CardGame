#include <iostream>
#include "Card.h"
using namespace std;

Card::Card() : number(0), faceUp(false), removed(false) {}
Card::Card(int number) : number(number), faceUp(false), removed(false) {}
Card::~Card() {}

int Card::getNumber() const { return number; }
bool Card::isFaceUp() const { return faceUp; }
bool Card::isRemoved() const { return removed; }
bool Card::isStandard() const { return number != 7 && number != 8; }
bool Card::isBonus() const { return false; }
bool Card::isPenalty() const { return false; }
void Card::reveal() { faceUp = true; }
void Card::hide() { faceUp = false; }
void Card::remove() {
    faceUp = false;
    removed = true;
}
void Card::display() const {
    if (isFaceUp())
        cout <<" "<<number<<" ";
    else if (isRemoved())
        cout << " x ";
    else
        cout << " * ";
}
bool Card::operator==(const Card& other) const {
    return this->number == other.number;
}

// StandardCard
StandardCard::StandardCard() : Card() {}
StandardCard::StandardCard(int num) : Card(num) {}
StandardCard::~StandardCard() {}
bool StandardCard::isBonus() const { return false; }
bool StandardCard::isPenalty() const { return false; }

// BonusCard
BonusCard::BonusCard(int num) : Card(7) {}
BonusCard::~BonusCard() {}
bool BonusCard::isBonus() const { return true; }
bool BonusCard::isPenalty() const { return false; }

// PenaltyCard
PenaltyCard::PenaltyCard(int num) : Card(8) {}
PenaltyCard::~PenaltyCard() {}
bool PenaltyCard::isBonus() const { return false; }
bool PenaltyCard::isPenalty() const { return true; }
