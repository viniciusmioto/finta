#include <iostream>

#include "Console.hpp"
#include "League.hpp"
#include "MatchResult.hpp"
#include "Team.hpp"

int main() {
    std::list<Team*> teams;

    std::list<MatchResult*> matchResults;

    League league(teams, matchResults);

    league.fillMatchResults("../data/Brasileirao2022.json");

    Console::showMenu();

    int option;
    std::cout << " Option: ";
    std::cin >> option;
    std::string teamName;

    while (option != 0) {
        switch (option) {
            case 1:
                system("clear");
                Console::printMatchResults(league.getMatchResults());

                break;
            case 2:
                unsigned short int matchDay;

                system("clear");
                std::cout << WHITE_BG
                          << " Choose a match day (1 - 38): " << RESET_TEXT;
                std::cin >> matchDay;

                if (matchDay < 1 || matchDay > 38) {
                    std::cout << YELLOW_TXT << "Invalid match day" << RESET_TEXT
                              << std::endl;
                    break;
                }

                Console::printMatchResults(league.getMatchResults(), matchDay);

                break;
            case 3:
                system("clear");
                Console::showTeams(teams);
                std::cout << WHITE_BG << " Choose a team:" << RESET_TEXT
                          << std::endl;

                std::cin.ignore();
                std::getline(std::cin, teamName);
                for (Team* team : teams)
                    if (teamName == team->getName())
                        Console::printMatchResults(*team);

                break;
            case 9:
                system("clear");
                Console::printTable(teams);

                break;
            default:
                std::cout << "Invalid option" << std::endl;

                break;
        }

        Console::showMenu();

        std::cout << WHITE_BG << " Option: " << RESET_TEXT;
        std::cin >> option;
    }

    return 0;
}