#include "MatchResult.hpp"
#include <iostream>

int main() {
    // Create a MatchResult object with initial values
    MatchResult match("Chelsea", "Liverpool", 3, 1);

    // Print the initial match result
    std::cout << "Match result: " << match.getMatchResult() << std::endl;

    return 0;
}
