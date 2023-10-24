#ifndef MATCH_RESULT_HPP
#define MATCH_RESULT_HPP

#include <string>
#include <cstdint>
#include "Team.hpp"

class MatchResult {
   public:
    MatchResult(Team* homeTeam, Team* awayTeam, unsigned short int homeTeamScore,
                unsigned short int awayTeamScore);

    
    Team* getHomeTeam() const;
    
    Team* getAwayTeam() const;
    
    unsigned short int getHomeTeamScore() const;
    
    unsigned short int getAwayTeamScore() const;

    // Method to get the match result as a string
    std::string getMatchResult() const;

   private:
    Team* homeTeam;
    Team* awayTeam;
    unsigned short int homeTeamScore;
    unsigned short int awayTeamScore;
};

#endif  // MATCH_RESULT_HPP
