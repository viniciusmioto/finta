#include "Goal.hpp"

Goal::Goal(Player* player, std::string minute, bool isOwnGoal)
    : Fact(player, minute), isOwnGoal{isOwnGoal} {
    player->setGoalsScored(player->getGoalsScored() + 1);
}

Goal::~Goal() {}

bool Goal::getIsOwnGoal() const { return isOwnGoal; }

void Goal::setIsOwnGoal(bool isOwnGoal) { this->isOwnGoal = isOwnGoal; }
