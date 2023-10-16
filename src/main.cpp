#include <iostream>
#include <algorithm>
#include <fstream>

#include "Console.hpp"
#include "Team.hpp"
#include "Person.hpp"
#include "Player.hpp"

int main() {
    // Create teams
    Team cap{"A. Paranaense"};

    // Create players
    Player player1{"Santos", "GK", 1};
    Player player2{"Jonathan", "RB", 2};
    Player player3{"Thiago Heleno", "CB", 4};
    Player player4{"Léo Pereira", "CB", 28};
    Player player5{"Márcio Azevedo", "LB", 6};
    Player player6{"Wellington", "CM", 5};
    Player player7{"Bruno Guimarães", "CM", 39};
    Player player8{"Léo Cittadini", "CM", 18};
    Player player9{"Rony", "RW", 7};
    Player player10{"Marco Ruben", "ST", 9};
    Player player11{"Nikão", "LW", 11};


    // Create staff
    Person coach{"Tiago Nunes"};
    Person assistantCoach{"Evandro Fornari"};

    // Add players to team
    cap.addPlayer(&player1);
    cap.addPlayer(&player2);
    cap.addPlayer(&player3);
    cap.addPlayer(&player4);
    cap.addPlayer(&player5);
    cap.addPlayer(&player6);
    cap.addPlayer(&player7);
    cap.addPlayer(&player8);
    cap.addPlayer(&player9);
    cap.addPlayer(&player10);
    cap.addPlayer(&player11);

    // Add staff to team
    cap.addStaff(&coach);
    cap.addStaff(&assistantCoach);

    // create iterator to show players
    auto it = cap.getPlayers().begin();

    // Show players
    std::cout << "Jogadores do " << cap.getName() << ":" << std::endl;
    for (; it != cap.getPlayers().end(); ++it) {
        std::cout << (*it)->getName() << " - " << (*it)->getPosition()
                  << " - Nº " << (int)(*it)->getJerseyNumber() << std::endl;
    }

    // create iterator to show staff
    auto it2 = cap.getStaff().begin();

    // Show staff
    std::cout << "Comissão técnica do " << cap.getName() << ":" << std::endl;
    for (; it2 != cap.getStaff().end(); ++it2) {
        std::cout << (*it2)->getName() << std::endl;
    }
    

    return 0;
}
