#ifndef TEAM_HPP
#define TEAM_HPP

#include <list>
#include <string>

class MatchResult; // Forward declaration

class Team {
   public:
    Team(std::string name);
    
    std::string getName();
    void setName(std::string name);

    void addMatchResult(MatchResult* matchResult);
    std::list<MatchResult*>& getMatchResults();

    unsigned short int getPoints();
    void addPoints(unsigned short int points);

    unsigned short int getWins();
    void addWins(unsigned short int wins);

    unsigned short int getDraws();
    void addDraws(unsigned short int draws);

    unsigned short int getLosses();
    void addLosses(unsigned short int losses);
    
    unsigned short int getGoals();
    void addGoals(unsigned short int goals);

   private:
    std::string name;
    unsigned short int points;
    unsigned short int wins;
    unsigned short int draws;
    unsigned short int losses;
    unsigned short int goals;
    std::list<MatchResult*> matchResults;
};

#endif  // TEAM_HPP