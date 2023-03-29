#include "Race.h"
#include "Biology.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Race::Race()
{
    int r;
    cout<<"Race Assignment: [1]=Auto [2]=Manual:  ";
    cin>>r;
    while(r>2 || r==0){
        cout<<endl<<"["<<r<<"] is Invalid: Select Again";
        cin>>r;}
    cout<<endl;
    switch(r){
    case 1:{RaceGenerator();}break;
    case 2:{RaceUsrSelection();}break;
    }
    cout<<endl;
    RaceAbilityAssgn();

}

Race::~Race()
{
    cout<<"Race Removed"<<endl;
}



void Race::RaceGenerator(){
    int result;
    default_random_engine gptr(time(NULL));
    uniform_int_distribution<int>ddist(1,6);

    for(int i=0;i<21;i++){ //If left as single 'roll', number is always the same
    result=ddist(gptr);}

    switch (result){
    case 1:{Human==true;
            R="Human";
            Rtype=0;
            cout<<"Result: Human"<<endl;}break;
    case 2:{Elf=true;
            R="Elf";
            Rtype=1;
            cout<<"Result: Elf"<<endl;}break;
    case 3:{Dwarf==true;
            R="Dwarf";
            Rtype=2;
            cout<<"Result: Dwarf"<<endl;}break;
    case 4:{Hobbit==true;
            R="Hobbit";
            Rtype=3;
            cout<<"Result: Hobbit"<<endl;}break;
    case 5:{HalfElf==true;
            R="HalfElf";
            Rtype=4;
            cout<<"Result: HalfElf"<<endl;}break;
    case 6:{HalfOrc==true;
            R="HalfOrc";
            Rtype=5;
            cout<<"Result: HalfOrc"<<endl;}break;
    }///End Switch
}


void Race::RaceUsrSelection(){
    int select;
    cout<<"Select Race with Desired Attributes From List by Entering [#]:"<<endl<<endl;
    cout<<"[0] Human   :  +1 of Choice, +1 of Choice"<<endl;
    cout<<"[1] Elf     :  +2 Dexterity, +1 Constitution, -1 Strength"<<endl;
    cout<<"[2] Dwarf   :  +1 Strength,  +1 Constitution"<<endl;
    cout<<"[3] Hobbit  :  +1 Dexterity, +1 Charisma"<<endl;
    cout<<"[4] HalfElf :  +1 Strength,  +1 Dexterity"<<endl;
    cout<<"[5] HalfOrc :  +4 Strength,  -1 Charisma, -1 Intelligence"<<endl<<endl;
    cout<<"Race?  ";
    cin>>select;
    while(select>5){
        cout<<endl<<"["<<select<<"] is Invalid:  Race?  ";
        cin>>select;
    }
    switch (select){
    case 0:{Human==true;
            R="Human";
            Rtype=0;
            cout<<"Chosen Race: Human"<<endl;}break;
    case 1:{Elf==true;
            R="Elf";
            Rtype=1;
            cout<<"Chosen Race: Elf"<<endl;}break;
    case 2:{Dwarf==true;
            R="Dwarf";
            Rtype=2;
            cout<<"Chosen Race: Dwarf"<<endl;}break;
    case 3:{Hobbit==true;
            R="Hobbit";
            Rtype=3;
            cout<<"Chosen Race: Hobbit"<<endl;}break;
    case 4:{HalfElf==true;
            R="HalfElf";
            Rtype=4;
            cout<<"Chosen Race: HalfElf"<<endl;}break;
    case 5:{HalfOrc==true;
            R="HalfOrc";
            Rtype=5;
            cout<<"Chosen Race: HalfOrc"<<endl;}break;
    }
}



