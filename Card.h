#ifndef CARD_H
#define CARD_H

class Card {
private:
    const int number;
    bool faceUp;
    bool removed;

public:
    Card();
    Card(int num);
    virtual ~Card();


    int getNumber() const;
    bool isFaceUp() const;
    bool isRemoved() const;
    void reveal ();
    void hide();
    void remove();
    virtual void display() const;
};

class StandardCard : public Card {
public:
    StandardCard();
    StandardCard(int num);
    ~StandardCard();
};

class BonusCard : public Card {
public:
    BonusCard(int num);
    ~BonusCard();
};

class PenaltyCard : public Card {
public:
    PenaltyCard(int num);
    ~PenaltyCard();
};

#endif