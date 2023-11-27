#include "Goal.hpp"

using namespace finta;

Goal::Goal(Player* player, std::string minute, bool isOwnGoal)
    : Fact(player, minute), isOwnGoal{isOwnGoal} {
    player->setGoalsScored(player->getGoalsScored() + 1);
}

bool Goal::getIsOwnGoal() const { return this->isOwnGoal; }

void Goal::setIsOwnGoal(bool isOwnGoal) { this->isOwnGoal = isOwnGoal; }
