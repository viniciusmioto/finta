#include "Team.hpp"

Team::Team(std::string name)
    : name{name}, points{0}, wins{0}, draws{0}, losses{0}, goals{0}, goalsAgainst{0}, goalDifference{0} {}

std::string Team::getName() const { return this->name; }

void Team::setName(const std::string& name) { this->name = name; }

void Team::addMatchResult(MatchResult* matchResult) {
    // Check if the matchResult pointer is not null
    if (matchResult) {
        // Add the matchResult to the team's list of match results
        this->matchResults.push_back(matchResult);
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

void Team::addStaff(Person* person) {
    // Check if the person pointer is not null
    if (person) {
        // Add the person to the team's list of staff
        staff.push_back(person);
    }
}

const std::list<Person*>& Team::getStaff() const { return staff; }

void Team::addPlayer(Player* player) {
    // Check if the player pointer is not null
    if (player) {
        // Add the player to the team's list of players
        players.push_back(player);
    }
}

const std::list<Player*>& Team::getPlayers() const { return players; }

short int Team::getGoalsAgainst() const { return goalsAgainst; }

void Team::addGoalsAgainst(const short int goalsAgainst) {
    this->goalsAgainst += goalsAgainst;
}

short int Team::getGoalDifference() const { return goalDifference; }

void Team::setGoalDifference(const short int goalDifference) {
    this->goalDifference = goalDifference;
}