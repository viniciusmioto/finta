#include "RedCard.hpp"

using namespace finta;

RedCard::RedCard(Player* player, std::string minute) : Fact(player, minute) {
    player->setRedCards(player->getRedCards() + 1);
}
