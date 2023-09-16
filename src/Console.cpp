#include "Console.hpp"

void Console::printMatchResults(Team& team) {
    std::cout << "Match results of " << team.getName() << ":\n";
    std::list<MatchResult*>& matchResultsList = team.getMatchResults();
    std::list<MatchResult*>::iterator it;

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        // check if it is the team1, so underlines the name
        if ((*it)->getTeam1() == &team) {
            // check if the team1 won
            if ((*it)->getScore1() > (*it)->getScore2())
                std::cout << GREEN_BACKGROUND << " W " << RESET << " ";
            // check if the team1 lost
            else if ((*it)->getScore1() < (*it)->getScore2())
                std::cout << RED_BACKGROUND << " L " << RESET << " ";
            // check if the team1 draw
            else
                std::cout << BACKGROUND << " D " << RESET << " ";

            std::cout << UNDERLINE + (*it)->getTeam1()->getName() + RESET << " "
                      << std::to_string((*it)->getScore1()) << " x "
                      << std::to_string((*it)->getScore2()) << " "
                      << (*it)->getTeam2()->getName() << std::endl;
            // check if it is the team2, so underlines the name
        } else if ((*it)->getTeam2() == &team) {
            // check if the team2 won
            if ((*it)->getScore2() > (*it)->getScore1())
                std::cout << GREEN_BACKGROUND << " W " << RESET << " ";
            // check if the team2 lost
            else if ((*it)->getScore2() < (*it)->getScore1())
                std::cout << RED_BACKGROUND << " L " << RESET << " ";
            // check if the team2 draw
            else
                std::cout << BACKGROUND << " D " << RESET << " ";

            std::cout << (*it)->getTeam1()->getName() << " "
                      << std::to_string((*it)->getScore1()) << " x "
                      << std::to_string((*it)->getScore2()) << " "
                      << UNDERLINE + (*it)->getTeam2()->getName() << RESET
                      << std::endl;
        }
    }
    std::cout << std::endl;
}