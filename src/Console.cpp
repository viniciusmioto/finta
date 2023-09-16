#include "Console.hpp"

#include <iomanip>

// Define a custom comparison function or lambda
bool Console::compareTeamsByPoints(Team* homeTeam, Team* awayTeam) {
    // Assuming you have a method getPoints() in your Team class
    return homeTeam->getPoints() >
           awayTeam->getPoints();  // Sort in descending order
}

void Console::printMatchResults(Team& team) {
    std::cout << BACKGROUND << "Match results of " << team.getName() << ":"
              << RESET << std::endl;

    std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::iterator it;

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        // check if it is the homeTeam, so underlines the name
        if ((*it)->getHomeTeam() == &team) {
            // check if the homeTeam won
            if ((*it)->getHomeTeamScore() > (*it)->getAwayTeamScore())
                std::cout << GREEN_BACKGROUND << " W " << RESET << " ";
            // check if the homeTeam lost
            else if ((*it)->getHomeTeamScore() < (*it)->getAwayTeamScore())
                std::cout << RED_BACKGROUND << " L " << RESET << " ";
            // check if the homeTeam draw
            else
                std::cout << BACKGROUND << " D " << RESET << " ";

            std::cout << UNDERLINE + (*it)->getHomeTeam()->getName() + RESET
                      << " " << (*it)->getHomeTeamScore() << " x "
                      << (*it)->getAwayTeamScore() << " "
                      << (*it)->getAwayTeam()->getName() << std::endl;

        }
        // check if it is the awayTeam, so underlines the name
        else if ((*it)->getAwayTeam() == &team) {
            // check if the awayTeam won
            if ((*it)->getAwayTeamScore() > (*it)->getHomeTeamScore())
                std::cout << GREEN_BACKGROUND << " W " << RESET << " ";
            // check if the awayTeam lost
            else if ((*it)->getAwayTeamScore() < (*it)->getHomeTeamScore())
                std::cout << RED_BACKGROUND << " L " << RESET << " ";
            // check if the awayTeam draw
            else
                std::cout << BACKGROUND << " D " << RESET << " ";

            std::cout << (*it)->getHomeTeam()->getName() << " "
                      << (*it)->getHomeTeamScore() << " x "
                      << (*it)->getAwayTeamScore() << " "
                      << UNDERLINE + (*it)->getAwayTeam()->getName() << RESET
                      << std::endl;
        }
    }
    std::cout << std::endl;
}

void Console::printMatchResults(std::list<MatchResult*>& matchResults) {
    std::cout << BACKGROUND << "Match results:" << RESET << std::endl;
    std::list<MatchResult*>::iterator it;

    for (it = matchResults.begin(); it != matchResults.end(); it++) {
        std::cout << (*it)->getHomeTeam()->getName() << " "
                  << (*it)->getHomeTeamScore() << " x "
                  << (*it)->getAwayTeamScore() << " "
                  << (*it)->getAwayTeam()->getName() << std::endl;
    }
    std::cout << std::endl;
}

void Console::printTable(std::list<Team*>& teams) {
    // Sort the teams by points
    teams.sort(compareTeamsByPoints);

    // Define the column widths
    const int positionWidth = 2;
    const int nameWidth = 20;
    const int pointsWidth = 6;
    const int winsWidth = 4;
    const int drawsWidth = 4;
    const int lossesWidth = 4;
    const int goalsWidth = 4;

    std::list<Team*>::iterator it;
    unsigned short int position = 1;

    // Print the table header
    std::cout << BACKGROUND << std::left << std::setw(positionWidth) << "Pos"
              << " | " << std::setw(nameWidth) << "Team"
              << " | " << std::setw(pointsWidth) << "Pts"
              << std::setw(winsWidth) << "W" << std::setw(drawsWidth) << "D"
              << std::setw(lossesWidth) << "L" << std::setw(goalsWidth) << "G"
              << RESET << std::endl;

    // Print the table rows
    for (it = teams.begin(); it != teams.end(); it++) {
        std::cout << std::left << std::setw(positionWidth) << position << "º | "
                  << std::setw(nameWidth) << (*it)->getName() << " | "
                  << std::setw(pointsWidth) << (*it)->getPoints()
                  << std::setw(winsWidth) << (*it)->getWins()
                  << std::setw(drawsWidth) << (*it)->getDraws()
                  << std::setw(lossesWidth) << (*it)->getLosses()
                  << std::setw(goalsWidth) << (*it)->getGoals() << std::endl;
        position++;
    }

    std::cout << std::endl;
}