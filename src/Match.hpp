#ifndef MATCH_HPP
#define MATCH_HPP

#include "MatchInfo.hpp"
#include "MatchResult.hpp"
#include "MatchStats.hpp"

class Match {
    friend std::ostream& operator<<(std::ostream& os, const Match& match);

   public:
    Match(unsigned short matchDay, MatchResult* matchResult);
    Match(unsigned short matchDay, MatchResult* matchResult,
          MatchInfo* matchInfo);
    Match(unsigned short matchDay, MatchResult* matchResult,
          MatchInfo* matchInfo, MatchStats* homeMatchStats,
          MatchStats* awayMatchStats);
    
    virtual ~Match();

    unsigned int getId() const;

    unsigned short getMatchDay() const;
    void setMatchDay(const unsigned short matchDay);

    MatchResult* getMatchResult() const;
    void setMatchResult(MatchResult* matchResult);

    MatchInfo* getMatchInfo() const;
    void setMatchInfo(MatchInfo* matchInfo);

    MatchStats* getHomeMatchStats() const;
    void setHomeMatchStats(MatchStats* homeMatchStats);

    MatchStats* getAwayMatchStats() const;
    void setAwayMatchStats(MatchStats* awayMatchStats);

   private:
    static unsigned long int nextId;
    unsigned long int id;
    unsigned short matchDay;
    MatchResult* matchResult;
    MatchInfo* matchInfo;
    MatchStats* homeMatchStats;
    MatchStats* awayMatchStats;
};

#endif  // MATCH_HPP