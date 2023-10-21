#include "Console.hpp"

#include <iomanip>

// Define a custom comparison function or lambda
bool Console::compareTeamsByPoints(Team* homeTeam, Team* awayTeam) {
    // Assuming you have a method getPoints() in your Team class
    return homeTeam->getPoints() >
           awayTeam->getPoints();  // Sort in descending order
}

// show menu
void Console::showMenu() {
    std::cout << "\n Choose an option:\n"
              << " 1 - Show all match results\n"
              << " 2 - Show match results for a match day\n"
              << " 3 - Show all match results of a team\n"
              << " 9 - Show classification table\n"
              << " 0 - Exit" << std::endl;
}

// show teams
void Console::showTeams(std::list<Team*>& teams) {
    std::cout << "Teams:\n" << std::endl;
    std::list<Team*>::iterator it;

    for (it = teams.begin(); it != teams.end(); it++) {
        std::cout << (*it)->getName() << std::endl;
    }
}

void Console::printMatchResults(Team& team) {
    std::cout << std::endl;

    std::cout << PURPLE_BG << " Match results of " << team.getName() << ":"
              << RESET_TEXT << std::endl;

    const std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::const_iterator it;

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        // show match day
        // std::cout << "MD [" << (*it)->getMatchDay() << "] ";

        // check if it is the homeTeam, so underlines the name
        if ((*it)->getHomeTeam() == &team) {
            // check if the homeTeam won
            if ((*it)->getHomeTeamScore() > (*it)->getAwayTeamScore())
                std::cout << GREEN_BG << " W " << RESET_TEXT << " ";
            // check if the homeTeam lost
            else if ((*it)->getHomeTeamScore() < (*it)->getAwayTeamScore())
                std::cout << RED_BG << " L " << RESET_TEXT << " ";
            // check if the homeTeam draw
            else
                std::cout << WHITE_BG << " D " << RESET_TEXT << " ";

            std::cout << UNDERLINE + (*it)->getHomeTeam()->getName() +
                             RESET_TEXT
                      << " " << (*it)->getHomeTeamScore() << " x "
                      << (*it)->getAwayTeamScore() << " "
                      << (*it)->getAwayTeam()->getName() << std::endl;

        }
        // check if it is the awayTeam, so underlines the name
        else if ((*it)->getAwayTeam() == &team) {
            // check if the awayTeam won
            if ((*it)->getAwayTeamScore() > (*it)->getHomeTeamScore())
                std::cout << GREEN_BG << " W " << RESET_TEXT << " ";
            // check if the awayTeam lost
            else if ((*it)->getAwayTeamScore() < (*it)->getHomeTeamScore())
                std::cout << RED_BG << " L " << RESET_TEXT << " ";
            // check if the awayTeam draw
            else
                std::cout << WHITE_BG << " D " << RESET_TEXT << " ";

            std::cout << (*it)->getHomeTeam()->getName() << " "
                      << (*it)->getHomeTeamScore() << " x "
                      << (*it)->getAwayTeamScore() << " "
                      << UNDERLINE + (*it)->getAwayTeam()->getName()
                      << RESET_TEXT << std::endl;
        }
    }
    std::cout << std::endl;
}

void Console::printMatchResults(const std::list<MatchResult*>& matchResults,
                                unsigned short matchDay) {
    std::cout << std::endl;
    std::cout << PURPLE_BG << " Match results of match day " << matchDay << ":"
              << RESET_TEXT << std::endl;

    std::list<MatchResult*>::const_iterator it;

    for (it = matchResults.begin(); it != matchResults.end(); it++) {
        if ((*it)->getMatchDay() == matchDay) {
            std::cout << " " << (*it)->getHomeTeam()->getName() << " "
                      << (*it)->getHomeTeamScore() << " x "
                      << (*it)->getAwayTeamScore() << " "
                      << (*it)->getAwayTeam()->getName() << std::endl;
        }
    }
}

void Console::printMatchResults(const std::list<MatchResult*>& matchResults) {
    std::cout << std::endl;
    std::cout << PURPLE_BG << " Match results:" << RESET_TEXT << std::endl;
    std::list<MatchResult*>::iterator it;

    for (int matchDay = 1; matchDay <= 38; matchDay++) {
        printMatchResults(matchResults, matchDay);
    }
    std::cout << std::endl;
}

void Console::printTable(std::list<Team*>& teams) {
    std::cout << std::endl;
    // Sort the teams by points
    teams.sort(compareTeamsByPoints);

    // Define the column widths
    const int positionWidth = 3;
    const int nameWidth = 15;
    const int pointsWidth = 3;
    const int winsWidth = 3;
    const int drawsWidth = 3;
    const int lossesWidth = 3;
    const int goalsWidth = 3;

    std::list<Team*>::iterator it;
    unsigned short int position = 1;

    // Print the table header
    std::cout << WHITE_BG << std::internal << std::setw(positionWidth) << " Pos"
              << " | " << std::setw(pointsWidth) << "Pts"
              << " | " << std::setw(winsWidth) << "W"
              << " | " << std::setw(drawsWidth) << "D"
              << " | " << std::setw(lossesWidth) << "L"
              << " | " << std::setw(goalsWidth) << "G" << std::left << " | "
              << std::setw(nameWidth) << "Team" << RESET_TEXT << std::endl;

    // Print the table rows
    for (it = teams.begin(); it != teams.end(); it++) {
        std::string color = RESET_TEXT;

        if (position <= 6)
            color = BLUE_BG;
        else if (position <= 8)
            color = ORANGE_BG;
        else if (position <= 14)
            color = GREEN_BG;
        else if (position >= 17)
            color = RED_BG;

        std::cout << std::internal << color << std::setw(positionWidth)
                  << position << "º " << RESET_TEXT << "| "
                  << std::setw(pointsWidth) << (*it)->getPoints() << " | "
                  << std::setw(winsWidth) << (*it)->getWins() << " | "
                  << std::setw(drawsWidth) << (*it)->getDraws() << " | "
                  << std::setw(lossesWidth) << (*it)->getLosses() << " | "
                  << std::setw(goalsWidth) << (*it)->getGoals() << " | "
                  << std::left << std::setw(nameWidth) << (*it)->getName()
                  << std::endl;
        position++;
    }

    std::cout << std::endl;

    // Print the table legend
    std::cout << BLUE_BG << "  " << RESET_TEXT << " Libertadores group stage"
              << std::endl;
    std::cout << ORANGE_BG << "  " << RESET_TEXT << " Libertadores qualifiers"
              << std::endl;
    std::cout << GREEN_BG << "  " << RESET_TEXT << " Sudamericana group stage"
              << std::endl;
    std::cout << RED_BG << "  " << RESET_TEXT << " Relegation" << std::endl;

    std::cout << std::endl;
}