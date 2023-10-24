#include "Console.hpp"

#include <iomanip>

// Define a custom comparison function or lambda
bool Console::compareTeams(const Team* homeTeam, const Team* awayTeam) {
    // Compare the points
    // if the points are equal, compare by wins
    // if the wins are equal, compare by goals difference

    if (homeTeam->getPoints() == awayTeam->getPoints()) {
        if (homeTeam->getWins() == awayTeam->getWins()) {
            return homeTeam->getGoalDifference() >
                   awayTeam->getGoalDifference();
        }
        return homeTeam->getWins() > awayTeam->getWins();
    }
    return homeTeam->getPoints() > awayTeam->getPoints();
}

// show menu
void Console::showMenu() {
    std::cout << "\n Choose an option:\n"
              << " 1 - Show all match results\n"
              << " 2 - Show match results for a match day\n"
              << " 3 - Show all match results of a team\n"
              << " 4 - Show match details\n"
              << " 5 - Show players of a team\n"
              << " 8 - Show classification table\n"
              << " 9 - Change data year\n"
              << " 0 - Exit" << std::endl;
}

// show teams
void Console::showTeams(const std::list<Team*>& teams) {
    std::cout << "Teams:\n" << std::endl;
    std::list<Team*>::iterator it;

    for (auto it = teams.begin(); it != teams.end(); it++) {
        std::cout << (*it)->getName() << std::endl;
    }
}

void Console::showPlayers(const std::list<Player*>& players) {
    std::cout << "Players:\n" << std::endl;
    std::list<Player*>::iterator it;

    for (auto it = players.begin(); it != players.end(); it++) {
        std::cout << (*it)->getName() << std::endl;
    }
}

void Console::printMatchResults(const Team& team) {
    std::cout << std::endl;

    std::cout << PURPLE_BG << " Match results of " << team.getName() << ":"
              << RESET_TEXT << std::endl;

    const std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::const_iterator it;

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        // show match id
        // std::cout << "[" << (*it)->getMatch()->getId() << "] ";

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

void Console::printMatchResults(const std::list<Match*>& matches,
                                unsigned short matchDay) {
    std::cout << std::endl;
    std::cout << PURPLE_BG << " Match results of match day " << matchDay << ":"
              << RESET_TEXT << std::endl;

    std::list<Match*>::const_iterator it;

    for (it = matches.begin(); it != matches.end(); it++) {
        if ((*it)->getMatchDay() == matchDay) {
            std::cout << "[" << (*it)->getId() << "] "
                      << (*it)->getMatchResult()->getHomeTeam()->getName()
                      << " " << (*it)->getMatchResult()->getHomeTeamScore()
                      << " x " << (*it)->getMatchResult()->getAwayTeamScore()
                      << " "
                      << (*it)->getMatchResult()->getAwayTeam()->getName()
                      << std::endl;
        }
    }
}

void Console::printMatchResults(const std::list<Match*>& matches) {
    std::cout << std::endl;
    std::cout << PURPLE_BG << " Match results:" << RESET_TEXT << std::endl;

    for (int matchDay = 1; matchDay <= 38; matchDay++) {
        printMatchResults(matches, matchDay);
    }
    std::cout << std::endl;
}

void Console::printMatchDetails(const Match& match) {
    std::cout << std::endl;
    std::cout << PURPLE_BG << " Match details:" << RESET_TEXT << std::endl;

    std::cout << "Match ID: " << match.getId() << std::endl;
    std::cout << "Match day: " << match.getMatchDay() << std::endl;
    std::cout << "Date: " << match.getMatchInfo()->getMatchDate() << std::endl;
    std::cout << "Hour: " << match.getMatchInfo()->getMatchHour() << std::endl;
    std::cout << "Stadium: " << match.getMatchInfo()->getMatchPlace()
              << std::endl;
    std::cout << match.getMatchResult()->getHomeTeam()->getName() << " "
              << match.getMatchResult()->getHomeTeamScore() << " x "
              << match.getMatchResult()->getAwayTeamScore() << " "
              << match.getMatchResult()->getAwayTeam()->getName() << std::endl;

    // Print the goals from home team
    // create iterator to iterate over the list of goals
    // std::list<Goal*>::const_iterator it;

    // for (it = match.getMatchInfo()->getGoals().begin();
    //      it != match.getMatchInfo()->getGoals().end(); it++) {
    //         std::cout << (*it)->getPlayer()->getName() << std::endl;
    // }

    std::cout << std::endl;
}

void Console::printTable(const std::list<Team*>& teams) {
    std::cout << std::endl;
    // Sort the teams by points
    std::list<Team*> teamsCopy = teams;

    std::cout << std::endl;

    // Sort the copy of the teams by points
    teamsCopy.sort(compareTeams);

    std::list<Team*>::iterator it;
    unsigned short int position = 1;

    // Print the table header
    std::cout << WHITE_BG << std::internal << std::setw(NUM_WIDTH) << " Pos"
              << " | " << std::setw(NUM_WIDTH) << "Pts"
              << " | " << std::setw(NUM_WIDTH) << "W"
              << " | " << std::setw(NUM_WIDTH) << "D"
              << " | " << std::setw(NUM_WIDTH) << "L"
              << " | " << std::setw(NUM_WIDTH) << "GF"
              << " | " << std::setw(NUM_WIDTH) << "GA"
              << " | " << std::setw(NUM_WIDTH) << "GD" << std::left << " | "
              << std::setw(NAME_WIDTH) << "Team" << RESET_TEXT << std::endl;

    // Print the table rows
    for (it = teamsCopy.begin(); it != teamsCopy.end(); it++) {
        std::string color = RESET_TEXT;

        if (position <= 6)
            color = BLUE_BG;
        else if (position <= 8)
            color = ORANGE_BG;
        else if (position <= 14)
            color = GREEN_BG;
        else if (position >= 17)
            color = RED_BG;

        std::cout << std::internal << color << std::setw(NUM_WIDTH) << position
                  << "º " << RESET_TEXT << "| " << std::setw(NUM_WIDTH)
                  << (*it)->getPoints() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getWins() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getDraws() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getLosses() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getGoals() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getGoalsAgainst() << " | " << std::setw(NUM_WIDTH)
                  << (*it)->getGoalDifference() << " | " << std::left
                  << std::setw(NAME_WIDTH) << (*it)->getName() << std::endl;
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
