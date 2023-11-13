#include "Player.hpp"

Player::Player(std::string name)
    : Person{name}, goalsScored{0}, yellowCards{0}, redCards{0} {}

unsigned short Player::getGoalsScored() const { return this->goalsScored; }

void Player::setGoalsScored(const unsigned short goalsScored) {
    this->goalsScored = goalsScored;
}

unsigned short Player::getYellowCards() const { return this->yellowCards; }

void Player::setYellowCards(const unsigned short yellowCards) {
    this->yellowCards = yellowCards;
}

unsigned short Player::getRedCards() const { return this->redCards; }

void Player::setRedCards(const unsigned short redCards) {
    this->redCards = redCards;
}
