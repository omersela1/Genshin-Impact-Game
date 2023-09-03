//Omer Sela - 314977570, Omer Portnoy - 207251018
#include "player.hpp"
char mBUFFER[1024];



int main() {
    Character c1("Blabla", "Home", Anemo, Sword, 3);
    epicCharacter e1("Pinto", "Home", Pyro, Polearm, 4);
    legendaryCharacter l1("NAKNIK", "Mordor", Geo, Polearm, 5, "Salami");
    legendaryCharacter l2("PORTNOY", "Matan", Electro, Polearm, 5, "Choopapi");
    epicCharacter e2("Dean", "TelAviv", Pyro, Bow, 4);
    Character c2("Marcelo", "Shenkar", Dendro, Polearm, 2);
    legendaryCharacter l3("Spongebob", "BikiniBottom", Hydro, Catalyst, 5, "Spatula");

    Player p1;
    p1.addCharacterFromMain(&c1);
    p1.addCharacterFromMain(&e1);
    p1.addCharacterFromMain(&l1);
    p1.addCharacterFromMain(&l2);
    p1.addCharacterFromMain(&e2);
    p1.addCharacterFromMain(&c2);
    p1.addCharacterFromMain(&l3);

   




    cout << "Hello " << p1.getName() << endl;
    cout<<"Welcome to GENSHIN !!"<<endl;
    int isOn = 1;
    char charPick;
 

    while (isOn != 0) {
        cout << endl;
        printMenu1();
        char select;
        cin >> select;
        select -= 48;

        switch (select)
        {
        case 1:
        {
        cout << p1.getIndex() << endl;
        p1.addCharacterToData();
        cout << p1.getIndex() << endl;
        // p1.printCharacters();
        break;
        }
        case 2:
        {
            cout<<"Choose character"<<endl;
            int x = p1.printActiveCharacters();
            if (x)
            {
                cin>>charPick;
                charPick -= 48;
            while (charPick<1|| charPick>x)
            {
                cout<<"Error index"<<endl;
                cin>>charPick;
                charPick -= 48;
            }
            p1.getChar(charPick);
            }    
            break;
        }
        case 3:
        {
            p1.editActiveTeam();
            break;
        }
        case 4:
        {
            p1.evaluate();
            break;
        }
        case 0:
        {
            isOn = 0;
            break;
        }
        
        default:
            break;
        }
    }
    return 0;
}