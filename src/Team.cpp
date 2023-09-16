#include "Team.hpp"

Team::Team(std::string name): name{name} {}

std::string Team::getName() { return this->name; }

void Team::setName(std::string name) { this->name = name; }

void Team::addMatchResult(MatchResult* matchResult) {
    // Check if the matchResult pointer is not null
    if (matchResult) {
        // Add the matchResult to the team's list of match results
        matchResults.push_back(matchResult);
    }
}

std::list<MatchResult*>& Team::getMatchResults() { return matchResults; }