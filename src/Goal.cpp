#include "Goal.hpp"

Goal::Goal(Player* player, std::string minute, Team* team, bool isOwnGoal)
    : minute{minute}, team{team}, isOwnGoal{isOwnGoal} {
    setPlayer(player);
}

Player* Goal::getPlayer() const { return player; }

std::string Goal::getMinute() const { return minute; }

Team* Goal::getTeam() const { return team; }

void Goal::setPlayer(Player* player) {
    this->player = player;
    if (!isOwnGoal)
        this->player->setGoalsScored(this->player->getGoalsScored() + 1);
}

void Goal::setMinute(const std::string& minute) { this->minute = minute; }

void Goal::setTeam(Team* team) { this->team = team; }
