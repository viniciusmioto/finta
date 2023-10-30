#ifndef YELLOW_CARD_HPP
#define YELLOW_CARD_HPP

#include "Fact.hpp"

class YellowCard : virtual public Fact {
   public:
    YellowCard(Player* player, std::string minute);

    virtual ~YellowCard();
};

#endif // YELLOW_CARD_HPP