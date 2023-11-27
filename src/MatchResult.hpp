#ifndef MATCH_RESULT_HPP
#define MATCH_RESULT_HPP

#include <cstdint>
#include <string>

#include "Team.hpp"

namespace finta {
class MatchResult {
    friend std::ostream& operator<<(std::ostream& os,
                                    const MatchResult& matchResult);

   public:
    MatchResult(Team* homeTeam, Team* awayTeam,
                unsigned short int homeTeamScore,
                unsigned short int awayTeamScore);

    Team* getHomeTeam() const;
    void setHomeTeam(Team* homeTeam);

    Team* getAwayTeam() const;
    void setAwayTeam(Team* awayTeam);

    unsigned short int getHomeTeamScore() const;
    void setHomeTeamScore(unsigned short int homeTeamScore);

    unsigned short int getAwayTeamScore() const;
    void setAwayTeamScore(unsigned short int awayTeamScore);

   private:
    Team* homeTeam;
    Team* awayTeam;
    unsigned short int homeTeamScore;
    unsigned short int awayTeamScore;
};
}  // namespace finta
#endif  // MATCH_RESULT_HPP
