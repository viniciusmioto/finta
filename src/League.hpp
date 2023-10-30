#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <list>

#include "Match.hpp"
#include "Team.hpp"

class League {
   public:
    League(std::list<Team*> teams);
    League(std::list<Team*> teams, std::list<Match*> matches);

    void addTeams(std::list<Team*> teams);

    void addMatch(Match* matches);

    void addGoalScorers(Team* team,
                                const boost::property_tree::ptree& goalScorers,
                                MatchInfo* matchInfo, Team* scorerTeam);

    void fillMatches(const std::string& filePath);

    const std::list<Match*>& getMatches() const;

    Team* findOrCreateTeam(const std::string& teamName);

    const std::list<Team*>& getTeams() const;

   private:
    std::list<Team*> teams;
    std::list<Match*> matches;
};

#endif  // LEAGUE_HPP
