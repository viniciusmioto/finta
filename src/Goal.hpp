#ifndef GOAL_HPP
#define GOAL_HPP

#include <string>
#include "Player.hpp"
#include "Team.hpp"

class Goal {
    public:
        Goal(Player* player, std::string minute, Team* team);
        Player* getPlayer() const;
        std::string getMinute() const;
        Team* getTeam() const;

        void setPlayer(Player* player);
        void setMinute(const std::string& minute);
        void setTeam(Team* team);

    private:
        Player* player;
        std::string minute;
        Team* team;
};

#endif // GOAL_HPP