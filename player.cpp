//Omer Sela - 314977570, Omer Portnoy - 207251018
#include "player.hpp"
char pBUFFER[1024];
int choice;


void printMenu1()
{
    // cout << "\t\t GENSHIN IMPACT " << endl;
    cout << "1.) Add new character to data" << endl;
    cout << "2.) Edit character weapon" << endl;
    cout << "3.) Edit active team" << endl;
    cout << "4.) Evaluate team" << endl << endl;
    cout << "0.) Quit" << endl;
}



Player::Player()
{
    dataIndex = 0;
    cout << "Enter user name: ";
    cin >> pBUFFER;
    cout << endl;
    userName = new char[strlen(pBUFFER) + 1];
    if (!userName) {
        cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
        return;
    }
    strcpy(userName, pBUFFER);
    for (int i = 0; i < 4; i++)
    {
        activeCharacters[i] = new Character;
    }
    
}

Player::~Player()
{
    delete[] userName;
}

 bool Player::addCharacterToData()
 {

      cout << "Enter character name: ";
            cin >> pBUFFER;
            char* cname = new char[strlen(pBUFFER) + 1];
            if (!cname)
            {
                cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
                return false;
            }
            strcpy(cname, pBUFFER);
            cout << endl << "Enter location: ";
            cin >> pBUFFER;
            char* cloc = new char[strlen(pBUFFER) + 1];
            if (!cloc)
            {
                cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
                return false;
            }
            strcpy(cloc, pBUFFER);
            cout << endl << "Enter type: "<<endl;
            cout<<"1. Wind"<<endl;
            cout<<"2. Fire"<<endl;
            cout<<"3. Frost"<<endl;
            cout<<"4. Water"<<endl;
            cout<<"5. Electro"<<endl;
            cout<<"6. Earth"<<endl;
            cout<<"7. Nature"<<endl;
            cin >> choice;
            while (choice<1 ||choice>7)
            {
                cout<<"Invalid Type.."<<endl;
                cin>> choice;
            }
            Element e;
            switch (choice)
            {
            case 1:
                 e = Anemo;
                break;
            case 2:
                 e = Pyro;
                break;
            case 3:
                 e = Cyro;
                break;
            case 4:
                 e = Hydro;
                break;
            case 5:
                 e = Electro;
                break;
            case 6:
                 e = Geo;
                break;
            case 7:
                 e = Dendro;
                break;
            
            default:
                break;
            }
            cout << endl << "Choose equipped weapon: "<<endl;
            cout<<"1.Sword"<<endl;
            cout<<"2.Polearm"<<endl;
            cout<<"3.Catalyst"<<endl;
            cout<<"4.Claymore"<<endl;
            cout<<"5.Bow"<<endl;
            cin >> choice;
            if (choice<1 || choice >5)
            {
                cout<<"Invalid weapon"<<endl;
                cin>>choice;
            }
            Weapon w;
            switch (choice)
            {
            case 1:
                w = Sword;
                break;
            case 2:
                w = Polearm;
                break;
            case 3:
                w = Catalyst;
                break;
            case 4:
                w = Claymore;
                break;
            case 5:
                w = Bow;
                break;
            default:
                break;
            }
            int stars;
            cout << endl << "Choose stars: "<<endl;
            cout<<"4 - Epic character"<<endl;
            cout<<"5 - Legendary character"<<endl;
            cin >> stars;
            if (stars<4 || stars>5)
            {
                cout<<"Invalid Stars level"<<endl;
                cin>>stars;
            }
            
            if (stars == 4) {
                epicCharacter *added = new epicCharacter(cname, cloc, e, w, stars);
                dataCharacters[dataIndex] = added;
                dataIndex++;
                cout<<"New character has been added sucssefully"<<endl;
                cout<<"Name:"<<added->getName()<<" Location:"<<added->getLocation()<<" Element:"<<added->getType()<<" Weapon:"<<added->getWeapon()<<" Stars:"<<added->getStars()<<endl;
            }
            if (stars == 5) {
                cout << "Enter signature weapon: ";
                cin >> pBUFFER;
                char* sig = new char[strlen(pBUFFER) + 1];
                if (!sig)
                {
                    cout << "ERROR in: " << __PRETTY_FUNCTION__ << endl;
                    return false;
                }
                strcpy(sig, pBUFFER);
                legendaryCharacter *added = new legendaryCharacter(cname, cloc, e, w, stars, sig);
                dataCharacters[dataIndex] = added;
                dataIndex++;
                delete[] sig;
                 cout<<"New character has been added sucssefully"<<endl;
                cout<<"Name:"<<added->getName()<<" Location:"<<added->getLocation()<<" Element:"<<added->getType()<<" Weapon:"<<added->getWeapon()<<" Stars:"<<added->getStars()<<" Signature Weapon:"<<added->getSig()<<endl;
            }

            
            // if (stars < 4 && stars > 0) {
            //     Character added(cname, cloc, e, w, stars);
            //     dataCharacters[dataIndex] = &added;
            //     dataIndex++;
            // }
        
        
        delete[] cname;
        delete[] cloc;

return true;

}
char* Player::getName()
{
    return userName;
}

