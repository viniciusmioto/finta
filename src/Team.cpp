#include "Team.hpp"

Team::Team(std::string name)
    : name{name}, points{0}, wins{0}, draws{0}, losses{0}, goals{0} {}

std::string Team::getName() { return this->name; }

void Team::setName(std::string name) { this->name = name; }

void Team::addMatchResult(MatchResult* matchResult) {
    // Check if the matchResult pointer is not null
    if (matchResult) {
        // Add the matchResult to the team's list of match results
        matchResults.push_back(matchResult);
    }
}

unsigned short int Team::getPoints() { return this->points; }

void Team::addPoints(unsigned short int points) { this->points += points; }

unsigned short int Team::getWins() { return this->wins; }

void Team::addWins(unsigned short int wins) { this->wins += wins; }

unsigned short int Team::getDraws() { return this->draws; }

void Team::addDraws(unsigned short int draws) { this->draws += draws; }

unsigned short int Team::getLosses() { return this->losses; }

void Team::addLosses(unsigned short int losses) { this->losses += losses; }

unsigned short int Team::getGoals() { return this->goals; }

void Team::addGoals(unsigned short int goals) { this->goals += goals; }

std::list<MatchResult*>& Team::getMatchResults() { return matchResults; }