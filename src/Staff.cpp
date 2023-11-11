#include "Staff.hpp"

Staff::Staff(std::string name) : Person(name) {
    matches = 0;
    wins = 0;
    draws = 0;
    losses = 0;
}

unsigned short Staff::getMatches() const { return this->matches; }

void Staff::setMatches(const unsigned short matches) {
    this->matches = matches;
}

unsigned short Staff::getWins() const { return this->wins; }

void Staff::setWins(const unsigned short wins) { this->wins = wins; }

unsigned short Staff::getDraws() const { return this->draws; }

void Staff::setDraws(const unsigned short draws) { this->draws = draws; }

unsigned short Staff::getLosses() const { return this->losses; }

void Staff::setLosses(const unsigned short losses) { this->losses = losses; }

unsigned short Staff::getResultPercentage() const {
    return (this->getWins() * 3 + this->getDraws()) * 100 / (this->getMatches() * 3);
}