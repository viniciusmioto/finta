#include <iostream>

#include "Console.hpp"
#include "InvalidMatchDayException.hpp"
#include "InvalidMatchIdException.hpp"
#include "League.hpp"
#include "Match.hpp"
#include "Team.hpp"


int main() {
    std::list<finta::Team*> teams;
    std::list<finta::Match*> matches;
    finta::League league("brasileirão", teams, matches);

    int dataYear;
    std::string dataFile;

    // choose the year
    std::cout << "Enter the year (2014-2022): ";
    std::cin >> dataYear;

    // Generate the file path based on the user input.
    dataFile = "../data/brasileirao-" + std::to_string(dataYear) + ".json";

    //  Load data from the selected file.
    league.fillMatches(dataFile);

#ifdef DEBUG
    Console::printTeams(league.getTeams());
#endif

    finta::Console::printMenu();

    unsigned short option;
    std::cout << " Option: ";
    std::cin >> option;
    std::string teamName;

    while (option != 0) {
        switch (option) {
            case 1:
                std::cout << "\033[2J\033[1;1H";
                finta::Console::printMatchResults(league.getMatches());
                break;
            case 2:
                try {
                    unsigned short matchDay = finta::Console::askMatchDay();
                    finta::Console::printMatchResults(league.getMatches(), matchDay);
                } catch (const finta::InvalidMatchDayException& e) {
                    std::cout << finta::YELLOW_TXT << e.what() << finta::RESET_TEXT
                              << std::endl;
                    break;
                }
                break;
            case 3:
                std::cout << "\033[2J\033[1;1H";
                finta::Console::printTeams(league.getTeams());
                std::cout << finta::WHITE_BG << " Choose a team:" << finta::RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);

                for (finta::Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        finta::Console::printMatchResults(*team);
                    }
                }

                break;
            case 4:
                try {
                    unsigned short matchId = finta::Console::askMatchId();
                    for (finta::Match* match : league.getMatches()) {
                        if (matchId == match->getId()) {
                            finta::Console::printMatchDetails(*match);
                        }
                    }
                } catch (const finta::InvalidMatchIdException& e) {
                    std::cout << finta::YELLOW_TXT << e.what() << finta::RESET_TEXT
                              << std::endl;
                    break;
                }

                break;
            case 5:
                std::cout << "\033[2J\033[1;1H";
                short int parameter;
                finta::Console::printTeams(league.getTeams());
                std::cout << finta::WHITE_BG << " Choose a team:" << finta::RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);

                std::cout << "\n"
                          << finta::WHITE_BG
                          << " Choose an sorting parameter:" << finta::RESET_TEXT
                          << std::endl;

                std::cout << "  0 - Alphabetic\n"
                          << "  1 - Goals\n"
                          << "  2 - Yellow Cards\n"
                          << "  3 - Red Cards\n"
                          << std::endl;
                std::cout << finta::WHITE_BG << " Option: " << finta::RESET_TEXT;
                std::cin >> parameter;

                for (finta::Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        finta::Console::printPlayers(team->getPlayers(), parameter);
                    }
                }
                break;
            case 6:
                std::cout << "\033[2J\033[1;1H";
                finta::Console::printTeams(league.getTeams());
                std::cout << finta::WHITE_BG << " Choose a team:" << finta::RESET_TEXT;
                std::cin.ignore();
                std::getline(std::cin, teamName);

                for (finta::Team* team : league.getTeams()) {
                    if (teamName == team->getName()) {
                        std::cout << team->getName() << std::endl;
                        finta::Console::printStaff(team->getStaff());
                    }
                }

                break;
            case 7:
                std::cout << "\033[2J\033[1;1H";
                finta::Console::printTable(league.getTeams());
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }

        finta::Console::printMenu();

        std::cout << finta::WHITE_BG << " Option: " << finta::RESET_TEXT;
        std::cin >> option;
    }

    return 0;
}
