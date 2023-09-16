#include <iostream>
#include "Team.hpp"
#include "MatchResult.hpp"

int main() {
    // Create teams
    Team team1{"Chelsea"};
    Team team2{"Arsenal"};
    Team team3{"Tottenham"};
    Team team4{"Liverpool"};

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


    // Print all match results of team1
    std::cout << "Match results of " << team1.getName() << ":\n";
    std::list<MatchResult*>& matchResultsList = team1.getMatchResults();    
    std::list<MatchResult*>::iterator it;

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        std::cout << (*it)->getMatchResult() << "\n";
    }

    // Print all match results of team2
    std::cout << "\nMatch results of " << team2.getName() << ":\n";
    matchResultsList = team2.getMatchResults();

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        std::cout << (*it)->getMatchResult() << "\n";
    }

    // Print all match results of team3
    std::cout << "\nMatch results of " << team3.getName() << ":\n";
    matchResultsList = team3.getMatchResults();

    for (it = matchResultsList.begin(); it != matchResultsList.end(); it++) {
        std::cout << (*it)->getMatchResult() << "\n";
    }

    return 0;
}
