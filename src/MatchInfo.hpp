#ifndef MATCH_INFO_HPP
#define MATCH_INFO_HPP

#include "MatchResult.hpp"
#include "Goal.hpp"

class MatchInfo {
   public:
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace);
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace, std::list<Goal*> homeGoals, std::list<Goal*> awayGoals);

    // Getter methods
    std::string getMatchDate() const;
    std::string getMatchHour() const;
    std::string getMatchPlace() const;

    // Setter method
    void setMatchInfo(Team* homeTeam, Team* awayTeam, const unsigned short int homeTeamScore,
                      const unsigned short int awayTeamScore, const std::string& matchDate,
                      const std::string& matchTime, const std::string& matchPlace);

    // Method to get the match info as a string
    std::string showMatchInfo() const;

    // Method to add a goal to the match
    void addHomeGoal(Goal* goal);

    const std::list<Goal*>& getHomeGoals() const;

    void addAwayGoal(Goal* goal);

    const std::list<Goal*>& getAwayGoals() const;

   private:
    std::string matchDate;
    std::string matchTime;
    std::string matchPlace;
    std::list<Goal*> homeGoals;
    std::list<Goal*> awayGoals;
};

#endif // MATCH_INFO_HPP