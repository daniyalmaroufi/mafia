#include "./Player.hpp"

Player::Player(std::string name_) {
    name = name_;
    status = alive;
}

bool Player::is_name(std::string name_) { return name == name_; }

Player_status Player::get_status() { return status; }
