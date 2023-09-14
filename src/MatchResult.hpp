#ifndef MATCHRESULT_HPP
#define MATCHRESULT_HPP

#include <string>

class MatchResult {
private:
    std::string team1;
    std::string team2;
    int score1;
    int score2;

public:
    MatchResult();
    MatchResult(const std::string& team1, const std::string& team2, int score1, int score2);

    // Getter methods
    std::string getTeam1() const;
    std::string getTeam2() const;
    int getScore1() const;
    int getScore2() const;

    // Setter method
    void setMatchResult(const std::string& team1, const std::string& team2, int score1, int score2);

    // Method to get the match result as a string
    std::string getMatchResult() const;
};

#endif // MATCHRESULT_HPP
