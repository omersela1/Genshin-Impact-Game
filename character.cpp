
//Omer Sela - 314977570, Omer Portnoy - 207251018
#include "character.hpp"
char cBUFFER[1024];

Character::Character()
{
    name = new char[10];
    if (!name)
    {
        cout<<"Error in"<< __PRETTY_FUNCTION__<<endl;
        return;
    }
    
    strcpy(name,"Empty");
    type = Generic;
}

Character::Character(char *cname, char *clocation, Element ctype, Weapon cweaponType, int cstars)
{
    name = new char[strlen(cname) + 1];
    // check null
    strcpy(name, cname);

    location = new char[strlen(clocation) + 1];
    // check null
    strcpy(location, clocation);

    equippedWeapon = new char[1];
    equippedWeapon[0] = '\0';
    type = ctype;
    weaponType = cweaponType;
    stars = cstars;
}

legendaryCharacter::legendaryCharacter(char *name, char *location, Element type, Weapon weaponType, int stars, char *sigWeapon) : Character(name, location, type, weaponType, 5)
{
    signatureWeapon = new char[strlen(sigWeapon) + 1];
    if (!signatureWeapon)
    {
        cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
        return;
    }
    strcpy(signatureWeapon, sigWeapon);
}

Character::~Character()
{
    delete[] name;
    delete[] location;
    delete[] equippedWeapon;
}

void Character::printCharacter()
{
    cout << name;
    if (strlen(name) <= 6)
        cout << "  ";
    cout << "\t\t";
    cout << location << "\t";
    if (strlen(location) <= 7)
        cout << "\t";
    cout << Weapon2Str(weaponType) << "\t" << getEquipped() << endl;
}

int Character::Attack()
{
    return 1;
}

// int Character::editWeapon(char* weapon)
// {
//     delete[] equippedWeapon;
//     equippedWeapon = new char[strlen(weapon) + 1];
//     if (!equippedWeapon) {
//         cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
//         return 0;
//     }
//     strcpy(equippedWeapon, weapon);
//     return 1;
// }

void Character::setWeaponName(char* weapon)
{
    delete[] equippedWeapon;
    cout << "check" << endl;
    equippedWeapon = new char[strlen(weapon) + 1];
    if (!equippedWeapon)
    {
        cout<<"Error in"<<__PRETTY_FUNCTION__<<endl;
        return;
    }
    strcpy(equippedWeapon, weapon);
}
void Character::editWeapon()
{
    delete[] equippedWeapon;
            char weap;
            char weaponName[20];
            cout << "Choose a new weapon type" << endl;
            cout << "1.Sword" << endl;
            cout << "2.Polearm" << endl;
            cout << "3.Catalyst" << endl;
            cout << "4.Claymore" << endl;
            cout << "5.Bow" << endl;
            cin>>weap;
            weap -= 48;
            if (weap < 1 || weap > 5)
            {
                cout << "Invalid choice" << endl;
                cin >> weap;
            }
            
            switch (weap)
            {
            case 1:
            {
                weaponType = Sword;
                break;
            }
            case 2:
            {
                weaponType = Polearm;
                break;
            }
            case 3:
            {
                weaponType = Catalyst;
                break;
            }
            case 4:
            {
                weaponType = Claymore;
                break;
            }
            case 5:
            {
                weaponType = Bow;
                break;
            }
            
            default:
                break;
            }
            cout<<"Weapon nickname: "<<endl;
            cin>>weaponName;
            equippedWeapon = new char[strlen(weaponName) + 1];
            strcpy(equippedWeapon, weaponName);
            cout<<"Weapon is now of type "<< Weapon2Str(weaponType) <<" called "<<this->getEquipped()<<endl;
    // int pick;
    // if (stars == 5)
    // {
    //     cout << "Choose type of weapon to switch" << endl;
    //     cout << "1. Weapon" << endl;
    //     cout << "2.Signature weapon" << endl;
    //     cin >> pick;
    //     if (pick < 1 || pick > 2)
    //     {
    //         cout << "Invalid choice" << endl;
    //         cin >> pick;
    //     }
    //     switch (pick)
    //     {
    //     case 1:
    //         delete[] equippedWeapon;
    //         int weap;
    //         cout << "Choose a new weapon" << endl;
    //         cout << "1.Sword" << endl;
    //         cout << "2.Polearm" << endl;
    //         cout << "3.Catalyst" << endl;
    //         cout << "4.Claymore" << endl;
    //         cout << "5.Bow" << endl;
    //         cin>>weap;
    //         if (weap<1 || weap>5)
    //         {
    //             cout<<"Invalid choice"<<endl;
    //             cin>>weap;
    //         }
            
    //         switch (weap)
    //         {
    //         case 1:
    //             weaponType = Sword;
    //             cout<<"Weapon is now "<< this->getWeapon()<<endl;
    //             break;
    //         case 2:
    //             weaponType = Polearm;
    //             cout<<"Weapon is now "<< this->getWeapon()<<endl;
    //             break;
    //         case 3:
    //             weaponType = Catalyst;
    //             cout<<"Weapon is now "<< this->getWeapon()<<endl;
    //             break;
    //         case 4:
    //             weaponType = Claymore ;
    //             cout<<"Weapon is now "<< this->getWeapon()<<endl;
    //             break;
    //         case 5:
    //             weaponType = Bow;
    //             cout<<"Weapon is now "<< this->getWeapon()<<endl;
    //             break;
            
    //         default:
    //             break;
    //         }
    //     case 2:
    //         cout<<"Enter new Signature weapon"<<endl;
    //         cin>>cBUFFER;
    //         char* newSig = new char[strlen(cBUFFER)+1];
    //         if (!newSig)
    //         {
    //             cout<<"Error in"<<__PRETTY_FUNCTION__<<endl;
    //             return;
    //         }
    //         changeSignatureWeapon(newSig);
    //         break;

    //     default:
    //         break;
    //     }
    // }
    // if (stars == 4)
    // {
    //     cout<<"Choose weapon to switch"<<endl;

    // }
    
    // delete[] equippedWeapon;

    // cout << "Choose a new weapon" << endl;
    // cout << "1.Sword" << endl;
    // cout << "2.Polearm" << endl;
    // cout << "3.Catalyst" << endl;
    // cout << "4.Claymore" << endl;
    // cout << "5.Bow" << endl;
}

