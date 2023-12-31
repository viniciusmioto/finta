#include "Console.hpp"

#include <iomanip>

namespace finta {

bool Console::compareTeams(const Team* homeTeam, const Team* awayTeam) {
    return *homeTeam > *awayTeam;
}

bool Console::comparePlayersByGoals(const Player* player1,
                                    const Player* player2) {
    return player1->getGoalsScored() > player2->getGoalsScored();
}

bool Console::comparePlayersByYellowCards(const Player* player1,
                                          const Player* player2) {
    return player1->getYellowCards() > player2->getYellowCards();
}

bool Console::comparePlayersByRedCards(const Player* player1,
                                       const Player* player2) {
    return player1->getRedCards() > player2->getRedCards();
}

bool Console::comparePlayersByName(const Player* player1,
                                   const Player* player2) {
    return *player1 < *player2;
}

// show menu
void Console::printMenu() {
    std::cout << "\n Choose an option:\n"
              << " 1 - Show all match results\n"
              << " 2 - Show match results for a match day\n"
              << " 3 - Show all match results of a team\n"
              << " 4 - Show match details\n"
              << " 5 - Show players of a team\n"
              << " 6 - Show staff of a team\n"
              << " 7 - Show classification table\n"
              << " 0 - Exit" << std::endl
              << std::endl;
}

// show teams
void Console::printTeams(const std::list<Team*>& teams) {
    std::cout << "Teams:\n" << std::endl;
    std::list<Team*>::iterator it;

    for (auto it = teams.begin(); it != teams.end(); ++it) {
        std::cout << (*it)->getName() << std::endl;
    }

    std::cout << std::endl;
}

void Console::printPlayers(const std::list<Player*>& players,
                           const unsigned short int parameter) {
    std::cout << "Players:\n" << std::endl;

    std::list<Player*> playersCopy = players;

    switch (parameter) {
        case 1:
            playersCopy.sort(comparePlayersByGoals);
            break;
        case 2:
            playersCopy.sort(comparePlayersByYellowCards);
            break;
        case 3:
            playersCopy.sort(comparePlayersByRedCards);
            break;
        default:
            playersCopy.sort(comparePlayersByName);
            break;
    }

    std::list<Player*>::iterator it;

    std::cout << PURPLE_BG << std::setw(NUM_WIDTH) << " ⚽"
              << " | " << std::setw(NUM_WIDTH) << "🟨"
              << " | " << std::setw(NUM_WIDTH) << "🟥"
              << " | " << std::setw(NAME_WIDTH * 1.5) << "Name"
              << std::setw(NAME_WIDTH * 1.5) << RESET_TEXT << std::endl;

    for (auto it = playersCopy.begin(); it != playersCopy.end(); ++it) {
        std::cout << std::setw(NUM_WIDTH) << (*it)->getGoalsScored() << " |"
                  << std::setw(NUM_WIDTH) << (*it)->getYellowCards() << " |"
                  << std::setw(NUM_WIDTH) << (*it)->getRedCards() << " | "
                  << (*it)->getName() << std::endl;
    }
}

void Console::printStaff(const std::list<Staff*>& staff) {
    std::cout << "Staff:\n" << std::endl;
    std::list<Staff*>::iterator it;

    std::cout << PURPLE_BG << std::setw(NUM_WIDTH) << "MP"
              << "|" << std::setw(NUM_WIDTH) << "W"
              << "|" << std::setw(NUM_WIDTH) << "D"
              << "|" << std::setw(NUM_WIDTH) << "L"
              << "|" << std::setw(NAME_WIDTH * 0.5) << " Res  "
              << "  |" << std::setw(NAME_WIDTH * 1.4) << "Name"
              << std::setw(NAME_WIDTH * 1.4) << RESET_TEXT << std::endl;

    for (auto it = staff.begin(); it != staff.end(); ++it) {
        std::cout << std::setw(NUM_WIDTH) << (*it)->getMatches() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getWins() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getDraws() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getLosses() << "|"
                  << std::setw(NAME_WIDTH * 0.5) << (*it)->getResultPercentage()
                  << "% | " << (*it)->getName() << std::endl;
    }

    std::cout << std::endl;
}

void Console::printMatchResults(const Team& team) {
    std::cout << std::endl;

    std::cout << PURPLE_BG << " Match results of " << team.getName() << ":"
              << RESET_TEXT << std::endl;

    const std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::const_iterator it;

    unsigned short int matchDay = 1;
    for (it = matchResultsList.begin(); it != matchResultsList.end(); ++it) {
        // show match day
        std::cout << PURPLE_TXT;
        if (matchDay < 10)
            std::cout << "(" << matchDay << "º)  ";
        else
            std::cout << "(" << matchDay << "º) ";
        std::cout << RESET_TEXT;
        matchDay++;

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

    for (it = matches.begin(); it != matches.end(); ++it) {
        if ((*it)->getMatchDay() == matchDay) {
            std::cout << CYAN_TXT << "[" << (*it)->getId() << "] " << RESET_TEXT
                      << *((*it)->getMatchResult()) << std::endl;
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

    std::cout << (match) << std::endl;

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
    for (it = teamsCopy.begin(); it != teamsCopy.end(); ++it) {
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

unsigned short Console::askMatchId() {
    std::cout << "\033[2J\033[1;1H";
    unsigned short matchId;
    std::cout << WHITE_BG << " Choose a match id: " << RESET_TEXT;
    std::cin >> matchId;

    if (matchId < 1 || matchId > 380) {
        throw InvalidMatchIdException{matchId};
        return 0;
    }

    return matchId;
}

unsigned short Console::askMatchDay() {
    std::cout << "\033[2J\033[1;1H";
    unsigned short matchDay;
    std::cout << WHITE_BG << " Choose a match day (1 - 38): " << RESET_TEXT;
    std::cin >> matchDay;

    if (matchDay < 1 || matchDay > 38) {
        throw InvalidMatchDayException{matchDay};
        return 0;
    }

    return matchDay;
}
} // namespace finta