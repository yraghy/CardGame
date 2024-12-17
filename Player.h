#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    int score;

public:
    Player();
    Player(string name);
    ~Player();

    string getName() const;
    int getScore() const;
    void setScore(int newScore);
    void increaseScore(int points);
    void decreaseScore(int points); // New method
    void displayScore() const;
};

#endif // PLAYER_H
