#ifndef YELLOW_CARD_HPP
#define YELLOW_CARD_HPP

#include "Fact.hpp"

namespace finta {
class YellowCard : virtual public Fact {
   public:
    YellowCard(Player* player, std::string minute);

    virtual ~YellowCard() = default;
};
}  // namespace finta
#endif  // YELLOW_CARD_HPP