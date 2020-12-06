#ifndef __DETECTIVE__
#define __DETECTIVE__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Villager.hpp"

class Detective : public Villager {
   public:
    Detective(std::string name_);
    Detective(){};
    void show_info();
    bool need_to_wake_up();

   private:
};

#endif