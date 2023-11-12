#include "MatchInfo.hpp"

std::ostream& operator<<(std::ostream& os, const MatchInfo& matchInfo) {
    os << "🗓️  Date: " << matchInfo.matchDate << std::endl;
    os << "🕖 Time: " << matchInfo.matchTime << std::endl;
    os << "🏟️  Stadium: " << matchInfo.matchPlace << "\n" << std::endl;

    os << "Home goals: " << std::endl;

    for (auto goal : matchInfo.homeGoals) os << "⚽  " << *goal << std::endl;

    os << std::endl;

    os << "Away goals: " << std::endl;

    for (auto goal : matchInfo.awayGoals) os << "⚽  " << *goal << std::endl;

    os << std::endl;

    os << "Home cards: " << std::endl;

    for (auto yellowCard : matchInfo.homeYellowCards)
        os << "🟨  " << *yellowCard << std::endl;

    for (auto redCard : matchInfo.homeRedCards)
        os << "🟥  " << *redCard << std::endl;

    os << std::endl;

    os << "Away cards: " << std::endl;

    for (auto yellowCard : matchInfo.awayYellowCards)
        os << "🟨  " << *yellowCard << std::endl;

    for (auto redCard : matchInfo.awayRedCards)
        os << "🟥  " << *redCard << std::endl;

    return os;
}

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

void MatchInfo::setMatchDate(const std::string& matchDate) {
    this->matchDate = matchDate;
}

std::string MatchInfo::getMatchHour() const { return matchTime; }

void MatchInfo::setMatchHour(const std::string& matchTime) {
    this->matchTime = matchTime;
}

std::string MatchInfo::getMatchPlace() const { return matchPlace; }

void MatchInfo::setMatchPlace(const std::string& matchPlace) {
    this->matchPlace = matchPlace;
}

const std::list<Goal*>& MatchInfo::getHomeGoals() const { return homeGoals; }

void MatchInfo::addHomeGoal(Goal* goal) { homeGoals.push_back(goal); }

const std::list<Goal*>& MatchInfo::getAwayGoals() const { return awayGoals; }

void MatchInfo::addAwayGoal(Goal* goal) { awayGoals.push_back(goal); }

const std::list<Fact*>& MatchInfo::getHomeYellowCards() const {
    return homeYellowCards;
}

void MatchInfo::addHomeYellowCard(Fact* yellowCard) {
    homeYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getAwayYellowCards() const {
    return awayYellowCards;
}

void MatchInfo::addAwayYellowCard(Fact* yellowCard) {
    awayYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getHomeRedCards() const {
    return homeRedCards;
}

void MatchInfo::addHomeRedCard(Fact* redCard) {
    homeRedCards.push_back(redCard);
}

const std::list<Fact*>& MatchInfo::getAwayRedCards() const {
    return awayRedCards;
}

void MatchInfo::addAwayRedCard(Fact* redCard) {
    awayRedCards.push_back(redCard);
}