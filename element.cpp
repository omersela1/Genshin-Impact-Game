//Omer Sela - 314977570, Omer Portnoy - 207251018
#include "element.hpp"

Element strToElem(char* str) {
    
    if (strcmp("Anemo", str) == 0)
        return Anemo;
    if (strcmp("Pyro", str) == 0)
        return Pyro;
    if (strcmp("Cyro", str) == 0)
        return Cyro;
    if (strcmp("Hydro", str) == 0)
        return Hydro;
    if (strcmp("Electro", str) == 0)
        return Electro;
    if (strcmp("Geo", str) == 0)
        return Geo;
    if (strcmp("Dendro", str) == 0)
        return Dendro;
}