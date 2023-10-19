#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <list>

#include "MatchResult.hpp"
#include "Team.hpp"

class League {
   public:
    League(std::list<Team*> teams);
    League(std::list<Team*> teams, std::list<MatchResult*> matchResults);
    ~League();

    void addTeams(std::list<Team*> teams);

    void addMatchResult(MatchResult* matchResult);

    void addMatchResults(std::list<MatchResult*> matchResults);

    void fillMatchResults(const std::string& filePath);

    const std::list<MatchResult*>& getMatchResults() const;

   private:
    std::list<Team*> teams;
    std::list<MatchResult*> matchResults;
};

#endif  // LEAGUE_HPP
