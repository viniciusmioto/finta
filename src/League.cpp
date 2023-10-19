#include "League.hpp"

League::League(std::list<Team*> teams) : teams(teams) {}

League::League(std::list<Team*> teams, std::list<MatchResult*> matchResults)
    : teams(teams), matchResults(matchResults) {}

League::~League() {
    for (Team* team : teams) {
        delete team;
    }
}

void League::addTeams(std::list<Team*> teams) { this->teams = teams; }

void League::addMatchResult(MatchResult* matchResult) {
    matchResults.push_back(matchResult);
}

void League::addMatchResults(std::list<MatchResult*> matchResults) {
    this->matchResults = matchResults;
}

void League::fillMatchResults(const std::string& filePath) {
    boost::property_tree::ptree data;
    boost::property_tree::read_json("../data/Brasileirao2022.json", data);

    for (int matchDay = 1; matchDay <= 38; ++matchDay) {
        for (const auto& match : data.get_child(std::to_string(matchDay))) {
            std::string homeTeam = match.second.get<std::string>("clubs.home");
            int homeGoals = match.second.get<int>("goals.home");
            std::string awayTeam = match.second.get<std::string>("clubs.away");
            int awayGoals = match.second.get<int>("goals.away");

            // Find the Team* pointers for home and away teams
            Team* homeTeamPtr = nullptr;
            Team* awayTeamPtr = nullptr;
            for (Team* team : teams) {
                if (homeTeam == team->getName()) {
                    homeTeamPtr = team;
                }
                if (awayTeam == team->getName()) {
                    awayTeamPtr = team;
                }
            }

            if (homeTeamPtr && awayTeamPtr) {
                this->matchResults.push_back(new MatchResult(
                    homeTeamPtr, awayTeamPtr, homeGoals, awayGoals));
            }
        }
    }
}

const std::list<MatchResult*>& League::getMatchResults() const {
    return this->matchResults;
}
