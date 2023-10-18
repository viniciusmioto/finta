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

// #include <iostream>
// #include <algorithm>
// #include <fstream>

// #include "Console.hpp"

// int main() {
//     // Create teams
//     Team homeTeam{"A. Paranaense"};
//     Team awayTeam{"Botafogo"};
//     Team team3{"Corinthians"};
//     Team team4{"Gremio"};

//     std::list<Team*> teams{&homeTeam, &awayTeam, &team3, &team4};

//     // Create match results (homeTeam)
//     MatchResult matchResult{&homeTeam, &awayTeam, 2, 1};
//     MatchResult matchResult2{&homeTeam, &team3, 3, 0};
//     MatchResult matchResult3{&homeTeam, &team4, 1, 2};

//     // Create more match results (awayTeam)
//     MatchResult matchResult6{&awayTeam, &homeTeam, 1, 3};
//     MatchResult matchResult7{&awayTeam, &team3, 1, 1};
//     MatchResult matchResult8{&awayTeam, &team4, 2, 1};

//     // Create more match results (team3)
//     MatchResult matchResult11{&team3, &homeTeam, 0, 1};
//     MatchResult matchResult12{&team3, &awayTeam, 2, 2};
//     MatchResult matchResult13{&team3, &team4, 0, 0};

//     // Create more match results (team4)
//     MatchResult matchResult16{&team4, &homeTeam, 2, 2};
//     MatchResult matchResult17{&team4, &awayTeam, 1, 2};
//     MatchResult matchResult18{&team4, &team3, 1, 0};

//     // Create a list of all match results
//     std::list<MatchResult*> matchResults{&matchResult, &matchResult2,
//     &matchResult3,
//                                          &matchResult6, &matchResult7,
//                                          &matchResult8, &matchResult11,
//                                          &matchResult12, &matchResult13,
//                                          &matchResult16, &matchResult17,
//                                          &matchResult18};

//     // print all match results
//     Console::printMatchResults(matchResults);

//     // print match results of homeTeam
//     Console::printMatchResults(homeTeam);

//     Console::printTable(teams);

//     return 0;
// }
