#ifndef GOAL_HPP
#define GOAL_HPP

#include <string>

#include "Fact.hpp"
#include "Player.hpp"
#include "Team.hpp"

class Goal : virtual public Fact {
   public:
    Goal(Player* player, std::string minute, bool isOwnGoal = false);

    virtual ~Goal() = default;

    bool getIsOwnGoal() const;
    void setIsOwnGoal(bool isOwnGoal);

   private:
    bool isOwnGoal;
};

#endif  // GOAL_HPP