//Omer Sela - 314977570, Omer Portnoy - 207251018
#pragma once
#include <cstring>
#include <iostream>
using namespace std;
#include "element.hpp"

class Character
{
    char* name;
    char* location;
    Element type;
    Weapon weaponType;
    char* equippedWeapon;
    int stars;

    public:
    Character();
    Character(char* cname, char* clocation, Element ctype, Weapon cweaponType, int cstars);
    ~Character();
    Character& operator= (Character& ch);
    virtual int Attack();
    void editWeapon();
    void printCharacter();
    char* getLocation();
    char* getName();
    char* getType();
    Element getElement();
    int getStars();
    void setWeaponName(char* weapon);
    char* getEquipped(){return equippedWeapon;};
    char* getWeapon();
    Weapon getEweapon();
    virtual void changeSignatureWeapon(const char* newWeapon){};
};

class legendaryCharacter : public Character {
    char* signatureWeapon;

    public:
    legendaryCharacter();
    legendaryCharacter(char* name, char* location, Element type, Weapon weaponType, int stars, char* sigWeapon);
    char* getSig(){return signatureWeapon;}
    void changeSignatureWeapon(const char* newWeapon)
    {
        delete[] signatureWeapon;
        signatureWeapon = new char[strlen(newWeapon)+1];
        if (!signatureWeapon)
        {
            cout<<"Error in"<< __PRETTY_FUNCTION__<<endl;
            return;
        }
        strcpy(signatureWeapon,newWeapon);
        

    }
    ~legendaryCharacter();
    int Attack();
};

class epicCharacter : public Character {

    public:
    epicCharacter();
    epicCharacter(char* name, char* location, Element type, Weapon weaponType, int stars);
    ~epicCharacter();
    int Attack();
   
};