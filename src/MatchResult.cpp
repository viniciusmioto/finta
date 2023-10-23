#include "MatchResult.hpp"

unsigned long int MatchResult::nextId{0};

MatchResult::MatchResult(Team* homeTeam, Team* awayTeam,
                         unsigned short int homeTeamScore,
                         unsigned short int awayTeamScore,
                         unsigned short matchDay)
    : id{nextId},
      homeTeam{homeTeam},
      awayTeam{awayTeam},
      homeTeamScore{homeTeamScore},
      awayTeamScore{awayTeamScore} {
    nextId++;
    setMatchDay(matchDay);

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

    // Add goals against to the teams
    homeTeam->addGoalsAgainst(awayTeamScore);
    awayTeam->addGoalsAgainst(homeTeamScore);

    // Add goal difference to the teams
    homeTeam->setGoalDifference(homeTeam->getGoals() -
                                homeTeam->getGoalsAgainst());

    awayTeam->setGoalDifference(awayTeam->getGoals() -
                                awayTeam->getGoalsAgainst());
}

unsigned int MatchResult::getId() const { return id; }

Team* MatchResult::getHomeTeam() const { return homeTeam; }

Team* MatchResult::getAwayTeam() const { return awayTeam; }

unsigned short int MatchResult::getHomeTeamScore() const {
    return homeTeamScore;
}

unsigned short int MatchResult::getAwayTeamScore() const {
    return awayTeamScore;
}

void MatchResult::setMatchResult(Team* homeTeam, Team* awayTeam,
                                 const unsigned short int homeTeamScore,
                                 const unsigned short int awayTeamScore) {
    this->homeTeam = homeTeam;
    this->awayTeam = awayTeam;
    this->homeTeamScore = homeTeamScore;
    this->awayTeamScore = awayTeamScore;
}

std::string MatchResult::getMatchResult() const {
    return this->getHomeTeam()->getName() + " " +
           std::to_string(this->getHomeTeamScore()) + " x " +
           std::to_string(this->getAwayTeamScore()) + " " +
           this->getAwayTeam()->getName();
}

unsigned short MatchResult::getMatchDay() const { return matchDay; }

void MatchResult::setMatchDay(const unsigned short matchDay) {
    if (matchDay < 1 || matchDay > 38) {
        this->matchDay = 0;
        return;
    }
    this->matchDay = matchDay;
}