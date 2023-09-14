#ifndef MATCH_RESULT_HPP
#define MATCH_RESULT_HPP

#include <string>
#include <cstdint>
#include "Team.hpp"


class MatchResult {
   public:
    MatchResult(Team* team1, Team* team2, uint8_t score1,
                uint8_t score2);

    // Getter methods
    unsigned int getId();
    Team* getTeam1();
    Team* getTeam2();
    uint8_t getScore1();
    uint8_t getScore2();

    // Setter method
    void setMatchResult(Team* team1, Team* team2, uint8_t score1,
                        uint8_t score2);

    // Method to get the match result as a string
    std::string getMatchResult();

   private:
    static unsigned long int nextId;
    unsigned long int id;
    Team* team1;
    Team* team2;
    uint8_t score1;
    uint8_t score2;
};

#endif  // MATCH_RESULT_HPP
