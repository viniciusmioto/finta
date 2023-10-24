#include "League.hpp"

League::League(std::list<Team*> teams) : teams(teams) {}

League::League(std::list<Team*> teams, std::list<Match*> matches)
    : teams(teams), matches(matches) {}

void League::addTeams(std::list<Team*> teams) { this->teams = teams; }

void League::addMatch(Match* match) { matches.push_back(match); }

Team* League::findOrCreateTeam(const std::string& teamName) {
    // Search for the team in the existing list
    for (Team* team : teams) {
        if (teamName == team->getName()) {
            return team;
        }
    }

    // If the team is not found, create a new team and add it to the list
    Team* newTeam = new Team(teamName);
    teams.push_back(newTeam);

#ifdef DEBUG
    std::cout << "Created new team: " << teamName << std::endl;
#endif

    return newTeam;
}  // accurate

void League::fillMatches(const std::string& filePath) {
    try {
        boost::property_tree::ptree data;
        boost::property_tree::read_json(filePath, data);

        for (int matchDay = 1; matchDay <= 38; ++matchDay) {
            for (const auto& match : data.get_child(std::to_string(matchDay))) {
                std::string homeTeam =
                    match.second.get<std::string>("clubs.home");
                int homeGoals = match.second.get<int>("goals.home");
                std::string awayTeam =
                    match.second.get<std::string>("clubs.away");
                int awayGoals = match.second.get<int>("goals.away");

                // Find or create the Team* pointers for home and away teams
                Team* homeTeamPtr = findOrCreateTeam(homeTeam);
                Team* awayTeamPtr = findOrCreateTeam(awayTeam);

                // Add the match result
                this->matches.push_back(new Match(
                    matchDay, new MatchResult(homeTeamPtr, awayTeamPtr,
                                              homeGoals, awayGoals)));

                std::cout << "Match day " << matchDay << " - " << homeTeam
                          << " vs. " << awayTeam << std::endl;
                std::cout << "Home Team  Goal Scorers : ";
                // Print the goal scorers for this match
                if (homeGoals > 0) {
                    const boost::property_tree::ptree& homeGoalScorers =
                        match.second.get_child("goalsPlayer.home");

                    for (const auto& scorer : homeGoalScorers) {
                        std::string playerName =
                            scorer.second.get<std::string>("player");
                        std::cout << playerName << " ";
                    }
                    std::cout << std::endl;
                }
                if (awayGoals > 0) {
                    const boost::property_tree::ptree& awayGoalScorers =
                        match.second.get_child("goalsPlayer.away");

                    std::cout << "Away Team Goal Scorers: ";
                    for (const auto& scorer : awayGoalScorers) {
                        std::string playerName =
                            scorer.second.get<std::string>("player");
                        std::cout << playerName << " ";
                    }

                    std::cout << std::endl;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
}

const std::list<Match*>& League::getMatches() const { return this->matches; }

const std::list<Team*>& League::getTeams() const { return this->teams; }