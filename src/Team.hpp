#ifndef TEAM_HPP
#define TEAM_HPP

#include <list>
#include <string>

#include <iostream>

#include "Person.hpp"
#include "Player.hpp"

class MatchResult; // Forward declaration

class Team {
   public:
    Team(std::string name);
    
    std::string getName() const;
    void setName(const std::string& name);

    void addMatchResult(MatchResult* matchResult);
    const std::list<MatchResult*>& getMatchResults() const;

    unsigned short int getPoints() const;
    void addPoints(const unsigned short int points);

    unsigned short int getWins() const;
    void addWins(const unsigned short int wins);

    unsigned short int getDraws() const;
    void addDraws(const unsigned short int draws);

    unsigned short int getLosses() const;
    void addLosses(const unsigned short int losses);
    
    unsigned short int getGoals() const;
    void addGoals(const unsigned short int goals);

    void addStaff(Person* person);
    const std::list<Person*>& getStaff() const;

    void addPlayer(Player* player);
    const std::list<Player*>& getPlayers() const;
    Player* findOrCreatePlayer(const std::string& playerName);

    short int getGoalsAgainst() const;
    void addGoalsAgainst(const short int goalsAgainst);

    short int getGoalDifference() const;
    void setGoalDifference(const short int goalDifference);

   private:
    std::string name;
    unsigned short int points;
    unsigned short int wins;
    unsigned short int draws;
    unsigned short int losses;
    unsigned short int goals;
    short int goalsAgainst;
    short int goalDifference;
    std::list<MatchResult*> matchResults;
    std::list<Person*> staff;
    std::list<Player*> players;
};

#endif  // TEAM_HPP