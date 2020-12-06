#ifndef __DOCTOR__
#define __DOCTOR__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Villager.hpp"

class Doctor : public Villager {
   public:
    Doctor(std::string name_);
    Doctor(){};
    void show_info();
    bool need_to_wake_up();

   private:
};

#endif