#include "MatchResult.hpp"

unsigned long int MatchResult::nextId{0};

MatchResult::MatchResult(Team* team1, Team* team2, uint8_t score1, uint8_t score2) 
: id{nextId}, team1{team1}, team2{team2}, score1{score1}, score2{score2} {
    nextId++;
}

unsigned int MatchResult::getId() { return id; }

Team* MatchResult::getTeam1() { return team1; }

Team* MatchResult::getTeam2() { return team2; }

uint8_t MatchResult::getScore1() { return score1; }

uint8_t MatchResult::getScore2() { return score2; }

void MatchResult::setMatchResult(Team* team1, Team* team2, uint8_t score1, uint8_t score2) {
    this->team1 = team1;
    this->team2 = team2;
    this->score1 = score1;
    this->score2 = score2;
}

std::string MatchResult::getMatchResult()  {
    return team1->getName() + " " + std::to_string(score1) + " - " + std::to_string(score2) + " " + team2->getName();
}
