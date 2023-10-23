#include <iostream>

#include "Console.hpp"
#include "League.hpp"
#include "MatchResult.hpp"
#include "Team.hpp"

int main() {
    std::list<Team*> teams;
    std::list<MatchResult*> matchResults;
    League league(teams, matchResults);

    int dataYear;
    std::string dataFile;

    // choose the year
    std::cout << "Enter the year (2006-2022): ";
    std::cin >> dataYear;

    // Generate the file path based on the user input.
    dataFile = "../data/brasileirao-" + std::to_string(dataYear) + ".json";

    //  Load data from the selected file.
    league.fillMatchResults(dataFile);

#ifdef DEBUG
    Console::showTeams(league.getTeams());
#endif

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
                Console::showTeams(league.getTeams());
                std::cout << WHITE_BG << " Choose a team:" << RESET_TEXT
                          << std::endl;
                std::cin.ignore();
                std::getline(std::cin, teamName);
                for (Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        Console::printMatchResults(*team);
                    }
                }
                break;
            case 8:
                system("clear");
                Console::printTable(league.getTeams());
                break;
            case 9:
                // Allow the user to change the data year.
                std::cout << "Enter the year (2006-2022): ";
                std::cin >> dataYear;

                // Generate the file path based on the user input.
                dataFile =
                    "../data/brasileirao-" + std::to_string(dataYear) + ".json";

                league.fillMatchResults(dataFile);
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
