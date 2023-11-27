#ifndef STAFF_HPP
#define STAFF_HPP

#include <iostream>
#include <string>

#include "Person.hpp"

namespace finta {
class Staff : public Person {
   public:
    Staff(std::string name);

    unsigned short getMatches() const;
    void setMatches(const unsigned short matches);

    unsigned short getWins() const;
    void setWins(const unsigned short wins);

    unsigned short getDraws() const;
    void setDraws(const unsigned short draws);

    unsigned short getLosses() const;
    void setLosses(const unsigned short losses);

    unsigned short getResultPercentage() const;

   private:
    unsigned short matches;
    unsigned short wins;
    unsigned short draws;
    unsigned short losses;
};
}  // namespace finta
#endif  // STAFF_HPP