#include "./Silencer.hpp"

Silencer::Silencer(std::string name_) : Mafia(name_) { done_nighttask = false; }

void Silencer::show_info() {
    std::cout << name << ": "
              << "silencer" << std::endl;
}

bool Silencer::need_to_wake_up() { return true; }

bool Silencer::do_nighttask_on(Player* second_player) {
    if (!done_nighttask) {
        if (second_player->get_status() != alive) throw DeadPerson();
        second_player->silence();

        done_nighttask = true;
    } else {
        return Mafia::do_nighttask_on(second_player);
    }
    return false;
}
