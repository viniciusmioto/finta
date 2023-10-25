#ifndef MATCH_HPP
#define MATCH_HPP

#include "MatchInfo.hpp"
#include "MatchResult.hpp"

class Match {
   public:
    Match(unsigned short matchDay, MatchResult* matchResult);
    Match(unsigned short matchDay, MatchResult* matchResult, MatchInfo* matchInfo);

    unsigned int getId() const;
    unsigned short getMatchDay() const;
    void setMatchDay(const unsigned short matchDay);
    MatchResult* getMatchResult() const;
    MatchInfo* getMatchInfo() const;
    void setMatchResult(MatchResult* matchResult);
    void setMatchInfo(MatchInfo* matchInfo);

   private:
    static unsigned long int nextId;
    unsigned long int id;
    unsigned short matchDay;
    MatchResult* matchResult;
    MatchInfo* matchInfo;
};

#endif  // MATCH_HPP