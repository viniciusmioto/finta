#include "Team.hpp"

Team::Team(std::string name): name{name} {}

std::string Team::getName() { return this->name; }

void Team::setName(std::string name) { this->name = name; }
