#include "Player.hpp"

Player::Player(std::string name) : Person{name} {}

Player::Player(std::string name, std::string position,
               uint8_t jerseyNumber)
    : Person{name}, position{position}, jerseyNumber{jerseyNumber} {}

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
