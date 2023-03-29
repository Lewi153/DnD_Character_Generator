#include "Profession.h"
#include "Biology.h"
#include "Race.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Profession::Profession()
{
    int p;
    cout<<"Profession Assignment: [1]=Auto [2]=Manual:  ";
    cin>>p;
    while(p>2 || p==0){
        cout<<endl<<"["<<p<<"] is Invalid: Select Again";
        cin>>p;}
    cout<<endl;
    switch(p){
    case 1:{ProfessionGenerator();}break;
    case 2:{ProfessionUsrSelection();}break;
    }
    cout<<endl;
}

Profession::~Profession()
{
    cout<<"Profession Removed"<<endl;
}


//ASK ABOUT PROFESSION RESTRICTIONS: Seems like too many possible combinations of >12   ...?
void Profession::ProfessionGenerator(){
int str = Biology::GetStrength();
int dex = Biology::GetDexterity();
int in = Biology::GetIntelligence();
int wis = Biology::GetWisdom();
default_random_engine gptr(time(NULL));
uniform_int_distribution<int>ddist(1,4);
int result;
//If all checked abilities are >12: Random pick of one                      Else: whichever >12 comes first will be chosen (with a factor of randomness)
if(str>12 && dex>12 && in>12 && wis>12){  //All Above 12
    for(int i=0;i<21;i++){ //If left as single 'roll', number is always the same
        result=ddist(gptr);}
    switch (result){
    case 1:{P="Warrior";
            Ptype=0;
            cout<<"Result: Warrior"<<endl;}break;
    case 2:{P="Thief";
            Ptype=1;
            cout<<"Result: Thief"<<endl;
            }break;
    case 3:{P="Magic User";
            Ptype=2;
            cout<<"Result: Magic User"<<endl;
            }break;
    case 4:{P="Cleric";
            Ptype=3;
            cout<<"Result: Cleric"<<endl;
            }break;
    }
}

else{
// ///////////////////THIS PART SIMPLY ADDS A FACTOR OF RANDOMNESS//////////////////
//Generate a random number here to select which ordered conditionals of >12 abilities will be looked at:   Whichever >12==true is found first down the case, will be selected
result=ddist(gptr);
switch (result){
case 1:{
    if(str>12){
        P="Warrior";
        Ptype=0;
        cout<<"Result: Warrior"<<endl;}
    else if(dex>12){
        P="Thief";
        Ptype=1;
        cout<<"Result: Thief"<<endl;}
    else if(in>12){
        P="Magic User";
        Ptype=2;
        cout<<"Result: Magic User"<<endl;}
    else if(wis>12){
        P="Cleric";
        Ptype=3;
        cout<<"Result: Cleric"<<endl;}
    else{cout<<"Issue Assigning a Profession"<<endl;}
}break;

case 2:{
    if(dex>12){
        P="Thief";
        Ptype=1;
        cout<<"Result: Thief"<<endl;}
    else if(in>12){
        P="Magic User";
        Ptype=2;
        cout<<"Result: Magic User"<<endl;}
    else if(wis>12){
        P="Cleric";
        Ptype=3;
        cout<<"Result: Cleric"<<endl;}
    else if(str>12){
        P="Warrior";
        Ptype=0;
        cout<<"Result: Warrior"<<endl;}
    else{cout<<"Issue Assigning a Profession"<<endl;}
}break;

case 3:{
    if(in>12){
        P="Magic User";
        Ptype=2;
        cout<<"Result: Magic User"<<endl;}
    else if(wis>12){
        P="Cleric";
        Ptype=3;
        cout<<"Result: Cleric"<<endl;}
    else if(str>12){
        P="Warrior";
        Ptype=0;
        cout<<"Result: Warrior"<<endl;}
    else if(dex>12){
        P="Thief";
        Ptype=1;
        cout<<"Result: Thief"<<endl;}
    else{cout<<"Issue Assigning a Profession"<<endl;}
}break;

case 4:{
    if(wis>12){
        P="Cleric";
        Ptype=3;
        cout<<"Result: Cleric"<<endl;}
    else if(str>12){
        P="Warrior";
        Ptype=0;
        cout<<"Result: Warrior"<<endl;}
    else if(dex>12){
        P="Thief";
        Ptype=1;
        cout<<"Result: Thief"<<endl;}
    else if(in>12){
        P="Magic User";
        Ptype=2;
        cout<<"Result: Magic User"<<endl;}
    else{cout<<"Issue Assigning a Profession"<<endl;}
}break;
}}

}//END FUNCTION


void Profession::ProfessionUsrSelection(){
    Ptype=4;
    int select;
    while(Ptype>3){
    cout<<"Select a Profession from the Following List by Entering [#]: *Ability Restrictions >12 Apply*"<<endl;
    cout<<"[0] Warrior"<<endl;
    cout<<"[1] Thief"<<endl;
    cout<<"[2] Magic User"<<endl;
    cout<<"[3] Cleric"<<endl;
    cout<<"Profession?  ";
    cin>>select;
    while(select>3){
        cout<<endl<<"["<<select<<"] is Invalid:  Profession?  ";
        cin>>select;
    }
    cout<<endl;
    switch (select){
        case 0:{int s=Biology::GetStrength();
        if (s>12){
            P="Warrior";
            Ptype=0;
            cout<<"Chosen Profession: Warrior"<<endl;}
        else{cout<<"Invalid: Character Strength not >12, Select Again."<<endl<<endl;}
        }break;

        case 1:{int d=Biology::GetDexterity();
        if (d>12){
            P="Thief";
            Ptype=1;
            cout<<"Chosen Profession: Thief"<<endl;}
        else{cout<<"Invalid: Character Dexterity not >12, Select Again."<<endl<<endl;}
        }break;

        case 2:{int i=Biology::GetIntelligence();
        if (i>12){
            P="Magic User";
            Ptype=2;
            cout<<"Chosen Profession: Magic User"<<endl;}
        else{cout<<"Invalid: Character Intelligence not >12, Select Again."<<endl<<endl;}
        }break;

        case 3:{int w=Biology::GetWisdom();
        if (w>12){
            P="Cleric";
            Ptype=3;
            cout<<"Chosen Profession: Cleric"<<endl;}
        else{cout<<"Invalid: Character Wisdom not >12, Select Again."<<endl<<endl;}
        }break;
    }///End Switch
    }///End While Ptype>3




}
