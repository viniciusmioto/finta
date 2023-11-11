#ifndef FACT_HPP
#define FACT_HPP

#include <string>

#include "Player.hpp"
#include "Team.hpp"

class Fact {
    friend std::ostream& operator<<(std::ostream& os, const Fact& fact);

   public:
    Fact(Player* player, std::string minute);
    virtual ~Fact() = default;

    Player* getPlayer() const;
    std::string getMinute() const;
    Team* getTeam() const;

    virtual void setPlayer(Player* player);
    void setMinute(const std::string& minute);
    void setTeam(Team* team);

   private:
    Player* player;
    std::string minute;
    Team* team;
};

#endif  // FACT_HPP