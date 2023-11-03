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

MatchInfo::~MatchInfo() {
    for (auto goal : homeGoals) delete goal;
    for (auto goal : awayGoals) delete goal;
    for (auto yellowCard : homeYellowCards) delete yellowCard;
    for (auto yellowCard : awayYellowCards) delete yellowCard;
    for (auto redCard : homeRedCards) delete redCard;
    for (auto redCard : awayRedCards) delete redCard;
}

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

void MatchInfo::addHomeYellowCard(Fact* yellowCard) {
    homeYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getHomeYellowCards() const {
    return homeYellowCards;
}

void MatchInfo::addAwayYellowCard(Fact* yellowCard) {
    awayYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getAwayYellowCards() const {
    return awayYellowCards;
}

void MatchInfo::addHomeRedCard(Fact* redCard) {
    homeRedCards.push_back(redCard);
}

const std::list<Fact*>& MatchInfo::getHomeRedCards() const {
    return homeRedCards;
}

void MatchInfo::addAwayRedCard(Fact* redCard) {
    awayRedCards.push_back(redCard);
}

const std::list<Fact*>& MatchInfo::getAwayRedCards() const {
    return awayRedCards;
}