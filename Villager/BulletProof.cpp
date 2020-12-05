#include "./BulletProof.hpp"

BulletProof::BulletProof(std::string name_) : Villager(name_) {}

void BulletProof::show_info() {
    std::cout << name << ": "
              << "bulletproof" << std::endl;
}
