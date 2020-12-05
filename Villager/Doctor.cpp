#include "./Doctor.hpp"

Doctor::Doctor(std::string name_) : Villager(name_) {}

void Doctor::show_info() {
    std::cout << name << ": "
              << "doctor" << std::endl;
}
