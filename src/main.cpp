#include <iostream>

#include "Console.hpp"
#include "League.hpp"
#include "Match.hpp"
#include "Team.hpp"

int main() {
    std::list<Team*> teams;
    std::list<Match*> matches;
    League league("brasileirão", teams, matches);

    int dataYear;
    std::string dataFile;

    // choose the year
    std::cout << "Enter the year (2006-2022): ";
    std::cin >> dataYear;

    // Generate the file path based on the user input.
    dataFile = "../data/brasileirao-" + std::to_string(dataYear) + ".json";

    //  Load data from the selected file.
    league.fillMatches(dataFile);

#ifdef DEBUG
    Console::printTeams(league.getTeams());
#endif

    Console::printMenu();

    int option;
    std::cout << " Option: ";
    std::cin >> option;
    std::string teamName;

    while (option != 0) {
        switch (option) {
            case 1:
                system("clear");
                Console::printMatchResults(league.getMatches());
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
                Console::printMatchResults(league.getMatches(), matchDay);
                break;
            case 3:
                system("clear");
                Console::printTeams(league.getTeams());
                std::cout << WHITE_BG << " Choose a team:" << RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);
                for (Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        Console::printMatchResults(*team);
                    }
                }
                break;
            case 4:
                system("clear");
                unsigned short matchId;
                std::cout << WHITE_BG << " Choose a match id: " << RESET_TEXT;
                std::cin >> matchId;
                for (Match* match : league.getMatches()) {
                    if (matchId == match->getId()) {
                        Console::printMatchDetails(*match);
                    }
                }
                break;
            case 5:
                system("clear");
                short int parameter;
                Console::printTeams(league.getTeams());
                std::cout << WHITE_BG << " Choose a team:" << RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);

                std::cout << "\n"
                          << WHITE_BG
                          << " Choose an sorting parameter:" << RESET_TEXT
                          << std::endl;

                std::cout << "  0 - Alphabetic\n"
                          << "  1 - Goals\n"
                          << "  2 - Yellow Cards\n"
                          << "  3 - Red Cards\n"
                          << std::endl;
                std::cout << WHITE_BG << " Option: " << RESET_TEXT;
                std::cin >> parameter;

                for (Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        Console::printPlayers(team->getPlayers(), parameter);
                    }
                }
                break;
            case 6:
                system("clear");
                Console::printTeams(league.getTeams());
                std::cout << WHITE_BG << " Choose a team:" << RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);

                for (Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        Console::printStaff(team->getStaff());
                    }
                }

                break;
            case 8:
                system("clear");
                Console::printTable(league.getTeams());
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }

        Console::printMenu();

        std::cout << WHITE_BG << " Option: " << RESET_TEXT;
        std::cin >> option;
    }

    return 0;
}
