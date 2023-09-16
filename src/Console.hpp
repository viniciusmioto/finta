#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

#include "MatchResult.hpp"
#include "Team.hpp"

const std::string reset_text{"\033[0m"};
const std::string underline_text{"\033[4m"};
const std::string background_text{"\033[7m"};
const std::string green_bg_text{"\033[42m"};
const std::string red_bg_text{"\033[45m"};

class Console {
   public:
    Console();
    static void printMatchResults(Team& team);
    static void printMatchResults(std::list<MatchResult*>& matchResults);
    static void printTable(std::list<Team*>& teams);
    static bool compareTeamsByPoints(Team* homeTeam, Team* awayTeam);
};

#endif  // CONSOLE_HPP
