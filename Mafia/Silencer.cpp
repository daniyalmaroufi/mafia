#include "./Silencer.hpp"

Silencer::Silencer(std::string name_) : Mafia(name_) { done_nighttask = false; }

void Silencer::show_info() {
    std::cout << name << ": "
              << "silencer" << std::endl;
}

bool Silencer::do_nighttask_on(Player* second_player) {
    if (!done_nighttask) {
        if (second_player->get_status() != alive) throw DeadPerson();
        second_player->silence();

        done_nighttask = true;
    } else {
        if (second_player->get_status() != alive) throw DeadVotee();
        return true;
    }
    return false;
}
