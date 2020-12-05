#include "./GodFather.hpp"

GodFather::GodFather(std::string name_) : Mafia(name_) {}

void GodFather::show_info() {
    std::cout << name << ": "
              << "godfather" << std::endl;
}
