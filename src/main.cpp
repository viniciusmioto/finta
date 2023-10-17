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
    try {
        boost::property_tree::ptree root;
        boost::property_tree::read_json("../data/Brasileirao2022.json", root);

        std::string userChoice;
        int matchDaySelection;

        // Prompt the user for input to choose the child node
        std::cout << "Enter the match day: ";
        std::cin >> userChoice;

        while (std::stoi(userChoice) < 1 || std::stoi(userChoice) > 38) {
            std::cout << yellow_text << "Invalid input. Please enter a number between 1 and 38: " << reset_text;
            std::cin >> userChoice;
        }

        try {
            matchDaySelection = std::stoi(userChoice);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. Please enter an integer." << std::endl;
            return 1;
        }

        for (const auto& match :
             root.get_child(std::to_string(matchDaySelection))) {
            std::string homeTeam = match.second.get<std::string>("clubs.home");
            int homeGoals = match.second.get<int>("goals.home");
            std::string awayTeam = match.second.get<std::string>("clubs.away");
            int awayGoals = match.second.get<int>("goals.away");

            // Print match result
            std::cout << homeTeam << " " << homeGoals << " x " << awayGoals
                      << " " << awayTeam << std::endl;
        }
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
