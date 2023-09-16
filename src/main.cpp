#include <iostream>
#include "Console.hpp"
#include <algorithm>

int main() {
    // Create teams
    Team homeTeam{"A. Paranaense"};
    Team awayTeam{"Botafogo"};
    Team team3{"Corinthians"};
    Team team4{"Gremio"};

    std::list<Team*> teams{&homeTeam, &awayTeam, &team3, &team4};

    // Create match results (homeTeam)
    MatchResult matchResult{&homeTeam, &awayTeam, 2, 1};
    MatchResult matchResult2{&homeTeam, &team3, 3, 0};
    MatchResult matchResult3{&homeTeam, &team4, 1, 2};

    // Create more match results (awayTeam)
    MatchResult matchResult6{&awayTeam, &homeTeam, 1, 3};
    MatchResult matchResult7{&awayTeam, &team3, 1, 1};
    MatchResult matchResult8{&awayTeam, &team4, 2, 1};

    // Create more match results (team3)
    MatchResult matchResult11{&team3, &homeTeam, 0, 1};
    MatchResult matchResult12{&team3, &awayTeam, 2, 2};
    MatchResult matchResult13{&team3, &team4, 0, 0};

    // Create more match results (team4)
    MatchResult matchResult16{&team4, &homeTeam, 2, 2};
    MatchResult matchResult17{&team4, &awayTeam, 1, 2};
    MatchResult matchResult18{&team4, &team3, 1, 0};

    // Create a list of all match results
    std::list<MatchResult*> matchResults{&matchResult, &matchResult2, &matchResult3,
                                         &matchResult6, &matchResult7, &matchResult8,
                                         &matchResult11, &matchResult12, &matchResult13,
                                         &matchResult16, &matchResult17, &matchResult18};

    
    // print all match results
    Console::printMatchResults(matchResults);

    // print match results of homeTeam
    Console::printMatchResults(homeTeam);

    Console::printTable(teams);

    return 0;
}
