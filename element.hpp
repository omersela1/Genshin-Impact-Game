//Omer Sela - 314977570, Omer Portnoy - 207251018
#pragma once
#include <cstring>
#include <iostream>
using namespace std;
#include "weapon.hpp"

enum Element {
    Anemo, Pyro, Cyro, Hydro, Electro, Geo, Dendro, Generic
};


Element strToElem(char* str);