#ifndef MATCH_STATS_HPP
#define MATCH_STATS_HPP

#include <iostream>
#include <string>

class MatchStats {
    friend std::ostream& operator<<(std::ostream& os, const MatchStats& matchStats);


   public:
    MatchStats();
    MatchStats(unsigned short shots, unsigned short shotsOnTarget,
               unsigned short possession, unsigned short passes,
               unsigned short passAccuracy, unsigned short fouls,
               unsigned short yellowCards, unsigned short redCards,
               unsigned short offsides, unsigned short corners);

    // getters
    unsigned short getShots() const;
    unsigned short getShotsOnTarget() const;
    unsigned short getPossession() const;
    unsigned short getPasses() const;
    unsigned short getPassAccuracy() const;
    unsigned short getFouls() const;
    unsigned short getYellowCards() const;
    unsigned short getRedCards() const;
    unsigned short getOffsides() const;
    unsigned short getCorners() const;

    // setters
    void setShots(const unsigned short shots);
    void setShotsOnTarget(const unsigned short shotsOnTarget);
    void setPossession(const unsigned short possession);
    void setPasses(const unsigned short passes);
    void setPassAccuracy(const unsigned short passAccuracy);
    void setFouls(const unsigned short fouls);
    void setYellowCards(const unsigned short yellowCards);
    void setRedCards(const unsigned short redCards);
    void setOffsides(const unsigned short offsides);
    void setCorners(const unsigned short corners);

    std::ostream& operator<<(std::ostream& os);

        private : unsigned short shots;
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

#endif  // MATCH_STATS_HPP