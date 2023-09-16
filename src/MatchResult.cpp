#include "MatchResult.hpp"

unsigned long int MatchResult::nextId{0};

MatchResult::MatchResult(Team* homeTeam, Team* awayTeam,
                         unsigned short int homeTeamScore,
                         unsigned short int awayTeamScore)
    : id{nextId},
      homeTeam{homeTeam},
      awayTeam{awayTeam},
      homeTeamScore{homeTeamScore},
      awayTeamScore{awayTeamScore} {
    nextId++;

    // Add this match result to both teams' lists
    if (homeTeam) {
        homeTeam->addMatchResult(this);
    }
    if (awayTeam) {
        awayTeam->addMatchResult(this);
    }

    // Add points to the teams
    // Home team won
    if (homeTeamScore > awayTeamScore) {
        homeTeam->addPoints(3);
    }
    // Away team won
    else if (homeTeamScore < awayTeamScore) {
        awayTeam->addPoints(3);
    }
    // Draw
    else {
        homeTeam->addPoints(1);
        awayTeam->addPoints(1);
    }

    // Add wins, draws and losses to the teams
    // Home team won
    if (homeTeamScore > awayTeamScore) {
        homeTeam->addWins(1);
        awayTeam->addLosses(1);
    }
    // Away team won
    else if (homeTeamScore < awayTeamScore) {
        homeTeam->addLosses(1);
        awayTeam->addWins(1);
    }
    // Draw
    else {
        homeTeam->addDraws(1);
        awayTeam->addDraws(1);
    }

    // Add goals to the teams
    homeTeam->addGoals(homeTeamScore);
    awayTeam->addGoals(awayTeamScore);
}

unsigned int MatchResult::getId() { return id; }

Team* MatchResult::getHomeTeam() { return homeTeam; }

Team* MatchResult::getAwayTeam() { return awayTeam; }

unsigned short int MatchResult::getHomeTeamScore() { return homeTeamScore; }

unsigned short int MatchResult::getAwayTeamScore() { return awayTeamScore; }

void MatchResult::setMatchResult(Team* homeTeam, Team* awayTeam,
                                 unsigned short int homeTeamScore,
                                 unsigned short int awayTeamScore) {
    this->homeTeam = homeTeam;
    this->awayTeam = awayTeam;
    this->homeTeamScore = homeTeamScore;
    this->awayTeamScore = awayTeamScore;
}

std::string MatchResult::getMatchResult() {
    return this->getHomeTeam()->getName() + " " +
           std::to_string(this->getHomeTeamScore()) + " x " +
           std::to_string(this->getAwayTeamScore()) + " " +
           this->getAwayTeam()->getName();
}
