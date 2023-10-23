#ifndef FACT_HPP
#define FACT_HPP

#include <string>

#include "Player.hpp"
#include "Team.hpp"

class Fact {
   public:
    Fact(const Player& player, const std::string& time, const Team& team);

    const Player& getPlayer() const;
    const std::string& getTime() const;
    const Team& getTeam() const;

    virtual void setPlayer(const Player& player);
    void setTime(const std::string& time);
    virtual void setTeam(const Team& team);

   private:
    Player player;
    std::string time;
    Team team;
};

#endif  // FACT_HPP