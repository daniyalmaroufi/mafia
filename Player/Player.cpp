#include "./Player.hpp"

Player::Player(std::string name_) { name = name_; }

bool Player::is_name(std::string name_) { return name == name_; }
