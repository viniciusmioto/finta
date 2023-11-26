#ifndef MATCH_INFO_HPP
#define MATCH_INFO_HPP

#include "Goal.hpp"
#include "MatchResult.hpp"
#include "RedCard.hpp"
#include "YellowCard.hpp"

class MatchInfo {
    friend std::ostream& operator<<(std::ostream& os,
                                    const MatchInfo& matchInfo);

   public:
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace);
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace, std::list<Goal*> homeGoals,
              std::list<Goal*> awayGoals);
    MatchInfo(std::string matchDate, std::string matchTime,
              std::string matchPlace, std::list<Goal*> homeGoals,
              std::list<Goal*> awayGoals, std::list<Fact*> homeYellowCards,
              std::list<Fact*> awayYellowCards, std::list<Fact*> homeRedCards,
              std::list<Fact*> awayRedCards);

    virtual ~MatchInfo();

    std::string getMatchDate() const;
    void setMatchDate(const std::string& matchDate);

    std::string getMatchHour() const;
    void setMatchHour(const std::string& matchTime);

    std::string getMatchPlace() const;
    void setMatchPlace(const std::string& matchPlace);

    const std::list<Goal*>& getHomeGoals() const;
    void addHomeGoal(Goal* goal);

    const std::list<Goal*>& getAwayGoals() const;
    void addAwayGoal(Goal* goal);

    const std::list<Fact*>& getHomeYellowCards() const;
    void addHomeYellowCard(Fact* yellowCard);

    const std::list<Fact*>& getAwayYellowCards() const;
    void addAwayYellowCard(Fact* yellowCard);

    const std::list<Fact*>& getHomeRedCards() const;
    void addHomeRedCard(Fact* redCard);

    const std::list<Fact*>& getAwayRedCards() const;
    void addAwayRedCard(Fact* redCard);

   private:
    std::string matchDate;
    std::string matchTime;
    std::string matchPlace;
    std::list<Goal*> homeGoals;
    std::list<Goal*> awayGoals;
    std::list<Fact*> homeYellowCards;
    std::list<Fact*> awayYellowCards;
    std::list<Fact*> homeRedCards;
    std::list<Fact*> awayRedCards;
};

#endif  // MATCH_INFO_HPP