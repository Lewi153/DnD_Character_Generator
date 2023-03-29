#ifndef PROFESSION_H
#define PROFESSION_H

#include <iostream>
#include "Biology.h"
#include "Race.h"

using namespace std;

class Profession : public Race
{
    public:
        Profession();
        virtual ~Profession();

        void Display(){cout<<"Profession: "<<P<<endl;}

        void ProfessionGenerator();
        void ProfessionUsrSelection();
        int GetPtype(){return Ptype;}

    protected:
        bool Warrior;
        bool MagicUser;
        bool Cleric;
        bool Thief;
        string P;
        int Ptype;
};

#endif // PROFESSION_H
