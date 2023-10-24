#include "MatchInfo.hpp"

MatchInfo::MatchInfo(std::string matchDate, std::string matchTime,
                     std::string matchPlace)
    : matchDate{matchDate}, matchTime{matchTime}, matchPlace{matchPlace} {}

MatchInfo::MatchInfo(std::string matchDate, std::string matchTime,
                     std::string matchPlace, std::list<Goal*> goals)
    : matchDate{matchDate},
      matchTime{matchTime},
      matchPlace{matchPlace},
      goals{goals} {}

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

void MatchInfo::addGoal(Goal* goal) {
    std::cout << "Add Goal: " << std::endl;
    std::cout << goal->getPlayer()->getName() << std::endl;
    std::cout << goal->getTime() << std::endl;
    std::cout << goal->getTeam()->getName() << std::endl;

    std::cout << std::endl;

    goals.push_back(goal);
}

std::list<Goal*> MatchInfo::getGoals() const { return goals; }