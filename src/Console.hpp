#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>
#include "Team.hpp"
#include "MatchResult.hpp"

class Console {
    public:
        Console();
        static void printMatchResults(Team& team);
};

#endif // CONSOLE_HPP
