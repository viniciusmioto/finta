#include <iostream>
#include "MatchResult.hpp"
#include "Team.hpp"

int main() {
    // Create teams
    Team team1{"Chelsea"};
    Team team2{"Arsenal"};

    // Create match result
    MatchResult matchResult{&team1, &team2, 2, 1};

    // Print match result
    std::cout << "Match ID: " << matchResult.getId() << std::endl;
    std::cout << matchResult.getMatchResult() << std::endl;

    // new match result
    MatchResult matchResult2{&team2, &team1, 3, 3};
    std::cout << "Match ID: " << matchResult2.getId() << std::endl;
    std::cout << matchResult2.getMatchResult() << std::endl;

    return 0;
}
