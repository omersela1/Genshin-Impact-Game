//Omer Sela - 314977570, Omer Portnoy - 207251018
#pragma once
using namespace std;
#include "character.hpp"


class Player
{
    char* userName;
   Character* activeCharacters[4];
   Character* dataCharacters[100];
   int dataIndex;

   public:
   Player();
   ~Player();
   bool addCharacterToData();
   bool addCharacterFromMain(Character* ch);
   bool editActiveTeam();
   void printCharacters();
   void getChar(int num);
   int printActiveCharacters();
   char* getName();
   int getIndex() { return dataIndex; };
   void evaluate();

};

void printMenu1();
Character& getFromFile(fstream f);