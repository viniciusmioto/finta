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
    return player1->getName() < player2->getName();
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
              << " 8 - Show classification table\n"
              << " 0 - Exit" << std::endl
              << std::endl;
}

// show teams
void Console::printTeams(const std::list<Team*>& teams) {
    std::cout << "Teams:\n" << std::endl;
    std::list<Team*>::iterator it;

    for (auto it = teams.begin(); it != teams.end(); it++) {
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
    }

    std::list<Player*>::iterator it;

    std::cout << PURPLE_BG << std::setw(NUM_WIDTH) << " ⚽"
              << " | " << std::setw(NUM_WIDTH) << "🟨"
              << " | " << std::setw(NUM_WIDTH) << "🟥"
              << " | " << std::setw(NAME_WIDTH * 1.5) << "Name"
              << std::setw(NAME_WIDTH * 1.5) << RESET_TEXT << std::endl;

    for (auto it = playersCopy.begin(); it != playersCopy.end(); it++) {
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

    for (auto it = staff.begin(); it != staff.end(); it++) {
        std::cout << std::setw(NUM_WIDTH) << (*it)->getMatches() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getWins() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getDraws() << "|"
                  << std::setw(NUM_WIDTH) << (*it)->getLosses() << "|"
                  << std::setw(NAME_WIDTH * 0.5) << (*it)->getResultPercentage()
                  << "% | " << (*it)->getName() << std::endl;
    }

    std::cout << std::endl;
}

void Console::printGoal(const Goal& goal) {
    std::cout << "⚽ " << goal.getPlayer()->getName() << " " << goal.getMinute()
              << std::endl;
}

void Console::printGoals(const std::list<Goal*>& goals, const Team& team) {
    if (goals.size() == 0) return;

    std::cout << std::endl;
    std::cout << UNDERLINE << "Goals from"
              << " " << team.getName() << RESET_TEXT << ":" << std::endl;

    std::list<Goal*>::const_iterator it;

    for (it = goals.begin(); it != goals.end(); it++) {
        printGoal(**it);
    }

    std::cout << std::endl;
}

void Console::printCards(const std::list<Fact*>& cards, const Team& team,
                         bool isYellowCard) {
    if (cards.size() == 0) return;

    std::cout << UNDERLINE << "Cards for " << team.getName() << RESET_TEXT
              << ": " << std::endl;

    std::list<Fact*>::const_iterator it;
    std::string card = isYellowCard ? "🟨 " : "🟥 ";
    for (it = cards.begin(); it != cards.end(); it++)
        std::cout << card << (*it)->getPlayer()->getName() << " "
                  << (*it)->getMinute() << std::endl;

    std::cout << std::endl;
}

void Console::printMatchResults(const Team& team) {
    std::cout << std::endl;

    std::cout << PURPLE_BG << " Match results of " << team.getName() << ":"
              << RESET_TEXT << std::endl;

    const std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::const_iterator it;

    unsigned short int matchDay = 1;
    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
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

    for (it = matches.begin(); it != matches.end(); it++) {
        if ((*it)->getMatchDay() == matchDay) {
            std::cout << CYAN_TXT << "[" << (*it)->getId() << "] " << RESET_TEXT
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

    std::cout << "🔰 " << UNDERLINE << "Match ID" << RESET_TEXT << ": "
              << match.getId() << std::endl;
    std::cout << "📌 " << UNDERLINE << "Match day" << RESET_TEXT << ": "
              << match.getMatchDay() << std::endl;
    std::cout << "🗓️  " << UNDERLINE << "Date" << RESET_TEXT << ": "
              << match.getMatchInfo()->getMatchDate() << std::endl;
    std::cout << "🕖 " << UNDERLINE << "Hour" << RESET_TEXT << ": "
              << match.getMatchInfo()->getMatchHour() << std::endl;
    std::cout << "🏟️  " << UNDERLINE << "Stadium" << RESET_TEXT << ": "
              << match.getMatchInfo()->getMatchPlace() << std::endl
              << std::endl;
    std::cout << match.getMatchResult()->getHomeTeam()->getName() << " "
              << match.getMatchResult()->getHomeTeamScore() << " x "
              << match.getMatchResult()->getAwayTeamScore() << " "
              << match.getMatchResult()->getAwayTeam()->getName() << std::endl;

    printGoals(match.getMatchInfo()->getHomeGoals(),
               *match.getMatchResult()->getHomeTeam());
    printGoals(match.getMatchInfo()->getAwayGoals(),
               *match.getMatchResult()->getAwayTeam());

    printCards(match.getMatchInfo()->getHomeYellowCards(),
               *match.getMatchResult()->getHomeTeam(), true);

    printCards(match.getMatchInfo()->getHomeRedCards(),
               *match.getMatchResult()->getHomeTeam(), false);

    printCards(match.getMatchInfo()->getAwayYellowCards(),
               *match.getMatchResult()->getAwayTeam(), true);

    printCards(match.getMatchInfo()->getAwayRedCards(),
               *match.getMatchResult()->getAwayTeam(), false);

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
