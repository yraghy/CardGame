#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() : name(""), score(0) {}
Player::Player(string name) : name(name), score(0) {}
Player::~Player() {}

string Player::getName() const { return name; }

int Player::getScore() const { return score; }

void Player::setScore(int newScore) { score = newScore; }

void Player::increaseScore(int points) { score += points; }

void Player::decreaseScore(int points) {
    score -= points;
    if (score < 0) score = 0; // Prevent negative score.
}

void Player::displayScore() const {
    cout << "Player: " << name << " Score: " << score << endl;
}
