#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>
#include "Team.hpp"
#include "MatchResult.hpp"

class Console {
    public:
        Console();
        static void printMatchResults(Team& team);
        static void printMatchResults(std::list<MatchResult*>& matchResults);
        static void printTable(std::list<Team*>& teams);
        static bool compareTeamsByPoints(Team* homeTeam, Team* awayTeam);
};

#endif // CONSOLE_HPP
