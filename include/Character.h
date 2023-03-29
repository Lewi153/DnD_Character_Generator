#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Biology.h"
#include "Race.h"
#include "Profession.h"
#include "Item.h"
using namespace std;

class Character : public Profession
{
    public:
        Character();
        virtual ~Character();
        void SetName(string name){Name=name;}

        void Display();
        void ItemGenerator();
        void ItemUsrSelection();


    private:
        string Name;
        Item * headItems;
        Item * headScrolls;

};

#endif // CHARACTER_H
