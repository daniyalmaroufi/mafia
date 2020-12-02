#include <iostream>

#include "./defines.hpp"
#include "../Mafia/Mafia.hpp"
#include "../Player/Player.hpp"
#include "../GameManager/GameManager.hpp"

using namespace std;

int main(){
    GameManager game;
    game.handle_inputs();
    return 0;
}