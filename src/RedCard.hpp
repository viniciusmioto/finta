#ifndef RED_CARD_HPP
#define RED_CARD_HPP

#include "Fact.hpp"

class RedCard : virtual public Fact {
   public:
    RedCard(Player* player, std::string minute);

    virtual ~RedCard() = default;
};

#endif