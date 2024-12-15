#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() : name(""), score(0) {}

Player::Player(string name) : name(name), score(0) {}

Player::~Player() {delete this;}

string Player::getName() const { return name; }

int Player::getScore() const { return score; }

void Player::setScore(int newScore) { score = newScore; }

void Player::increaseScore(int points) { score += points; }

void Player::displayScore() const {
    cout << "Player: " << name << " Score: " << score << endl;
}
