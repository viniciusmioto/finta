#include "League.hpp"

League::League(std::string name) : name{name} {}

League::League(std::string name, std::list<Team*> teams)
    : name{name}, teams(teams) {}

League::League(std::string name, std::list<Team*> teams,
               std::list<Match*> matches)
    : name{name}, teams(teams), matches(matches) {}

League::~League() {
    for (Team* team : teams) delete team;

    for (Match* match : matches) delete match;
}

std::string League::getName() const { return this->name; }

void League::setName(std::string name) { this->name = name; }

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
    boost::property_tree::ptree data;
    try {
        boost::property_tree::read_json(filePath, data);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
    for (unsigned short matchDay = 1; matchDay <= 38; ++matchDay) {
        for (const auto& match : data.get_child(std::to_string(matchDay))) {
            std::string homeTeam = match.second.get<std::string>("clubs.home");
            unsigned short homeGoals =
                match.second.get<unsigned short>("goals.home");
            std::string awayTeam = match.second.get<std::string>("clubs.away");
            unsigned short awayGoals =
                match.second.get<unsigned short>("goals.away");

            // Find or create the Team* pointers for home and away teams
            Team* homeTeamPtr = findOrCreateTeam(homeTeam);
            Team* awayTeamPtr = findOrCreateTeam(awayTeam);

            MatchInfo* matchInfo =
                new MatchInfo{match.second.get<std::string>("date"),
                              match.second.get<std::string>("hour"),
                              match.second.get<std::string>("stadium")};

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

                        bool isOwnGoal =
                            (minute.find("(GC)") != std::string::npos);

                        if (isOwnGoal)
                            matchInfo->addHomeGoal(new Goal{
                                awayTeamPtr->findOrCreatePlayer(playerName),
                                minute, isOwnGoal});
                        else
                            matchInfo->addHomeGoal(new Goal{
                                homeTeamPtr->findOrCreatePlayer(playerName),
                                minute, isOwnGoal});
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
                        bool isOwnGoal =
                            (minute.find("(GC)") != std::string::npos);

                        if (isOwnGoal)
                            matchInfo->addAwayGoal(new Goal{
                                homeTeamPtr->findOrCreatePlayer(playerName),
                                minute, isOwnGoal});
                        else
                            matchInfo->addAwayGoal(new Goal{
                                awayTeamPtr->findOrCreatePlayer(playerName),
                                minute, isOwnGoal});
                    }
                }
            }

            // Extract yellow cards for the home team
            for (const auto& yellowCard :
                 match.second.get_child("cards.home.yellow")) {
                std::string playerName =
                    yellowCard.second.get<std::string>("player");
                std::string minute = yellowCard.second.get<std::string>("time");

                matchInfo->addHomeYellowCard(new YellowCard{
                    homeTeamPtr->findOrCreatePlayer(playerName), minute});
            }

            // Extract yellow cards for the away team
            for (const auto& yellowCard :
                 match.second.get_child("cards.away.yellow")) {
                std::string playerName =
                    yellowCard.second.get<std::string>("player");
                std::string minute = yellowCard.second.get<std::string>("time");

                matchInfo->addAwayYellowCard(new YellowCard{
                    awayTeamPtr->findOrCreatePlayer(playerName), minute});
            }

            // Extract red cards for the home team
            for (const auto& redCard :
                 match.second.get_child("cards.home.red")) {
                std::string playerName =
                    redCard.second.get<std::string>("player");
                std::string minute = redCard.second.get<std::string>("time");

                matchInfo->addHomeRedCard(new RedCard{
                    homeTeamPtr->findOrCreatePlayer(playerName), minute});
            }

            // Extract red cards for the away team
            for (const auto& redCard :
                 match.second.get_child("cards.away.red")) {
                std::string playerName =
                    redCard.second.get<std::string>("player");
                std::string minute = redCard.second.get<std::string>("time");

                matchInfo->addAwayRedCard(new RedCard{
                    awayTeamPtr->findOrCreatePlayer(playerName), minute});
            }

            std::string homeCoach = match.second.get<std::string>("coach.home");
            std::string awayCoach = match.second.get<std::string>("coach.away");

            MatchResult* matchResult =
                new MatchResult{homeTeamPtr, awayTeamPtr, homeGoals, awayGoals};

            // Update the team staff stats
            homeTeamPtr->updateStaffStats(homeTeamPtr->findOrCreateStaff(homeCoach), homeGoals - awayGoals);
            awayTeamPtr->updateStaffStats(awayTeamPtr->findOrCreateStaff(awayCoach), awayGoals - homeGoals);

            // Add the match
            this->matches.push_back(
                new Match{matchDay, matchResult, matchInfo});
        }
    }
}

const std::list<Match*>& League::getMatches() const { return this->matches; }

const std::list<Team*>& League::getTeams() const { return this->teams; }