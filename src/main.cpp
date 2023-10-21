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

    League brasileirao(teams, matchResults);

    brasileirao.fillMatchResults("../data/Brasileirao2022.json");

    std::cout << "Choose an option:" << std::endl;
    std::cout << "1 - Show all match results" << std::endl;
    std::cout << "2 - Show all match results of a team" << std::endl;
    std::cout << "3 - Show classification table" << std::endl;
    std::cout << "0 - Exit" << std::endl;

    int option;
    std::cout << "Option: ";
    std::cin >> option;
    std::string teamName;

    while (option != 0) {
        switch (option) {
            case 1:
                Console::printMatchResults(brasileirao.getMatchResults());
                break;
            case 2:
                std::cout << "Choose a team:" << std::endl;
                for (Team* team : teams) {
                    std::cout << team->getName() << std::endl;
                }
                std::cout << "Team: ";
                std::cin.ignore();
                std::getline(std::cin, teamName);
                for (Team* team : teams) {
                    if (teamName == team->getName()) {
                        system("clear");
                        std::cout << std::endl;
                        Console::printMatchResults(*team);
                    }
                }
                break;
            case 3:
                system("clear");
                std::cout << std::endl;
                Console::printTable(teams);
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }

        std::cout << "Choose an option:" << std::endl;
        std::cout << "1 - Show all match results" << std::endl;
        std::cout << "2 - Show all match results of a team" << std::endl;
        std::cout << "3 - Show classification table" << std::endl;
        std::cout << "0 - Exit" << std::endl;

        std::cin >> option;
        system("clear");
    }

    return 0;
}