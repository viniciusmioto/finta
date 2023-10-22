#ifndef GOAL_HPP
#define GOAL_HPP

#include "Fact.hpp"

class Goal : public Fact {
    public:
     Goal(const Player& player, const std::string& time, const Team& team);
    
     virtual void setPlayer(const Player& player) override;
     void setTime(const std::string& time);
     void setTeam(const Team& team);
    
    private:
     Player player;
     std::string time;
     Team team;
};

#endif // GOAL_HPP