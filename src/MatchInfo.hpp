#ifndef MATCH_INFO_HPP
#define MATCH_INFO_HPP

#include "MatchResult.hpp"
#include "Goal.hpp"

class MatchInfo {
   public:
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace);

    // Getter methods
    std::string getMatchDate() const;
    std::string getMatchTime() const;
    std::string getMatchPlace() const;

    // Setter method
    void setMatchInfo(Team* homeTeam, Team* awayTeam, const unsigned short int homeTeamScore,
                      const unsigned short int awayTeamScore, const std::string& matchDate,
                      const std::string& matchTime, const std::string& matchPlace);

    // Method to get the match info as a string
    std::string getMatchInfo() const;

    // Method to add a goal to the match
    void addGoal(Goal* goal);

    // Method to get the goals as a string
    std::string getGoals() const;

   private:
    std::string matchDate;
    std::string matchTime;
    std::string matchPlace;
    std::list<Goal*> goals;
};

#endif // MATCH_INFO_HPP