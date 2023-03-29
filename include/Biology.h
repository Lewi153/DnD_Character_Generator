#ifndef BIOLOGY_H
#define BIOLOGY_H
#include <iostream>
#include <string>
using namespace std;

class Biology
{
    public:
        Biology();
        virtual ~Biology();

        int GetStrength(){return Strength;}
        int GetDexterity(){return Dexterity;}
        int GetIntelligence(){return Intelligence;}
        int GetWisdom(){return Wisdom;}
        int GetCharisma(){return Charisma;}
        int GetConstitution(){return Constitution;}
        string GetName(){return name;}
        Biology * GetNext(){return next;}

        void Display();
        void AbilityGenerator(int&S, int&D, int&I, int&W, int&Ch, int&Co);
        void AbilityUsrSelection();
        void SetNext(Biology * ptr){next=ptr;};


    protected:
        int Strength;
        int Dexterity;
        int Intelligence;
        int Wisdom;
        int Charisma;
        int Constitution;
        string name;
        Biology * next;

};

#endif // BIOLOGY_H
