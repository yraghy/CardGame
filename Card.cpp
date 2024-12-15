#include <iostream>
#include "Card.h"
using namespace std;

    Card::Card() : number(0), faceUp(false), removed(false) {}
    Card::Card(int number) : number(number), faceUp(false), removed(false) {}
    Card::~Card() {}

    int Card::getNumber() const { return number; }
    bool Card::isFaceUp() const { return faceUp; }
    bool Card::isRemoved() const { return removed; }
    void Card::reveal() { faceUp = true; }
    void Card::hide() { faceUp = false; }
    void Card::remove(){
        faceUp = false;
        removed = true;
    }
    void Card::display() const {
        if(this->isFaceUp()) cout<<getNumber();
        else if(this->isRemoved()) cout<< " x ";
        else cout<<" * ";
    }

//Standard Card
    StandardCard::StandardCard() : Card() {}
    StandardCard::StandardCard(int num) : Card(num) {}
    StandardCard::~StandardCard() {}

//Bonus Card
    BonusCard::BonusCard(int num) : Card(7) {}
    BonusCard::~BonusCard() {}

//Penalty Card
    PenaltyCard::PenaltyCard(int num) : Card(8) {}
    PenaltyCard::~PenaltyCard() {}