#include "Fact.hpp"

Fact::Fact(const Player& player, const std::string& time, const Team& team)
    : player(player), time(time), team(team) {}

const Player& Fact::getPlayer() const { return player; }

const std::string& Fact::getTime() const { return time; }

void Fact::setPlayer(const Player& player) { this->player = player; }

void Fact::setTime(const std::string& time) { this->time = time; }

const Team& Fact::getTeam() const { return team; }

void Fact::setTeam(const Team& team) { this->team = team; }

