//Omer Sela - 314977570, Omer Portnoy - 207251018
#include "weapon.hpp"

Weapon strToWeapon(char* str)
{
    if (strcmp("Sword", str) == 0)
        return Sword;
    if (strcmp("Polearm", str) == 0)
        return Polearm;
    if (strcmp("Catalyst", str) == 0)
        return Catalyst;
    if (strcmp("Claymore", str) == 0)
        return Claymore;
    if (strcmp("Bow", str) == 0)
        return Bow;
}

char* Weapon2Str(Weapon weapon)
{
    if (weapon == Sword)
    {
        return "Sword";
    }
    if (weapon == Polearm)
    {
        return "Polearm";
    }
    if (weapon == Catalyst)
    {
        return "Catalyst";
    }
    if (weapon == Claymore)
    {
        return "Claymore";
    }
    if (weapon == Bow)
    {
        return "Bow";
    }
      
}