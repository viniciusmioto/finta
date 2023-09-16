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

   private:
    std::string name;
    std::list<MatchResult*> matchResults;
};

#endif  // TEAM_HPP