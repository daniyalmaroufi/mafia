#ifndef __BULLETPROOF__
#define __BULLETPROOF__

#include <iostream>
#include <vector>
#include <string>
#include "../main/defines.hpp"
#include "./Villager.hpp"

class BulletProof : public Villager {
   public:
    BulletProof(std::string name_);
    BulletProof(){};
    void show_info();

   private:
   bool killed_once;
};

#endif