#include "./Mafia.hpp"

Mafia::Mafia() { std::cout << "object created!" << std::endl; }

void Mafia::add_player(std::string player_name) {
    players.push_back(new Player(player_name));
}