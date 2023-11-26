#include "Team.hpp"

Team::Team(std::string name)
    : name{name},
      points{0},
      wins{0},
      draws{0},
      losses{0},
      goals{0},
      goalsAgainst{0},
      goalDifference{0} {}

Team::~Team() {
    for (auto staff : staff) delete staff;

    for (auto player : players) delete player;
}

std::string Team::getName() const { return this->name; }

void Team::setName(const std::string& name) { this->name = name; }

const std::list<MatchResult*>& Team::getMatchResults() const {
    return this->matchResults;
}

void Team::addMatchResult(MatchResult* matchResult) {
    // Check if the matchResult pointer is not null
    if (matchResult) {
        // Add the matchResult to the team's list of match results
        this->matchResults.push_back(matchResult);
    }
}

unsigned short int Team::getPoints() const { return this->points; }

void Team::addPoints(const unsigned short int points) {
    this->points += points;
}

unsigned short int Team::getWins() const { return this->wins; }

void Team::addWins(const unsigned short int wins) { this->wins += wins; }

unsigned short int Team::getDraws() const { return this->draws; }

void Team::addDraws(const unsigned short int draws) { this->draws += draws; }

unsigned short int Team::getLosses() const { return this->losses; }

void Team::addLosses(const unsigned short int losses) {
    this->losses += losses;
}

unsigned short int Team::getGoals() const { return this->goals; }

void Team::addGoals(const unsigned short int goals) { this->goals += goals; }

const std::list<Staff*>& Team::getStaff() const { return this->staff; }

void Team::addStaff(Staff* staff) {
    // Check if the staff pointer is not null
    if (staff) {
        // Add the staff to the team's list of staff
        this->staff.push_back(staff);
    }
}

Staff* Team::findOrCreateStaff(const std::string& staffName) {
    // Check if the staff member exists in the team's list of staff
    for (Staff* staffMember : staff) {
        // Check if the staff member's name matches the given name
        if (*staffMember == staffName) {
            // Return the staff member
            return staffMember;
        }
    }

    // Create a new staff member
    Staff* staffMember{new Staff(staffName)};

#ifdef DEBUG
    std::cout << "Created new staff member: " << staffName << std::endl;
#endif

    // Add the staff member to the team's list of staff
    this->staff.push_back(staffMember);

    // Return the staff member
    return staffMember;
}

void Team::updateStaffStats(Staff* staffMember, short result) {
    // check result
    if (result == 0) {  // draw
        staffMember->setDraws(staffMember->getDraws() + 1);
    } else if (result >= 1) {  // win
        staffMember->setWins(staffMember->getWins() + 1);
    } else if (result <= -1) {  // lose
        staffMember->setLosses(staffMember->getLosses() + 1);
    }

    staffMember->setMatches(staffMember->getMatches() + 1);
}

const std::list<Player*>& Team::getPlayers() const { return this->players; }

void Team::addPlayer(Player* player) {
    // Check if the player pointer is not null
    if (player)
        // Add the player to the team's list of players
        this->players.push_back(player);
}

Player* Team::findOrCreatePlayer(const std::string& playerName) {
    // Check if the player exists in the team's list of players
    for (Player* player : players)
        // Check if the player's name matches the given name
        if (*player == playerName)
            // Return the player
            return player;

    // Create a new player
    Player* player{new Player(playerName)};

#ifdef DEBUG
    std::cout << "Created new player: " << playerName << std::endl;
#endif

    // Add the player to the team's list of players
    this->players.push_back(player);

    // Return the player
    return player;
}

short int Team::getGoalsAgainst() const { return this->goalsAgainst; }

void Team::addGoalsAgainst(const short int goalsAgainst) {
    this->goalsAgainst += goalsAgainst;
}

short int Team::getGoalDifference() const { return this->goalDifference; }

void Team::setGoalDifference(const short int goalDifference) {
    this->goalDifference = goalDifference;
}

bool Team::operator==(const Team& team) const {
    return this->name == team.name;
}

bool Team::operator==(const std::string& name) const {
    return this->name == name;
}

bool Team::operator>(const Team& otherTeam) const {
    // Compare the points
    // if the points are equal, compare by wins
    // if the wins are equal, compare by goals difference
    // if the goals difference is equal, compare by goals scored

    if (this->points > otherTeam.points) {
        return true;
    } else if (this->points == otherTeam.points) {
        if (this->wins > otherTeam.wins) {
            return true;
        } else if (this->wins == otherTeam.wins) {
            if (this->goalDifference > otherTeam.goalDifference) {
                return true;
            } else if (this->goalDifference == otherTeam.goalDifference) {
                if (this->goals > otherTeam.goals) {
                    return true;
                }
            }
        }
    }

    return false;
}