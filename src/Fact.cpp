#include "Fact.hpp"

Fact::Fact(Player* player, std::string minute)
    : player{player}, minute{minute} {}

Player* Fact::getPlayer() const { return player; }

std::string Fact::getMinute() const { return minute; }

void Fact::setPlayer(Player* player) { this->player = player; }

void Fact::setMinute(const std::string& minute) { this->minute = minute; }
