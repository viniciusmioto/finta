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

        for (unsigned short matchDay = 1; matchDay <= 38; ++matchDay) {
            for (const auto& match : data.get_child(std::to_string(matchDay))) {
                std::string homeTeam =
                    match.second.get<std::string>("clubs.home");
                unsigned short homeGoals =
                    match.second.get<unsigned short>("goals.home");
                std::string awayTeam =
                    match.second.get<std::string>("clubs.away");
                unsigned short awayGoals =
                    match.second.get<unsigned short>("goals.away");

                // Find or create the Team* pointers for home and away teams
                Team* homeTeamPtr = findOrCreateTeam(homeTeam);
                Team* awayTeamPtr = findOrCreateTeam(awayTeam);

                MatchInfo* matchInfo =
                    new MatchInfo(match.second.get<std::string>("date"),
                                  match.second.get<std::string>("hour"),
                                  match.second.get<std::string>("stadium"));

                if (homeGoals > 0) {
                    const boost::property_tree::ptree& homeGoalScorers =
                        match.second.get_child("goalsPlayer.home");

                    for (const auto& scorer : homeGoalScorers) {
                        std::string playerName =
                            scorer.second.get<std::string>("player");
                        const boost::property_tree::ptree& goals =
                            scorer.second.get_child("gols");

                        for (const auto& goal : goals) {
                            std::string minute = goal.second.data();
                            matchInfo->addHomeGoal(new Goal{
                                homeTeamPtr->findOrCreatePlayer(playerName),
                                minute,
                                homeTeamPtr
                            });
                        }
                    }
                }
                if (awayGoals > 0) {
                    const boost::property_tree::ptree& awayGoalScorers =
                        match.second.get_child("goalsPlayer.away");

                    for (const auto& scorer : awayGoalScorers) {
                        std::string playerName =
                            scorer.second.get<std::string>("player");
                        const boost::property_tree::ptree& goals =
                            scorer.second.get_child("gols");

                        for (const auto& goal : goals) {
                            std::string minute = goal.second.data();
                            matchInfo->addAwayGoal(new Goal{
                                awayTeamPtr->findOrCreatePlayer(playerName),
                                minute,
                                awayTeamPtr
                            });
                        }
                    }
                }

                // Add the match
                this->matches.push_back(
                    new Match{matchDay,
                              new MatchResult{homeTeamPtr, awayTeamPtr,
                                              homeGoals, awayGoals},
                              matchInfo});
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
}

const std::list<Match*>& League::getMatches() const { return this->matches; }

const std::list<Team*>& League::getTeams() const { return this->teams; }