#ifndef MATCH_STATS_HPP
#define MATCH_STATS_HPP

#include <iostream>
#include <string>

namespace finta {
class MatchStats {
    friend std::ostream& operator<<(std::ostream& os,
                                    const MatchStats& matchStats);

   public:
    MatchStats();
    MatchStats(unsigned short shots, unsigned short shotsOnTarget,
               unsigned short possession, unsigned short passes,
               unsigned short passAccuracy, unsigned short fouls,
               unsigned short yellowCards, unsigned short redCards,
               unsigned short offsides, unsigned short corners);

    unsigned short getShots() const;
    void setShots(const unsigned short shots);

    unsigned short getShotsOnTarget() const;
    void setShotsOnTarget(const unsigned short shotsOnTarget);

    unsigned short getPossession() const;
    void setPossession(const unsigned short possession);

    unsigned short getPasses() const;
    void setPasses(const unsigned short passes);

    unsigned short getPassAccuracy() const;
    void setPassAccuracy(const unsigned short passAccuracy);

    unsigned short getFouls() const;
    void setFouls(const unsigned short fouls);

    unsigned short getYellowCards() const;
    void setYellowCards(const unsigned short yellowCards);

    unsigned short getRedCards() const;
    void setRedCards(const unsigned short redCards);

    unsigned short getOffsides() const;
    void setOffsides(const unsigned short offsides);

    unsigned short getCorners() const;
    void setCorners(const unsigned short corners);

   private:
    unsigned short shots;
    unsigned short shotsOnTarget;
    unsigned short possession;
    unsigned short passes;
    unsigned short passAccuracy;
    unsigned short fouls;
    unsigned short yellowCards;
    unsigned short redCards;
    unsigned short offsides;
    unsigned short corners;
};
}  // namespace finta
#endif  // MATCH_STATS_HPP