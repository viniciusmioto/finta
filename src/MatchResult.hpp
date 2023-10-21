#ifndef MATCH_RESULT_HPP
#define MATCH_RESULT_HPP

#include <string>
#include <cstdint>
#include "Team.hpp"

class MatchResult {
   public:
    MatchResult(Team* homeTeam, Team* awayTeam, unsigned short int homeTeamScore,
                unsigned short int awayTeamScore, unsigned short matchDay);

    // Getter methods
    unsigned int getId() const;
    
    Team* getHomeTeam() const;
    
    Team* getAwayTeam() const;
    
    unsigned short int getHomeTeamScore() const;
    
    unsigned short int getAwayTeamScore() const;

    unsigned short getMatchDay() const;

    void setMatchDay(const unsigned short matchDay);

    // Setter method
    void setMatchResult(Team* homeTeam, Team* awayTeam, const unsigned short int homeTeamScore,
                        const unsigned short int awayTeamScore);

    // Method to get the match result as a string
    std::string getMatchResult() const;

   private:
    static unsigned long int nextId;
    unsigned long int id;
    unsigned short matchDay;
    Team* homeTeam;
    Team* awayTeam;
    unsigned short int homeTeamScore;
    unsigned short int awayTeamScore;
};

#endif  // MATCH_RESULT_HPP
