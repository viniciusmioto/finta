#include "YellowCard.hpp"

YellowCard::YellowCard(Player* player, std::string minute)
    : Fact(player, minute) {
    player->setYellowCards(player->getYellowCards() + 1);
}
