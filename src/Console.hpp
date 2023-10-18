#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

#include "MatchResult.hpp"
#include "Team.hpp"

const std::string RESET_TEXT{"\033[0m"};
const std::string UNDERLINE{"\033[4m"};
const std::string WHITE_BG{"\033[7m"};
const std::string YELLOW_TXT{"\033[33m"};
const std::string GREEN_BG{"\033[42m"};
const std::string RED_BG{"\033[45m"};
const std::string BLUE_BG{"\033[46m"};
const std::string ORANGE_BG{"\033[47m"};

class Console {
   public:
    Console();
    static void printMatchResults(Team& team);
    static void printMatchResults(std::list<MatchResult*>& matchResults);
    static void printTable(std::list<Team*>& teams);
    static bool compareTeamsByPoints(Team* homeTeam, Team* awayTeam);
};

#endif  // CONSOLE_HPP
