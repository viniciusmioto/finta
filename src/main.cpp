#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "Console.hpp"
#include "MatchResult.hpp"
#include "Team.hpp"

int main() {
    Team amg{"América-MG"};
    Team cap{"Athletico-PR"};
    Team acg{"Atlético-GO"};
    Team cam{"Atlético-MG"};
    Team afc{"Avaí"};
    Team bfr{"Botafogo"};
    Team rbb{"Bragantino"};
    Team csc{"Ceará SC"};
    Team sccp{"Corinthians"};
    Team cfc{"Coritiba"};
    Team cec{"Cuiabá"};
    Team crf{"Flamengo"};
    Team ffc{"Fluminense"};
    Team fec{"Fortaleza"};
    Team gec{"Goiás"};
    Team sci{"Internacional"};
    Team ecj{"Juventude"};
    Team sep{"Palmeiras"};
    Team sfc{"Santos"};
    Team spfc{"São Paulo"};

    std::list<Team*> teams{
        &amg, &cap, &acg, &cam, &afc, &bfr, &rbb, &csc, &sccp, &cfc,
        &cec, &crf, &ffc, &fec, &gec, &sci, &ecj, &sep, &sfc,  &spfc,
    };

    std::list<MatchResult*> matchResults;

    
    try {
        boost::property_tree::ptree root;
        boost::property_tree::read_json("../data/Brasileirao2022.json", root);

        for (int matchDay = 1; matchDay <= 38; ++matchDay) {
            for (const auto& match : root.get_child(std::to_string(matchDay))) {
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
                    matchResults.push_back(new MatchResult(homeTeamPtr, awayTeamPtr, homeGoals, awayGoals));
                }
            }
        }

        // print all match results
        Console::printMatchResults(matchResults);

        // print all match results of cap
        Console::printMatchResults(cap);

        // show classification table
        Console::printTable(teams);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}