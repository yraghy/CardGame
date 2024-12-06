#ifndef CARD_H
#define CARD_H

class Card {
private:
    int number;
    bool faceUp;

public:
    Card();
    Card(int num);
    virtual ~Card();


    int getNumber() const;
    void setNumber(int num);
    bool isFaceUp() const;
    void setFaceUp(bool up);


    virtual void display() const;
    virtual int getPoints() const = 0;
};

class StandardCard : public Card {
public:
    StandardCard();
    StandardCard(int num);
    ~StandardCard();

    int getPoints() const override;
};

class BonusCard : public Card {
public:
    BonusCard();
    BonusCard(int num);
    ~BonusCard();

    int getPoints() const override;
};

class PenaltyCard : public Card {
public:
    PenaltyCard();
    PenaltyCard(int num);
    ~PenaltyCard();

    int getPoints() const override;
};

#endif