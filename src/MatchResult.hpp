#ifndef MATCH_RESULT_HPP
#define MATCH_RESULT_HPP

#include <string>
#include <cstdint>
#include "Team.hpp"
#include "Colors.hpp"

class MatchResult {
   public:
    MatchResult(Team* homeTeam, Team* awayTeam, unsigned short int homeTeamScore,
                unsigned short int awayTeamScore);

    // Getter methods
    unsigned int getId();
    Team* getHomeTeam();
    Team* getAwayTeam();
    unsigned short int getHomeTeamScore();
    unsigned short int getAwayTeamScore();

    // Setter method
    void setMatchResult(Team* homeTeam, Team* awayTeam, unsigned short int homeTeamScore,
                        unsigned short int awayTeamScore);

    // Method to get the match result as a string
    std::string getMatchResult();

   private:
    static unsigned long int nextId;
    unsigned long int id;
    Team* homeTeam;
    Team* awayTeam;
    unsigned short int homeTeamScore;
    unsigned short int awayTeamScore;
};

#endif  // MATCH_RESULT_HPP
