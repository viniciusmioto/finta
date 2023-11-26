#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

#include "InvalidMatchDayException.hpp"
#include "InvalidMatchIdException.hpp"
#include "Match.hpp"
#include "Team.hpp"

static const std::string RESET_TEXT{"\033[0m"};
static const std::string UNDERLINE{"\033[4m"};
static const std::string WHITE_BG{"\033[7m"};
static const std::string RED_TXT{"\033[31m"};
static const std::string GREEN_TXT{"\033[32m"};
static const std::string YELLOW_TXT{"\033[33m"};
static const std::string PURPLE_TXT{"\033[34m"};
static const std::string CYAN_TXT{"\033[36m"};
static const std::string GREEN_BG{"\033[42m"};
static const std::string YELLOW_BG{"\033[43m"};
static const std::string PURPLE_BG{"\033[44m"};
static const std::string RED_BG{"\033[45m"};
static const std::string BLUE_BG{"\033[46m"};
static const std::string ORANGE_BG{"\033[47m"};
static constexpr int NUM_WIDTH = 3;
static constexpr int NAME_WIDTH = 13;

class Console {
   public:
    Console() = delete;
    static void printMenu();
    static void printTeams(const std::list<Team*>& teams);
    static void printPlayers(const std::list<Player*>& players,
                             const unsigned short int parameter);
    static void printStaff(const std::list<Staff*>& staff);
    static void printMatchResults(const Team& team);
    static void printMatchResults(const std::list<Match*>& matches);
    static void printMatchResults(const std::list<Match*>& matches,
                                  unsigned short matchDay);
    static void printMatchDetails(const Match& match);
    static void printTable(const std::list<Team*>& teams);

    static unsigned short askMatchId();
    static unsigned short askMatchDay();

   private:
    static bool compareTeams(const Team* homeTeam, const Team* awayTeam);
    static bool comparePlayersByGoals(const Player* player1,
                                      const Player* player2);
    static bool comparePlayersByYellowCards(const Player* player1,
                                            const Player* player2);
    static bool comparePlayersByRedCards(const Player* player1,
                                         const Player* player2);
    static bool comparePlayersByName(const Player* player1,
                                     const Player* player2);
};

#endif  // CONSOLE_HPP
