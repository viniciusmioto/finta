#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Person.hpp"

class Player : public Person {
   public:
    Player(std::string name);

    unsigned short getGoalsScored() const;
    void setGoalsScored(const unsigned short goalsScored);

    unsigned short getYellowCards() const;
    void setYellowCards(const unsigned short yellowCards);

    unsigned short getRedCards() const;
    void setRedCards(const unsigned short redCards);

   private:
    unsigned short goalsScored;
    unsigned short yellowCards;
    unsigned short redCards;
};

#endif  // PLAYER_HPP