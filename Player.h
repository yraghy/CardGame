#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;l

class Player {
private:
    string name;
    int score;

public:
    Player();
    Player(const string name, int score);
    ~Player();

    string getName();
    int getScore();
    void setScore(int score);

    void displayScore();



};


#endif //PLAYER_H
