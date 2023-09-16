#include "Team.hpp"

Team::Team(std::string name)
    : name{name}, points{0}, wins{0}, draws{0}, losses{0}, goals{0} {}

std::string Team::getName() const { return this->name; }

void Team::setName(const std::string& name) { this->name = name; }

void Team::addMatchResult(MatchResult* matchResult) {
    // Check if the matchResult pointer is not null
    if (matchResult) {
        // Add the matchResult to the team's list of match results
        matchResults.push_back(matchResult);
    }
}

unsigned short int Team::getPoints() const { return this->points; }

void Team::addPoints(const unsigned short int points) { this->points += points; }

unsigned short int Team::getWins() const { return this->wins; }

void Team::addWins(const unsigned short int wins) { this->wins += wins; }

unsigned short int Team::getDraws() const { return this->draws; }

void Team::addDraws(const unsigned short int draws) { this->draws += draws; }

unsigned short int Team::getLosses() const { return this->losses; }

void Team::addLosses(const unsigned short int losses) { this->losses += losses; }

unsigned short int Team::getGoals() const { return this->goals; }

void Team::addGoals(const unsigned short int goals) { this->goals += goals; }

const std::list<MatchResult*>& Team::getMatchResults() const { return matchResults; }