#ifndef GOAL_HPP
#define GOAL_HPP

#include <string>
#include "Player.hpp"
#include "Team.hpp"

class Goal {
    public:
        Goal(Player* player, std::string time, Team* team);
        Player* getPlayer() const;
        std::string getTime() const;
        Team* getTeam() const;

        void setPlayer(Player* player);
        void setTime(const std::string& time);
        void setTeam(Team* team);

    private:
        Player* player;
        std::string time;
        Team* team;
};

#endif // GOAL_HPP