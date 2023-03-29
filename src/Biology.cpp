#include "Biology.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

Biology::Biology()
{
    cout<<"Enter Character Name:  ";
    cin>>name;
    cout<<endl;

    int a;
    cout<<"Ability Score Assignment: [1]=Auto [2]=Manual:  ";
    cin>>a;
    while(a>2 || a==0){
        cout<<endl<<"["<<a<<"] is Invalid: Select Again";
        cin>>a;}
    cout<<endl;
    switch(a) {
        case 1:{Biology::AbilityGenerator(Strength, Dexterity, Intelligence, Wisdom, Charisma, Constitution);}break;
        case 2:{Biology::AbilityUsrSelection();}break;
    }
    next=NULL;
}



Biology::~Biology()
{
cout<<"Biology Removed";
}


//Display Function
void Biology::Display(){
cout<<"Strength: "<<Strength<<endl;
cout<<"Dexterity: "<<Dexterity<<endl;
cout<<"Intelligence: "<<Intelligence<<endl;
cout<<"Wisdom: "<<Wisdom<<endl;
cout<<"Charisma: "<<Charisma<<endl;
cout<<"Constitution: "<<Constitution<<endl;
}

//Auto - Random Ability Scores Function
void Biology::AbilityGenerator(int&S, int&D, int&I, int&W, int&Ch, int&Co){
    default_random_engine gptr(time(NULL));
    uniform_int_distribution<int> ddist(1,6);

    int ability[6];
    int dice[4];
    int sum=0;
    int minval=100;
    int lowestRoll;

    for(int j=0;j<6;j++){
        for (int i=0;i<4;i++){
            dice[i]=ddist(gptr);
            if (dice[i]<minval){
                minval=dice[i];
                lowestRoll=i;
            }
        }
        dice[lowestRoll]=0;
        for (int k=0;k<4;k++){
            sum=sum+dice[k];
            }
        ability[j]=sum;
        sum=0;
        minval=100;
    }
    S=ability[0];
    D=ability[1];
    I=ability[2];
    W=ability[3];
    Ch=ability[4];
    Co=ability[5];
    cout<<"**Raw Ability Scores**"<<endl;
    cout<<"Strength: "<<S<<endl;
    cout<<"Dexterity: "<<D<<endl;
    cout<<"Intelligence: "<<I<<endl;
    cout<<"Wisdom: "<<W<<endl;
    cout<<"Charisma: "<<Ch<<endl;
    cout<<"Constitution: "<<Co<<endl<<endl;
}

//User Selected - Random Ability Scores Function
void Biology::AbilityUsrSelection(){
    default_random_engine gptr(time(NULL));
    uniform_int_distribution<int> ddist(1,6);
    int ability[6];
    int select;
    int dice[4];
    int sum=0;
    int minval=100;
    int lowestRoll;

    for(int j=0;j<6;j++){
        for (int i=0;i<4;i++){
            dice[i]=ddist(gptr);
            if (dice[i]<minval){
                minval=dice[i];
                lowestRoll=i;
            }
        }
        dice[lowestRoll]=0;
        for (int k=0;k<4;k++){
            sum=sum+dice[k];
            }
        ability[j]=sum;
        sum=0;
        minval=100;
    }

    cout<<"--Select a Non-Zero Score From the Following List by Entering [#]--"<<endl<<endl;

    //Strength
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Strength?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Strength?  ";
        cin>>select;
    }
    cout<<endl;
    Strength = ability[select];
    ability[select]=0;

    //Dexterity
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Dexterity?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Dexterity?  ";
        cin>>select;
    }
    cout<<endl;
    Dexterity = ability[select];
    ability[select]=0;

    //Intelligence
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Intelligence?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Intelligence?  ";
        cin>>select;
    }
    cout<<endl;
    Intelligence = ability[select];
    ability[select]=0;

    //Wisdom
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Wisdom?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Wisdom?  ";
        cin>>select;
    }
    cout<<endl;
    Wisdom = ability[select];
    ability[select]=0;

    //Charisma
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Charisma?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Charisma?  ";
        cin>>select;
    }
    cout<<endl;
    Charisma = ability[select];
    ability[select]=0;

    //Constitution
    cout<<"Available Scores: "<<endl;
    for(int i=0;i<6;i++){
        cout<<"["<<i<<"]: "<<ability[i]<<endl;
    }
    cout<<endl<<"Constitution?  ";
    cin>>select;
    while(select>5 || ability[select]==0){
        cout<<endl<<"["<<select<<"] is Invalid:  Constitution?  ";
        cin>>select;
    }
    cout<<endl;
    Constitution = ability[select];
    ability[select]=0;

}
