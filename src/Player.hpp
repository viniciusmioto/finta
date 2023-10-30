#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Person.hpp"

class Player : public Person {
   public:
    Player(std::string name);
    Player(std::string name, std::string position, uint8_t jerseyNumber);

    std::string getPosition() const;
    void setPosition(const std::string& position);

    uint8_t getJerseyNumber() const;
    void setJerseyNumber(const uint8_t jerseyNumber);

    unsigned short getGoalsScored() const;
    void setGoalsScored(const unsigned short goalsScored);

   private:
    std::string position;
    uint8_t jerseyNumber;
    unsigned short goalsScored;
};

#endif  // PLAYER_HPP