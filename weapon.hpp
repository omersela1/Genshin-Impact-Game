//Omer Sela - 314977570, Omer Portnoy - 207251018
#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "element.hpp"



enum Weapon
{
    Sword, Polearm, Catalyst, Claymore, Bow
};

char* Weapon2Str(Weapon weapon);
Weapon strToWeapon(char* str);