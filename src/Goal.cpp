#include "Goal.hpp"

Goal::Goal(Player* player, std::string time, Team* team)
    : time{time}, team{team} {
        setPlayer(player);
    }

Player* Goal::getPlayer() const { return player; }

std::string Goal::getTime() const { return time; }

Team* Goal::getTeam() const { return team; }

void Goal::setPlayer(Player* player) { this->player = player; }

void Goal::setTime(const std::string& time) { this->time = time; }

void Goal::setTeam(Team* team) { this->team = team; }
