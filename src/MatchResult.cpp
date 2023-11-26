#include "MatchResult.hpp"

MatchResult::MatchResult(Team* homeTeam, Team* awayTeam,
                         unsigned short int homeTeamScore,
                         unsigned short int awayTeamScore)
    : homeTeam{homeTeam},
      awayTeam{awayTeam},
      homeTeamScore{homeTeamScore},
      awayTeamScore{awayTeamScore} {
    // Add this match result to both teams' lists
    if (homeTeam) {
        homeTeam->addMatchResult(this);
    }
    if (awayTeam) {
        awayTeam->addMatchResult(this);
    }

    // Home team won
    if (homeTeamScore > awayTeamScore) {
        homeTeam->addPoints(3);
        homeTeam->addWins(1);
        awayTeam->addLosses(1);
    }
    // Away team won
    else if (homeTeamScore < awayTeamScore) {
        awayTeam->addPoints(3);
        homeTeam->addLosses(1);
        awayTeam->addWins(1);
    }
    // Draw
    else {
        homeTeam->addPoints(1);
        awayTeam->addPoints(1);
        homeTeam->addDraws(1);
        awayTeam->addDraws(1);
    }

    // Add goals to the teams
    homeTeam->addGoals(homeTeamScore);
    awayTeam->addGoals(awayTeamScore);

    // Add goals against to the teams
    homeTeam->addGoalsAgainst(awayTeamScore);
    awayTeam->addGoalsAgainst(homeTeamScore);

    // Add goal difference to the teams
    homeTeam->setGoalDifference(homeTeam->getGoals() -
                                homeTeam->getGoalsAgainst());

    awayTeam->setGoalDifference(awayTeam->getGoals() -
                                awayTeam->getGoalsAgainst());
}

Team* MatchResult::getHomeTeam() const { return this->homeTeam; }

void MatchResult::setHomeTeam(Team* homeTeam) { this->homeTeam = homeTeam; }

Team* MatchResult::getAwayTeam() const { return this->awayTeam; }

void MatchResult::setAwayTeam(Team* awayTeam) { this->awayTeam = awayTeam; }

unsigned short int MatchResult::getHomeTeamScore() const {
    return this->homeTeamScore;
}

void MatchResult::setHomeTeamScore(unsigned short int homeTeamScore) {
    this->homeTeamScore = homeTeamScore;
}

unsigned short int MatchResult::getAwayTeamScore() const {
    return this->awayTeamScore;
}

void MatchResult::setAwayTeamScore(unsigned short int awayTeamScore) {
    this->awayTeamScore = awayTeamScore;
}

std::ostream& operator<<(std::ostream& os, const MatchResult& matchResult) {
    os << matchResult.getHomeTeam()->getName() << " "
       << matchResult.getHomeTeamScore() << " x "
       << matchResult.getAwayTeamScore() << " "
       << matchResult.getAwayTeam()->getName();

    return os;
}