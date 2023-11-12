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
    virtual void setPlayer(Player* player);

    std::string getMinute() const;
    void setMinute(const std::string& minute);

   private:
    Player* player;
    std::string minute;
};

#endif  // FACT_HPP