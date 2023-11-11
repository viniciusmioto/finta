#include "MatchStats.hpp"

std::ostream& operator<<(std::ostream& os, const MatchStats& stats) {
    os << "🥅 Shots: " << stats.getShots() << std::endl;
    os << "🎯 Shots on target: " << stats.getShotsOnTarget() << std::endl;
    os << "✳️  Possession: " << stats.getPossession() << "%" << std::endl;
    os << "👟 Passes: " << stats.getPasses() << std::endl;
    os << "✅ Pass accuracy: " << stats.getPassAccuracy() << "%" << std::endl;
    os << "💢 Fouls: " << stats.getFouls() << std::endl;
    os << "🟨 Yellow cards: " << stats.getYellowCards() << std::endl;
    os << "🟥 Red cards: " << stats.getRedCards() << std::endl;
    os << "🚫 Offsides: " << stats.getOffsides() << std::endl;
    os << "⛳ Corners: " << stats.getCorners() << std::endl;

    return os;
}

MatchStats::MatchStats()
    : shots{0},
      shotsOnTarget{0},
      possession{0},
      passes{0},
      passAccuracy{0},
      fouls{0},
      yellowCards{0},
      redCards{0},
      offsides{0},
      corners{0} {}

MatchStats::MatchStats(unsigned short shots, unsigned short shotsOnTarget,
                       unsigned short possession, unsigned short passes,
                       unsigned short passAccuracy, unsigned short fouls,
                       unsigned short yellowCards, unsigned short redCards,
                       unsigned short offsides, unsigned short corners)
    : shots{shots},
      shotsOnTarget{shotsOnTarget},
      possession{possession},
      passes{passes},
      passAccuracy{passAccuracy},
      fouls{fouls},
      yellowCards{yellowCards},
      redCards{redCards},
      offsides{offsides},
      corners{corners} {}

// getters
unsigned short MatchStats::getShots() const { return shots; }
unsigned short MatchStats::getShotsOnTarget() const { return shotsOnTarget; }
unsigned short MatchStats::getPossession() const { return possession; }
unsigned short MatchStats::getPasses() const { return passes; }
unsigned short MatchStats::getPassAccuracy() const { return passAccuracy; }
unsigned short MatchStats::getFouls() const { return fouls; }
unsigned short MatchStats::getYellowCards() const { return yellowCards; }
unsigned short MatchStats::getRedCards() const { return redCards; }
unsigned short MatchStats::getOffsides() const { return offsides; }
unsigned short MatchStats::getCorners() const { return corners; }

// setters
void MatchStats::setShots(const unsigned short shots) { this->shots = shots; }
void MatchStats::setShotsOnTarget(const unsigned short shotsOnTarget) {
    this->shotsOnTarget = shotsOnTarget;
}
void MatchStats::setPossession(const unsigned short possession) {
    this->possession = possession;
}
void MatchStats::setPasses(const unsigned short passes) {
    this->passes = passes;
}
void MatchStats::setPassAccuracy(const unsigned short passAccuracy) {
    this->passAccuracy = passAccuracy;
}
void MatchStats::setFouls(const unsigned short fouls) { this->fouls = fouls; }
void MatchStats::setYellowCards(const unsigned short yellowCards) {
    this->yellowCards = yellowCards;
}
void MatchStats::setRedCards(const unsigned short redCards) {
    this->redCards = redCards;
}
void MatchStats::setOffsides(const unsigned short offsides) {
    this->offsides = offsides;
}
void MatchStats::setCorners(const unsigned short corners) {
    this->corners = corners;
}