void Player::printCharacters()
{
    
    
    int i = 0;
    
    while (i < dataIndex) {
        cout << i + 1 << ".) ";
        dataCharacters[i]->printCharacter();
        cout << endl;
        i++;
    }


}

int Player::printActiveCharacters()
{
    int x = 0;
    cout<<"Name:\t\t\tLocation:\tWeapon:"<<endl;
    for (int i = 0; i < 4; i++)
    {
        if (activeCharacters[i]->getElement() != Generic)
        {
            cout<<i+1<<".";
            activeCharacters[i]->printCharacter();
            x++;
        }
        else 
        {
            cout << i+1 << ". empty";
            cout << endl;
            x++;
        }
        
    }
    return x;
}

bool Player::addCharacterFromMain(Character* ch)
{
    dataCharacters[dataIndex] = ch;
    // if (dataIndex < 4) {
    //     activeCharacters[dataIndex] = ch;
    // }
    dataIndex++;
    return true;

}

bool Player::editActiveTeam()
{
    int i = 0;
    while (activeCharacters[i]->getElement() != Generic && i < 4)
    {
        i++;
    };
    char select;
    if (i == 4) {
    i -= 1;
    cout << "Choose a character to remove: " << endl;
    printActiveCharacters();
    cin >> select;
    select -= 48;
    if (select < 1 || select > 4) {
        cout << "NO SUCH OPTION!" << endl;
        cin >> select;
        select -= 48;
    }
         activeCharacters[select - 1] = activeCharacters[3];
    }

    cout << "Choose a character to add to the team: " << endl;
    printCharacters();
    cin >> select;
    select -= 48;
    activeCharacters[i] = dataCharacters[select - 1];
    printActiveCharacters();
    return true;
}

void Player::getChar(int num)
{
    activeCharacters[num - 1]->editWeapon();
}

void Player::evaluate()
{
    int n = 0;
    while (activeCharacters[n]->getElement() != Generic && n <= 3) {
        n++;
    }
    if (n < 4) {
        cout << "Your team is incomplete! please fill it and try again" << endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (j != i && !(strcmp(activeCharacters[j]->getLocation(), activeCharacters[i]->getLocation())))
                sum++;
        }
    }
    if (sum > 0) {
        cout << "Added " << sum * 10 << '%' << " to coordination." << endl;
    }

    sum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (j != i && (activeCharacters[i]->getElement() == activeCharacters[j]->getElement()))
                sum++;
        }
        if (sum > 0) {
            cout << "Added " << sum * 10 << '%' << " to element " << activeCharacters[i]->getType() << endl;
            sum = 0;
        }
    }


    int i = 0;
    while (i < 4) {
        switch (activeCharacters[i]->getEweapon())
        {
        case Sword:
        {
        cout << activeCharacters[i]->getName() << " Swings the sword." << endl;
        break;
        }

        case Polearm:
        {
        cout << activeCharacters[i]->getName() << " Attacks with polearm." << endl;
        break;
        }   

        case Catalyst:
        {
        cout << activeCharacters[i]->getName() << " Cast spells with catalyst." << endl;
        break;
        }

        case Claymore:
        {
        cout << activeCharacters[i]->getName() << " Swings the claymore." << endl;
        break;
        }

        case Bow:
        {
        cout << activeCharacters[i]->getName() << " Shoots arrows with a bow." << endl;
        break;
        }
        
        default:
            break;
        }
    if (activeCharacters[i]->getStars() == 5)
        cout << activeCharacters[i]->getName() << " Has a signature weapon! Double damage!" << endl;

    i++;

    }

cout << "Passable elements reactions: " << endl;

