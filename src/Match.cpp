#include "Match.hpp"

unsigned long int Match::nextId{1};

std::ostream& operator<<(std::ostream& os, const Match& match) {
    os << "🔰 Match ID: " << match.id << " | 📌 Match Day: " << match.matchDay
       << std::endl;

    os << "\n" << *match.matchResult << "\n" << std::endl;
    os << *match.matchInfo << std::endl;

    os << "Home Team Stats: " << std::endl;

    os << *match.homeMatchStats << std::endl;

    os << "Away Team Stats: " << std::endl;

    os << *match.awayMatchStats << std::endl;

    return os;
}

Match::Match(unsigned short matchDay, MatchResult* MatchResult)
    : id{nextId}, matchResult{MatchResult} {
    setMatchDay(matchDay);
    this->nextId++;
}

Match::Match(unsigned short matchDay, MatchResult* MatchResult,
             MatchInfo* MatchInfo)
    : id{nextId}, matchResult{MatchResult}, matchInfo{MatchInfo} {
    setMatchDay(matchDay);
    this->nextId++;
}

Match::Match(unsigned short matchDay, MatchResult* MatchResult,
             MatchInfo* MatchInfo, MatchStats* HomeMatchStats,
             MatchStats* AwayMatchStats)
    : id{nextId},
      matchResult{MatchResult},
      matchInfo{MatchInfo},
      homeMatchStats{HomeMatchStats},
      awayMatchStats{AwayMatchStats} {
    this->setMatchDay(matchDay);
    this->nextId++;
}

Match::~Match() {
    delete matchResult;
    delete matchInfo;
    delete homeMatchStats;
    delete awayMatchStats;
}

unsigned int Match::getId() const { return this->id; }

unsigned short Match::getMatchDay() const { return this->matchDay; }

void Match::setMatchDay(const unsigned short matchDay) {
    if (matchDay < 1 || matchDay > 38) {
        this->matchDay = 0;
        return;
    }
    this->matchDay = matchDay;
}

MatchResult* Match::getMatchResult() const { return this->matchResult; }

void Match::setMatchResult(MatchResult* matchResult) {
    this->matchResult = matchResult;
}

MatchInfo* Match::getMatchInfo() const { return this->matchInfo; }

void Match::setMatchInfo(MatchInfo* matchInfo) { this->matchInfo = matchInfo; }


MatchStats* Match::getHomeMatchStats() const { return this->homeMatchStats; }

void Match::setHomeMatchStats(MatchStats* homeMatchStats) {
    this->homeMatchStats = homeMatchStats;
}

MatchStats* Match::getAwayMatchStats() const { return this->awayMatchStats; }

void Match::setAwayMatchStats(MatchStats* awayMatchStats) {
    this->awayMatchStats = awayMatchStats;
}
