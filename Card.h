#ifndef CARD_H
#define CARD_H

class Card {
protected:
    int number;
    bool faceUp;
    bool removed;

public:
    Card();
    Card(int number);
    virtual ~Card();

    int getNumber() const;
    bool isFaceUp() const;
    bool isRemoved() const;
    virtual bool isStandard() const;
    virtual bool isBonus() const; // New virtual method
    virtual bool isPenalty() const; // New virtual method
    void reveal();
    void hide();
    void remove();
    void display() const;

    bool operator==(const Card& other) const;
};

class StandardCard : public Card {
public:
    StandardCard();
    StandardCard(int num);
    ~StandardCard();
    bool isBonus() const override;
    bool isPenalty() const override;
};

class BonusCard : public Card {
public:
    BonusCard(int num);
    ~BonusCard();
    bool isBonus() const override;
    bool isPenalty() const override;
};

class PenaltyCard : public Card {
public:
    PenaltyCard(int num);
    ~PenaltyCard();
    bool isBonus() const override;
    bool isPenalty() const override;
};

#endif // CARD_H
