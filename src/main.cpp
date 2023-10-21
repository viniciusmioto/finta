#include <iostream>

#include "Console.hpp"
#include "League.hpp"
#include "MatchResult.hpp"
#include "Team.hpp"

int main() {
    Team amg{"América-MG"};
    Team cap{"Athletico-PR"};
    Team acg{"Atlético-GO"};
    Team cam{"Atlético-MG"};
    Team afc{"Avaí"};
    Team bfr{"Botafogo"};
    Team rbb{"Bragantino"};
    Team csc{"Ceará SC"};
    Team sccp{"Corinthians"};
    Team cfc{"Coritiba"};
    Team cec{"Cuiabá"};
    Team crf{"Flamengo"};
    Team ffc{"Fluminense"};
    Team fec{"Fortaleza"};
    Team gec{"Goiás"};
    Team sci{"Internacional"};
    Team ecj{"Juventude"};
    Team sep{"Palmeiras"};
    Team sfc{"Santos"};
    Team spfc{"São Paulo"};

    std::list<Team*> teams{
        &amg, &cap, &acg, &cam, &afc, &bfr, &rbb, &csc, &sccp, &cfc,
        &cec, &crf, &ffc, &fec, &gec, &sci, &ecj, &sep, &sfc,  &spfc,
    };

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