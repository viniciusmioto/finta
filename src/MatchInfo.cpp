#include "MatchInfo.hpp"

namespace finta{

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

MatchInfo::MatchInfo(std::string matchDate, std::string matchTime,
                     std::string matchPlace, std::list<Goal*> homeGoals,
                     std::list<Goal*> awayGoals,
                     std::list<Fact*> homeYellowCards,
                     std::list<Fact*> awayYellowCards,
                     std::list<Fact*> homeRedCards,
                     std::list<Fact*> awayRedCards)
    : matchDate{matchDate},
      matchTime{matchTime},
      matchPlace{matchPlace},
      homeGoals{homeGoals},
      awayGoals{awayGoals},
      homeYellowCards{homeYellowCards},
      awayYellowCards{awayYellowCards},
      homeRedCards{homeRedCards},
      awayRedCards{awayRedCards} {}

MatchInfo::~MatchInfo() {
    for (auto goal : homeGoals) delete goal;
    for (auto goal : awayGoals) delete goal;
    for (auto yellowCard : homeYellowCards) delete yellowCard;
    for (auto yellowCard : awayYellowCards) delete yellowCard;
    for (auto redCard : homeRedCards) delete redCard;
    for (auto redCard : awayRedCards) delete redCard;
}

std::string MatchInfo::getMatchDate() const { return this->matchDate; }

void MatchInfo::setMatchDate(const std::string& matchDate) {
    this->matchDate = matchDate;
}

std::string MatchInfo::getMatchHour() const { return this->matchTime; }

void MatchInfo::setMatchHour(const std::string& matchTime) {
    this->matchTime = matchTime;
}

std::string MatchInfo::getMatchPlace() const { return this->matchPlace; }

void MatchInfo::setMatchPlace(const std::string& matchPlace) {
    this->matchPlace = matchPlace;
}

const std::list<Goal*>& MatchInfo::getHomeGoals() const {
    return this->homeGoals;
}

void MatchInfo::addHomeGoal(Goal* goal) { this->homeGoals.push_back(goal); }

const std::list<Goal*>& MatchInfo::getAwayGoals() const {
    return this->awayGoals;
}

void MatchInfo::addAwayGoal(Goal* goal) { this->awayGoals.push_back(goal); }

const std::list<Fact*>& MatchInfo::getHomeYellowCards() const {
    return this->homeYellowCards;
}

void MatchInfo::addHomeYellowCard(Fact* yellowCard) {
    this->homeYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getAwayYellowCards() const {
    return this->awayYellowCards;
}

void MatchInfo::addAwayYellowCard(Fact* yellowCard) {
    this->awayYellowCards.push_back(yellowCard);
}

const std::list<Fact*>& MatchInfo::getHomeRedCards() const {
    return this->homeRedCards;
}

void MatchInfo::addHomeRedCard(Fact* redCard) {
    this->homeRedCards.push_back(redCard);
}

const std::list<Fact*>& MatchInfo::getAwayRedCards() const {
    return this->awayRedCards;
}

void MatchInfo::addAwayRedCard(Fact* redCard) {
    this->awayRedCards.push_back(redCard);
}

std::ostream& operator<<(std::ostream& os, const finta::MatchInfo& matchInfo) {
    os << "🗓️  Date: " << matchInfo.getMatchDate() << std::endl;
    os << "🕖 Time: " << matchInfo.getMatchHour() << std::endl;
    os << "🏟️  Stadium: " << matchInfo.getMatchPlace() << "\n" << std::endl;

    os << "Home goals: " << std::endl;

    for (auto goal : matchInfo.getHomeGoals())
        os << "⚽  " << *goal << std::endl;

    os << std::endl;

    os << "Away goals: " << std::endl;

    for (auto goal : matchInfo.getAwayGoals())
        os << "⚽  " << *goal << std::endl;

    os << std::endl;

    os << "Home cards: " << std::endl;

    for (auto yellowCard : matchInfo.getHomeYellowCards())
        os << "🟨  " << *yellowCard << std::endl;

    for (auto redCard : matchInfo.getHomeRedCards())
        os << "🟥  " << *redCard << std::endl;

    os << std::endl;

    os << "Away cards: " << std::endl;

    for (auto yellowCard : matchInfo.getAwayYellowCards())
        os << "🟨  " << *yellowCard << std::endl;

    for (auto redCard : matchInfo.getAwayRedCards())
        os << "🟥  " << *redCard << std::endl;

    return os;
}
}  // namespace finta