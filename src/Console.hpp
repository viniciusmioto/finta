#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

#include "Match.hpp"
#include "Team.hpp"

const std::string RESET_TEXT{"\033[0m"};
const std::string UNDERLINE{"\033[4m"};
const std::string WHITE_BG{"\033[7m"};
const std::string RED_TXT{"\033[31m"};
const std::string GREEN_TXT{"\033[32m"};
const std::string YELLOW_TXT{"\033[33m"};
const std::string PURPLE_TXT{"\033[34m"};
const std::string CYAN_TXT{"\033[36m"};
const std::string GREEN_BG{"\033[42m"};
const std::string YELLOW_BG{"\033[43m"};
const std::string PURPLE_BG{"\033[44m"};
const std::string RED_BG{"\033[45m"};
const std::string BLUE_BG{"\033[46m"};
const std::string ORANGE_BG{"\033[47m"};
const int NUM_WIDTH = 3;
const int NAME_WIDTH = 13;

class Console {
   public:
    Console();
    static void printMenu();
    static void printTeams(const std::list<Team*>& teams);
    static void printPlayers(const std::list<Player*>& players);
    static void printGoal(const Goal& goal);
    static void printGoals(const std::list<Goal*>& goals, const Team& team);
    static void printMatchResults(const Team& team);
    static void printMatchResults(const std::list<Match*>& matches);
    static void printMatchResults(const std::list<Match*>& matches,
                                  unsigned short matchDay);
    static void printMatchDetails(const Match& match);
    static void printTable(const std::list<Team*>& teams);
    static bool compareTeams(const Team* homeTeam, const Team* awayTeam);
};

#endif  // CONSOLE_HPP
