#include "MatchInfo.hpp"

MatchInfo::MatchInfo(std::string matchDate, std::string matchTime,
                     std::string matchPlace)
    : matchDate{matchDate}, matchTime{matchTime}, matchPlace{matchPlace} {}

MatchInfo::MatchInfo(std::string matchDate, std::string matchTime,
                     std::string matchPlace, std::list<Goal*> homeGoals,
                     std::list<Goal*> awayGoals)
    : matchDate{matchDate},
      matchTime{matchTime},
      matchPlace{matchPlace},
      homeGoals{homeGoals},
      awayGoals{awayGoals} {}

std::string MatchInfo::getMatchDate() const { return matchDate; }

std::string MatchInfo::getMatchHour() const { return matchTime; }

std::string MatchInfo::getMatchPlace() const { return matchPlace; }

void MatchInfo::setMatchInfo(Team* homeTeam, Team* awayTeam,
                             const unsigned short int homeTeamScore,
                             const unsigned short int awayTeamScore,
                             const std::string& matchDate,
                             const std::string& matchTime,
                             const std::string& matchPlace) {
    this->matchDate = matchDate;
    this->matchTime = matchTime;
    this->matchPlace = matchPlace;
}

std::string MatchInfo::showMatchInfo() const {
    std::string matchInfoString = "Match info:\n";
    matchInfoString += "Date: " + matchDate + "\n";
    matchInfoString += "Time: " + matchTime + "\n";
    matchInfoString += "Place: " + matchPlace + "\n";
    return matchInfoString;
}

void MatchInfo::addHomeGoal(Goal* goal) { homeGoals.push_back(goal); }

const std::list<Goal*>& MatchInfo::getHomeGoals() const { return homeGoals; }

void MatchInfo::addAwayGoal(Goal* goal) { awayGoals.push_back(goal); }

const std::list<Goal*>& MatchInfo::getAwayGoals() const { return awayGoals; }

void MatchInfo::addHomeYellowCard(YellowCard* yellowCard) {
    homeYellowCards.push_back(yellowCard);
}

const std::list<YellowCard*>& MatchInfo::getHomeYellowCards() const {
    return homeYellowCards;
}

void MatchInfo::addAwayYellowCard(YellowCard* yellowCard) {
    awayYellowCards.push_back(yellowCard);
}

const std::list<YellowCard*>& MatchInfo::getAwayYellowCards() const {
    return awayYellowCards;
}

void MatchInfo::addHomeRedCard(RedCard* redCard) {
    homeRedCards.push_back(redCard);
}

const std::list<RedCard*>& MatchInfo::getHomeRedCards() const {
    return homeRedCards;
}

void MatchInfo::addAwayRedCard(RedCard* redCard) {
    awayRedCards.push_back(redCard);
}

const std::list<RedCard*>& MatchInfo::getAwayRedCards() const {
    return awayRedCards;
}