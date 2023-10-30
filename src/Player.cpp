#include "Player.hpp"

Player::Player(std::string name) : Person{name} {
    position = "";
    jerseyNumber = 0;
    goalsScored = 0;
}

Player::Player(std::string name, std::string position,
               uint8_t jerseyNumber)
    : Person{name}, position{position}, jerseyNumber{jerseyNumber} {
    goalsScored = 0;
    }

std::string Player::getPosition() const {
    return position;
}

void Player::setPosition(const std::string& position) {
    this->position = position;
}

uint8_t Player::getJerseyNumber() const {
    return jerseyNumber;
}

void Player::setJerseyNumber(const uint8_t jerseyNumber) {
    this->jerseyNumber = jerseyNumber;
}

unsigned short Player::getGoalsScored() const {
    return goalsScored;
}

void Player::setGoalsScored(const unsigned short goalsScored) {
    this->goalsScored = goalsScored;
}