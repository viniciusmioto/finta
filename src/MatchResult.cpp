#include "MatchResult.hpp"

MatchResult::MatchResult(){}

MatchResult::MatchResult(const std::string& team1, const std::string& team2, int score1, int score2)
: team1{team1}, team2{team2}, score1{score1}, score2{score2} {}

std::string MatchResult::getTeam1() const { return team1; }

std::string MatchResult::getTeam2() const { return team2; }

int MatchResult::getScore1() const { return score1; }

int MatchResult::getScore2() const { return score2; }

void MatchResult::setMatchResult(const std::string& team1, const std::string& team2, int score1, int score2) {
    this->team1 = team1;
    this->team2 = team2;
    this->score1 = score1;
    this->score2 = score2;
}

std::string MatchResult::getMatchResult() const {
    return team1 + " " + std::to_string(score1) + " - " + std::to_string(score2) + " " + team2;
}