void Race::RaceAbilityAssgn(){

    switch(Rtype){
        case 0:{
            default_random_engine gptr(time(NULL));
            uniform_int_distribution<int>ddist(1,6);
            int select;
            int result1;
            int result2;
            cout<<"+2 Human Attribute Points Assignment: [1]=Auto [2]=Manual  ";
            cin>>select;
            cout<<endl;
            if(select==1){
            for(int i=0;i<6;i++){ //If left as single 'roll', number is always the same
                result1=ddist(gptr);}
            switch(result1){
                case 0:{Strength=Strength+1;}break;
                case 1:{Dexterity=Dexterity+1;}break;
                case 2:{Intelligence=Intelligence+1;}break;
                case 3:{Wisdom=Wisdom+1;}break;
                case 4:{Charisma=Charisma+1;}break;
                case 5:{Constitution=Constitution+1;}break;
                }
            for(int i=0;i<6;i++){ //If left as single 'roll', number is always the same
                result2=ddist(gptr);}
            switch(result2){
                case 0:{Strength=Strength+1;}break;
                case 1:{Dexterity=Dexterity+1;}break;
                case 2:{Intelligence=Intelligence+1;}break;
                case 3:{Wisdom=Wisdom+1;}break;
                case 4:{Charisma=Charisma+1;}break;
                case 5:{Constitution=Constitution+1;}break;
                }
            }
            else if (select==2){
                int choice1;
                int choice2;
                cout<<"+1: Select First Ability by Entering [#]"<<endl;
                cout<<"[0]: Strength"<<endl;
                cout<<"[1]: Dexterity"<<endl;
                cout<<"[2]: Intelligence"<<endl;
                cout<<"[3]: Wisdom"<<endl;
                cout<<"[4]: Charisma"<<endl;
                cout<<"[5]: Constitution"<<endl<<endl;
                cout<<"Selection:  ";
                cin>>choice1;
                while(choice1>5){
                    cout<<endl<<"["<<choice1<<"] is Invalid:  Ability?  ";
                    cin>>select;
                }
                cout<<endl;
                switch(choice1){
                    case 0:{Strength=Strength+1;}break;
                    case 1:{Dexterity=Dexterity+1;}break;
                    case 2:{Intelligence=Intelligence+1;}break;
                    case 3:{Wisdom=Wisdom+1;}break;
                    case 4:{Charisma=Charisma+1;}break;
                    case 5:{Constitution=Constitution+1;}break;
                }
                cout<<"+1: Select Second Ability by Entering [#]"<<endl;
                cout<<"[0]: Strength"<<endl;
                cout<<"[1]: Dexterity"<<endl;
                cout<<"[2]: Intelligence"<<endl;
                cout<<"[3]: Wisdom"<<endl;
                cout<<"[4]: Charisma"<<endl;
                cout<<"[5]: Constitution"<<endl<<endl;
                cout<<"Selection:  ";
                cin>>choice2;
                while(choice1>5){
                    cout<<endl<<"["<<choice1<<"] is Invalid:  Ability?  ";
                    cin>>select;
                }
                cout<<endl;
                switch(choice2){
                    case 0:{Strength=Strength+1;}break;
                    case 1:{Dexterity=Dexterity+1;}break;
                    case 2:{Intelligence=Intelligence+1;}break;
                    case 3:{Wisdom=Wisdom+1;}break;
                    case 4:{Charisma=Charisma+1;}break;
                    case 5:{Constitution=Constitution+1;}break;
                }
            }
            else{cout<<"Invalid."<<endl;}
            }break;

        case 1:{
            Dexterity=Dexterity+2;
            Constitution=Constitution+1;
            Strength=Strength-1;
            }break;
        case 2:{
            Strength=Strength+1;
            Constitution=Constitution+1;
            }break;
        case 3:{
            Dexterity=Dexterity+1;
            Charisma=Charisma+1;
            }break;
        case 4:{
            Strength=Strength+1;
            Dexterity=Dexterity+1;
            }break;
        case 5:{
            Strength=Strength+4;
            Charisma=Charisma-1;
            Intelligence=Intelligence-1;
            }break;
        default:{cout<<"Error Updating Abilities from Race (string)"<<endl;}
    }///End Switch






}
