#include "Fact.hpp"

Fact::Fact(Player* player, std::string minute)
    : player{player}, minute{minute} {}

Player* Fact::getPlayer() const { return this->player; }

void Fact::setPlayer(Player* player) { this->player = player; }

std::string Fact::getMinute() const { return this->minute; }

void Fact::setMinute(const std::string& minute) { this->minute = minute; }

std::ostream& operator<<(std::ostream& os, const Fact& fact) {
    os << fact.player->getName() << " " << fact.minute;

    return os;
}
