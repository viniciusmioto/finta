#include "Match.hpp"

unsigned long int Match::nextId{0};

Match::Match(unsigned short matchDay, MatchResult* MatchResult) : id{nextId}, matchResult{MatchResult} {
    setMatchDay(matchDay);
    nextId++;
}

unsigned int Match::getId() const { return id; }

unsigned short Match::getMatchDay() const { return matchDay; }

void Match::setMatchDay(const unsigned short matchDay) {
    if (matchDay < 1 || matchDay > 38) {
        this->matchDay = 0;
        return;
    }
    this->matchDay = matchDay;
}

MatchResult* Match::getMatchResult() const { return matchResult; }

MatchInfo* Match::getMatchInfo() const { return matchInfo; }

void Match::setMatchResult(MatchResult* matchResult) {
    this->matchResult = matchResult;
}

void Match::setMatchInfo(MatchInfo* matchInfo) { this->matchInfo = matchInfo; }
