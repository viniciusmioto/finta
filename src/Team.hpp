#ifndef TEAM_HPP
#define TEAM_HPP

#include <list>
#include <string>

#include <iostream>

#include "Staff.hpp"
#include "Player.hpp"

class MatchResult; // Forward declaration

class Team {
   public:
    Team(std::string name);
    ~Team();

    std::string getName() const;
    void setName(const std::string& name);

    const std::list<MatchResult*>& getMatchResults() const;
    void addMatchResult(MatchResult* matchResult);

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

    const std::list<Staff*>& getStaff() const;
    void addStaff(Staff* staff);

    Staff* findOrCreateStaff(const std::string& staffName);
    void updateStaffStats(Staff *staffMember, short result);

    const std::list<Player*>& getPlayers() const;
    void addPlayer(Player* player);
    Player* findOrCreatePlayer(const std::string& playerName);

    short int getGoalsAgainst() const;
    void addGoalsAgainst(const short int goalsAgainst);

    short int getGoalDifference() const;
    void setGoalDifference(const short int goalDifference);

    bool operator==(const Team& otherTeam) const;
    bool operator==(const std::string& otherTeamName) const;
    bool operator>(const Team& otherTeam) const;

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
    std::list<Staff*> staff;
    std::list<Player*> players;
};

#endif  // TEAM_HPP