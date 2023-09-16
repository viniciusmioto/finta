#include <iostream>
#include "Console.hpp"

int main() {
    // Create teams
    Team team1{"Athletico Paranaense"};
    Team team2{"Botafogo"};
    Team team3{"Corinthians"};
    Team team4{"Grêmio"};

    // Create match results (team1)
    MatchResult matchResult{&team1, &team2, 2, 1};
    MatchResult matchResult2{&team1, &team3, 3, 0};
    MatchResult matchResult3{&team1, &team4, 1, 2};

    // Create more match results (team2)
    MatchResult matchResult6{&team2, &team1, 1, 3};
    MatchResult matchResult7{&team2, &team3, 1, 1};
    MatchResult matchResult8{&team2, &team4, 2, 1};

    // Create more match results (team3)
    MatchResult matchResult11{&team3, &team1, 0, 1};
    MatchResult matchResult12{&team3, &team2, 2, 2};
    MatchResult matchResult13{&team3, &team4, 0, 0};

    // Create more match results (team4)
    MatchResult matchResult16{&team4, &team1, 2, 2};
    MatchResult matchResult17{&team4, &team2, 1, 2};
    MatchResult matchResult18{&team4, &team3, 1, 0};


    // print match results
    Console::printMatchResults(team1);
    Console::printMatchResults(team2);
    Console::printMatchResults(team3);
    Console::printMatchResults(team4);

    return 0;
}
