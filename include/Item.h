#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Item
{
    public:
        Item();
        virtual ~Item();
        char GetCode(){return code;}
        int GetVersion(){return version;}
        void SetCode(char c){code=c;}
        void SetVersion(int n){version=n;}

        Item * GetNext(){return next;}
        void SetNext(Item * ptr){next=ptr;}







    private:
        char code; ///Armor, Weapon, Other, Spell
        int version; ///Type of Armor, Type of Weapon, etc..
        Item * next;
};

#endif // ITEM_H
