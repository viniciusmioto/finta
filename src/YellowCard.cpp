#include "YellowCard.hpp"

using namespace finta;

YellowCard::YellowCard(Player* player, std::string minute)
    : Fact(player, minute) {
    player->setYellowCards(player->getYellowCards() + 1);
}