for (int h = 0; h < 3; h++)
    for (int k = h + 1; k < 4; k++) {
        if ((activeCharacters[h]->getElement() == Cyro && activeCharacters[k]->getElement() == Anemo) || (activeCharacters[k]->getElement() == Cyro && activeCharacters[h]->getElement() == Anemo))
            cout << "Blizzard" << endl;
        if ((activeCharacters[h]->getElement() == Dendro && activeCharacters[k]->getElement() == Pyro) || (activeCharacters[k]->getElement() == Dendro && activeCharacters[h]->getElement() == Pyro))
            cout << "Burn" << endl;
        if ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() == Anemo) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() == Anemo))
            cout << "Dust" << endl;
        if ((activeCharacters[h]->getElement() == Electro && activeCharacters[k]->getElement() == Hydro) || (activeCharacters[k]->getElement() == Electro && activeCharacters[h]->getElement() == Hydro))
            cout << "Electro-Charged" << endl;
        if ((activeCharacters[h]->getElement() == Cyro && activeCharacters[k]->getElement() == Hydro) || (activeCharacters[k]->getElement() == Cyro && activeCharacters[h]->getElement() == Hydro))
            cout << "Frozen" << endl;
        if ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() == Pyro) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() == Pyro))
            cout << "Magma" << endl;
        if ((activeCharacters[h]->getElement() == Cyro && activeCharacters[k]->getElement() == Pyro) || (activeCharacters[k]->getElement() == Cyro && activeCharacters[h]->getElement() == Pyro))
            cout << "Melt" << endl;
        if ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() == Hydro) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() == Hydro))
            cout << "Mud" << endl;
        if ((activeCharacters[h]->getElement() == Electro && activeCharacters[k]->getElement() == Pyro) || (activeCharacters[k]->getElement() == Electro && activeCharacters[h]->getElement() == Pyro))
            cout << "Overloaded" << endl;
        if ((activeCharacters[h]->getElement() == Dendro && activeCharacters[k]->getElement() == Hydro) || (activeCharacters[k]->getElement() == Dendro && activeCharacters[h]->getElement() == Hydro))
            cout << "Poison" << endl;
        if ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() == Cyro) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() == Cyro))
            cout << "Shatter" << endl;
        if ((activeCharacters[h]->getElement() == Electro && activeCharacters[k]->getElement() == Cyro) || (activeCharacters[k]->getElement() == Electro && activeCharacters[h]->getElement() == Cyro))
            cout << "Superconduct" << endl;
        if ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() == Dendro) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() == Dendro))
            cout << "Thorn" << endl;
        if ((activeCharacters[h]->getElement() == Hydro && activeCharacters[k]->getElement() == Pyro) || (activeCharacters[k]->getElement() == Hydro && activeCharacters[h]->getElement() == Pyro))
            cout << "Vaporize" << endl;
    }

    for (int h = 0; h < 3; h++)
    for (int k = h + 1; k < 4; k++) {
     if (((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() != Anemo) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() != Anemo))
                 && ((activeCharacters[h]->getElement() == Geo && activeCharacters[k]->getElement() != Dendro) || (activeCharacters[k]->getElement() == Geo && activeCharacters[h]->getElement() != Dendro)))
            cout << "Crystallize" << endl;
     if (((activeCharacters[h]->getElement() == Anemo && activeCharacters[k]->getElement() != Dendro) || (activeCharacters[k]->getElement() == Anemo && activeCharacters[h]->getElement() != Dendro))
                 && ((activeCharacters[h]->getElement() == Anemo && activeCharacters[k]->getElement() != Geo) || (activeCharacters[k]->getElement() == Anemo && activeCharacters[h]->getElement() != Geo)))
            cout << "Swirl" << endl;
            return;
    }
}

// Character& getFromFile(fstream f)
// {
//     char* search = new char[100];
//     cout << "Enter character name to add: ";
//     cin >> search;
//     cout << endl;
//     string s;
//     while(strcmp(s.c_str(), search) != 0) {
//         getline(f, s, ' ');
//     }
//     char* ch1 = new char[s.length() + 1];
//     strcpy(ch1, s.c_str());
//     string s2;
//     getline(f, s2);
//     char * ch2 = new char[s2.length() + 1];
//     strcpy(ch2, s2.c_str());
//     int star = s2.c_str()[1];

//     // cout << star;

//     char elem[10];
//     char weap[10];
//     char loc[10];
//     int i = 2;
//     int j = 0;
//     while (s2.c_str()[i] == ' ') {
//         i++;
//     }
//     while (s2.c_str()[i] != ' ') {
//         elem[j] = s2.c_str()[i];
//         j++;
//         i++;
//     }

//     Element e = strToElem(elem);

//     j = 0;
//     while (s2.c_str()[i] == ' ') {
//     i++;
//     }
//     while (s2.c_str()[i] != ' ') {
//         weap[j] = s2.c_str()[i];
//         j++;
//         i++;
//     }

//     Weapon w = strToWeapon(weap);
//     j = 0;
//     while (s2.c_str()[i] == ' ') {
//     i++;
//     }
//     while (s2.c_str()[i] != ' ') {
//         loc[j] = s2.c_str()[i];
//         j++;
//         i++;
//     }

//     j = 0;

//     if (star != 5) {
//     Character added(ch1, loc, e, w, star);
//     return added;
//     }

//     // char sigWeapon[20];

//     // if (star == 5) {
//     //     while (s2.c_str()[i] == ' ') {
//     //     i++;
//     //     }
//     //      while (s2.c_str()[i] != ' ') {
//     //     sigWeapon[j] = s2.c_str()[i];
//     //     j++;
//     //     i++;
//     //     }
//     // }

//     // legendaryCharacter added(ch1, loc, e, w, star, sigWeapon);
//     // return &added;


// }