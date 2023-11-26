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
    League(std::string name);
    League(std::string name, std::list<Team*> teams);
    League(std::string name, std::list<Team*> teams, std::list<Match*> matches);

    virtual ~League();

    std::string getName() const;
    void setName(std::string name);

    const std::list<Team*>& getTeams() const;
    void addTeams(std::list<Team*> teams);
    Team* findOrCreateTeam(const std::string& teamName);

    const std::list<Match*>& getMatches() const;
    void addMatch(Match* matches);
    void fillMatches(const std::string& filePath);

   private:
    unsigned short convertPercentageToInt(const std::string& percentage);

    std::string name;
    std::list<Team*> teams;
    std::list<Match*> matches;
};

#endif  // LEAGUE_HPP