int legendaryCharacter::Attack()
{
    return 1;
}

epicCharacter::epicCharacter(char *name, char *location, Element type, Weapon weaponType, int stars) : Character(name, location, type, weaponType, 4)
{
}

Character &Character::operator=(Character &ch)
{
    // strcpy(cBUFFER, ch.name);
    // delete[] name;
    // name = new char[strlen(cBUFFER) + 1];
    // strcpy(name, cBUFFER);
}

int epicCharacter::Attack()
{
    return 1;
}

char *Character::getLocation()
{
    return location;
}

char *Character::getName()
{
    return name;
}

int Character::getStars()
{
    return stars;
}
Weapon Character::getEweapon()
{
    return weaponType;
}

char *Character::getWeapon()
{
    char *the_weapon;
    the_weapon = new char[20];
    if (!the_weapon)
    {
        cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
    if (weaponType == Sword)
    {
        strcpy(the_weapon, "Sword");
    }
    if (weaponType == Polearm)
    {
        strcpy(the_weapon, "Polearm");
    }
    if (weaponType == Catalyst)
    {
        strcpy(the_weapon, "Catalyst");
    }
    if (weaponType == Claymore)
    {
        strcpy(the_weapon, "Claymore");
    }
    if (weaponType == Bow)
    {
        strcpy(the_weapon, "Bow");
    }

    return the_weapon;
}


char *Character::getType()
{
    char *the_type;
    the_type = new char[20];
    if (!the_type)
    {
        cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
        return 0;
    }
    if (type == Anemo)
    {
        strcpy(the_type, "Anemo(Wind)");
    }
    if (type == Pyro)
    {
        strcpy(the_type, "Pyro(Fire)");
    }
    if (type == Cyro)
    {
        strcpy(the_type, "Cyro(Frost)");
    }
    if (type == Hydro)
    {
        strcpy(the_type, "Hydro(Water)");
    }
    if (type == Electro)
    {
        strcpy(the_type, "Electro(like Picachu)");
    }
    if (type == Geo)
    {
        strcpy(the_type, "Geo(Earth)");
    }
    if (type == Dendro)
    {
        strcpy(the_type, "Dendro(Nature)");
    }
    return the_type;
}

Element Character::getElement()
{
    return type;
}

epicCharacter::~epicCharacter()
{
    //
}

legendaryCharacter::~legendaryCharacter()
{
    delete[] signatureWeapon;
}
