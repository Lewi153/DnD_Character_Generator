#ifndef RACE_H
#define RACE_H
#include <iostream>
#include "Biology.h"
using namespace std;

class Race : public Biology
{
    public:
        Race();
        virtual ~Race();

        void Display(){cout<<"Race: "<<R<<endl;}
        void RaceGenerator();
        void RaceUsrSelection();
        void RaceAbilityAssgn();


    protected:
        bool Human;
        bool Elf;
        bool Dwarf;
        bool Hobbit;
        bool HalfElf;
        bool HalfOrc;
        string R;
        int Rtype;
};

#endif // RACE_H
