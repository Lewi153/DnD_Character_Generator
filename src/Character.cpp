#include "Character.h"
#include "Biology.h"
#include "Race.h"
#include "Profession.h"
#include "Item.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Character::Character()
{
    Name=Biology::GetName();
    headItems=NULL;
    headScrolls=NULL;
    int select;
    cout<<"Item Assignment: [1]=Auto [2]=Manual:  ";
    cin>>select;
    while(select>2 || select==0){
        cout<<endl<<"["<<select<<"] is Invalid: Select Again";
        cin>>select;}
    cout<<endl;
    switch(select){
    case 1:{ItemGenerator();}break;         //Add Items - Auto version
    case 2:{ItemUsrSelection();}break;      //Add Items - Manual version
    }
}



Character::~Character()
{
   cout<<"Character Removed"<<endl;
}



void Character::Display(){
    cout<<"Character ["<<Name<<"] Attributes: "<<endl;
    Profession::Display();
    Race::Display();
    Biology::Display();
    cout<<"Items: ";
    Item * curr;
    curr=headItems;
    while(curr!=NULL){
        char c = curr->GetCode();
        int i = curr->GetVersion();
        cout<<c<<i<<" ";
        curr=curr->GetNext();}
    cout<<endl;
    if(headScrolls==NULL){cout<<"No Spell-Scrolls Allowed for this Profession"<<endl;}
    else{
    cout<<"Number of Spell-Scrolls: ";
    int num=0;
    curr=headScrolls;
    while(curr!=NULL){
        num++;
        curr=curr->GetNext();}
    cout<<num<<endl;
    }


    }


















//Auto items
void Character::ItemGenerator(){
    int p=Profession::GetPtype(); //0=Warrior,1=Thief,2=Magic User, 3=Cleric
    int select1, select2, select3;
    Item * curr;
    Item * newItem;
    if(p==0){ //Warrior
        default_random_engine gptr(time(NULL));
        uniform_int_distribution<int>wdist(0,7);
        uniform_int_distribution<int>adist(0,4);
        uniform_int_distribution<int>odist(0,3);
        uniform_int_distribution<int>onumdist(8,12);
        int result;
        int numItems;
        //Weapon Generator
        for(int i=0;i<10;i++){
            result=wdist(gptr);}
        newItem=new Item;
        newItem->SetCode('W');
        newItem->SetVersion(result);
        headItems=newItem;
        newItem=NULL;
        //Armor Generator
        for(int i=0;i<10;i++){
            result=adist(gptr);}
        newItem=new Item;
        newItem->SetCode('A');
        newItem->SetVersion(result);
        headItems->SetNext(newItem);
        newItem=NULL;
        //Other Generator
        for(int i=0;i<10;i++){
            numItems=onumdist(gptr);}
        for(int j=0;j<numItems;j++){
            for(int k=0;k<10;k++){
                result=odist(gptr);}
            newItem=new Item;
            newItem->SetCode('E');
            newItem->SetVersion(result);
            curr=headItems;
            while(curr->GetNext()!=NULL){curr=curr->GetNext();}
            curr->SetNext(newItem);
            curr=NULL;
            newItem=NULL;
        }
    }
    else if(p==1){ //Thief
        default_random_engine gptr(time(NULL));
        uniform_int_distribution<int>wdist(1,2);
        uniform_int_distribution<int>adist(0,1);
        uniform_int_distribution<int>odist(0,3);
        uniform_int_distribution<int>onumdist(8,12);
        int result;
        int numItems;
        //Weapon Generator
        for(int i=0;i<10;i++){
            result=wdist(gptr);}
        newItem=new Item;
        newItem->SetCode('W');
        newItem->SetVersion(result);
        headItems=newItem;
        newItem=NULL;
        //Armor Generator
        for(int i=0;i<10;i++){
            result=adist(gptr);}
        newItem=new Item;
        newItem->SetCode('A');
        newItem->SetVersion(result);
        headItems->SetNext(newItem);
        newItem=NULL;
        //Other Generator
        for(int i=0;i<10;i++){
            numItems=onumdist(gptr);}
        for(int j=0;j<numItems;j++){
            for(int k=0;k<10;k++){
                result=odist(gptr);}
            newItem=new Item;
            newItem->SetCode('E');
            newItem->SetVersion(result);
            curr=headItems;
            while(curr->GetNext()!=NULL){curr=curr->GetNext();}
            curr->SetNext(newItem);
            curr=NULL;
            newItem=NULL;
        }

    }
    else if(p==2){//Magic-User
        default_random_engine gptr(time(NULL));
        uniform_int_distribution<int>wdist(0,1);
        uniform_int_distribution<int>odist(0,3);
        uniform_int_distribution<int>onumdist(8,12);
        int result;
        int numItems;
        int in = Biology::GetIntelligence();
        //Weapon Generator
        for(int i=0;i<10;i++){
            result=wdist(gptr);}
        newItem=new Item;
        newItem->SetCode('W');
        newItem->SetVersion(result);
        headItems=newItem;
        newItem=NULL;
        //Armor Generator
        newItem=new Item;
        newItem->SetCode('A');
        newItem->SetVersion(0);
        headItems->SetNext(newItem);
        newItem=NULL;
        //Other Generator
        for(int i=0;i<10;i++){
            numItems=onumdist(gptr);}
        for(int j=0;j<numItems;j++){
            for(int k=0;k<10;k++){
                result=odist(gptr);}
            newItem=new Item;
            newItem->SetCode('E');
            newItem->SetVersion(result);
            curr=headItems;
            while(curr->GetNext()!=NULL){curr=curr->GetNext();}
            curr->SetNext(newItem);
            curr=NULL;
            newItem=NULL;
        }
        if (in>15){
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls=newItem;
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls->SetNext(newItem);
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            curr=headScrolls->GetNext();
            curr->SetNext(newItem);
        }
        else if(in>12){
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls=newItem;
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls->SetNext(newItem);
        }
        else{cout<<"Issue Determining Number of Scrolls"<<endl;}

    }

    else if(p==3){ //Cleric
        default_random_engine gptr(time(NULL));
        uniform_int_distribution<int>wdist(0,3);
        uniform_int_distribution<int>adist(0,2);
        uniform_int_distribution<int>odist(0,3);
        uniform_int_distribution<int>onumdist(8,12);
        int result;
        int numItems;
        int wis = Biology::GetWisdom();
        //Weapon Generator
        for(int i=0;i<10;i++){
            result=wdist(gptr);}
        newItem=new Item;
        newItem->SetCode('W');
        switch(result){
        case 0:{
        newItem->SetVersion(0);
        headItems=newItem;
        newItem=NULL;
        }break;
        case 1:{
        newItem->SetVersion(5);
        headItems=newItem;
        newItem=NULL;
        }break;
        case 2:{
        newItem->SetVersion(6);
        headItems=newItem;
        newItem=NULL;
        }break;
        case 3:{
        newItem->SetVersion(7);
        headItems=newItem;
        newItem=NULL;
        }break;
        }
        //Armor Generator
        for(int i=0;i<10;i++){
            result=adist(gptr);}
        newItem=new Item;
        newItem->SetCode('A');
        newItem->SetVersion(result);
        headItems->SetNext(newItem);
        newItem=NULL;
        //Other Generator
        for(int i=0;i<10;i++){
            numItems=onumdist(gptr);}
        for(int j=0;j<numItems;j++){
            for(int k=0;k<10;k++){
                result=odist(gptr);}
            newItem=new Item;
            newItem->SetCode('E');
            newItem->SetVersion(result);
            curr=headItems;
            while(curr->GetNext()!=NULL){curr=curr->GetNext();}
            curr->SetNext(newItem);
            curr=NULL;
            newItem=NULL;
        }

        if (wis>15){
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls=newItem;
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls->SetNext(newItem);
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            curr=headScrolls->GetNext();
            curr->SetNext(newItem);
        }
        else if(wis>12){
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls=newItem;
            newItem=NULL;
            newItem = new Item;
            newItem->SetCode('E');
            newItem->SetVersion(4);
            headScrolls->SetNext(newItem);
        }
        else{cout<<"Issue Determining Number of Scrolls"<<endl;}

    }

    else{cout<<"Issue Determining Profession (For Item Selection)"<<endl;}


}


















//Manual items
    void Character::ItemUsrSelection(){
    int p=Profession::GetPtype(); //0=Warrior,1=Thief,2=Magic User, 3=Cleric
    int select1, select2, select3;
    int numItems;
    Item * curr;
    Item * newItem;
    default_random_engine gptr(time(NULL));
    uniform_int_distribution<int>onumdist(8,12);
    for(int i=0;i<10;i++){
        numItems=onumdist(gptr);}
if(p==0){ //Warrior
    cout<<"[Warrior] Choose One Weapon from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Staff"<<endl;
    cout<<"[1] Dagger"<<endl;
    cout<<"[2] Short Sword"<<endl;
    cout<<"[3] Long Sword"<<endl;
    cout<<"[4] Axe"<<endl;
    cout<<"[5] Mace"<<endl;
    cout<<"[6] Spear"<<endl;
    cout<<"[7] Bow"<<endl;
    cout<<"Choice?  ";
    cin>>select1;
    while (select1>7){
    cout<<"Invalid Selection of ["<<select1<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select1){
    case 0:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(0);
        headItems=curr;
    }break;
    case 1:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(1);
        headItems=curr;
    }break;
    case 2:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(2);
        headItems=curr;
    }break;
    case 3:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(3);
        headItems=curr;
    }break;
    case 4:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(4);
        headItems=curr;
    }break;
    case 5:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(5);
        headItems=curr;
    }break;
    case 6:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(6);
        headItems=curr;
    }break;
    case 7:{
        curr=new Item;
        curr->SetCode('W');
        curr->SetVersion(7);
        headItems=curr;
    }break;
    }//End Switch

    cout<<"[Warrior] Choose One Armor from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Robe"<<endl;
    cout<<"[1] Leather Armor"<<endl;
    cout<<"[2] Chain Mail"<<endl;
    cout<<"[3] Plate Mail"<<endl;
    cout<<"[4] Shield"<<endl;
    cout<<"Choice?  ";
    cin>>select2;
    while (select2>4){
    cout<<"Invalid Selection of ["<<select2<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select2){
    case 0:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(0);
        headItems->SetNext(curr);
    }break;
    case 1:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(1);
        headItems->SetNext(curr);
    }break;
    case 2:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(2);
        headItems->SetNext(curr);
    }break;
    case 3:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(3);
        headItems->SetNext(curr);
    }break;
    case 4:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(4);
        headItems->SetNext(curr);
    }break;
    }

    cout<<"You have been granted ["<<numItems<<"] Additional Items."<<endl;
    for (int j=0;j<numItems;j++){
    cout<<"Choose Additional Item to Carry With You by Entering [#]:"<<endl;
    cout<<"[0] Torch"<<endl;
    cout<<"[1] Rope"<<endl;
    cout<<"[2] Food & Wine"<<endl;
    cout<<"Choice?  ";
    cin>>select3;
    while (select3>2){
    cout<<"Invalid Selection of ["<<select3<<"]. Choice?  ";
    cin>>select3;}
    cout<<endl;
    switch(select3){
    case 0:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(0);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 1:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(1);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 2:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(2);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    }}
}//End Warrior




else if(p==1){ //Thief
cout<<"[Thief] Choose One Weapon from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Dagger"<<endl;
    cout<<"[1] Short Sword"<<endl;
    cout<<"Choice?  ";
    cin>>select1;
    while (select1>1){
    cout<<"Invalid Selection of ["<<select1<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select1){
    case 0:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(1);
    }break;
    case 1:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(2);
    }break;
    }//End Switch

    cout<<"[Thief] Choose One Armor from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Robe"<<endl;
    cout<<"[1] Leather Armor"<<endl;
    cout<<"Choice?  ";
    cin>>select2;
    while (select2>1){
    cout<<"Invalid Selection of ["<<select2<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select2){
    case 0:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(0);
        headItems->SetNext(curr);
    }break;
    case 1:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(1);
        headItems->SetNext(curr);
    }break;
    }

    cout<<"You have been granted ["<<numItems<<"] Additional Items."<<endl;
    for (int j=0;j<numItems;j++){
    cout<<"Choose Additional Item to Carry With You by Entering [#]:"<<endl;
    cout<<"[0] Torch"<<endl;
    cout<<"[1] Rope"<<endl;
    cout<<"[2] Food & Wine"<<endl;
    cout<<"Choice?  ";
    cin>>select3;
    while (select3>2){
    cout<<"Invalid Selection of ["<<select3<<"]. Choice?  ";
    cin>>select3;}
    cout<<endl;
    switch(select3){
     case 0:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(0);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 1:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(1);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 2:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(2);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    }}
}//End Thief

else if(p==2){//Magic-User
    int in = Biology::GetIntelligence();
    cout<<"[Magic User] Choose One Weapon from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Staff"<<endl;
    cout<<"[1] Dagger"<<endl;
    cout<<"Choice?  ";
    cin>>select1;
    while (select1>1){
    cout<<"Invalid Selection of ["<<select1<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select1){
    case 0:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(0);
    }break;
    case 1:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(1);
    }break;
    }//End Switch

    cout<<"[Magic User] Choose One Armor from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Robe"<<endl;
    cout<<"Choice?  ";
    cin>>select2;
    while (select2>0){
    cout<<"Invalid Selection of ["<<select2<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select2){
    case 0:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(0);
        headItems->SetNext(curr);
    }break;
    }//End Switch

    cout<<"You have been granted ["<<numItems<<"] Additional Items."<<endl;
    for (int j=0;j<numItems;j++){
    cout<<"Choose Additional Item to Carry With You by Entering [#]:"<<endl;
    cout<<"[0] Torch"<<endl;
    cout<<"[1] Rope"<<endl;
    cout<<"[2] Food & Wine"<<endl;
    cout<<"Choice?  ";
    cin>>select3;
    while (select3>2){
    cout<<"Invalid Selection of ["<<select3<<"]. Choice?  ";
    cin>>select3;}
    cout<<endl;
    switch(select3){
     case 0:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(0);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 1:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(1);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 2:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(2);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    }}

    if (in>15){
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls=newItem;
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls->SetNext(newItem);
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        curr=headScrolls->GetNext();
        curr->SetNext(newItem);
        cout<<"Based on Intelligence, You Have Been Granted 3 Spell-Scrolls"<<endl;
    }
    else if(in>12){
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls=newItem;
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls->SetNext(newItem);
        cout<<"Based on Intelligence, You Have Been Granted 2 Spell-Scrolls"<<endl;
    }
    else{cout<<"Issue Determining Number of Scrolls"<<endl;}

}//End Magic-User


else if(p==3){ //Cleric
    int wis = Biology::GetWisdom();
    cout<<"[Cleric] Choose One Weapon from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Staff"<<endl;
    cout<<"[1] Mace"<<endl;
    cout<<"[2] Spear"<<endl;
    cout<<"[3] Bow"<<endl;
    cout<<"Choice?  ";
    cin>>select1;
    while (select1>3){
    cout<<"Invalid Selection of ["<<select1<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select1){
    case 0:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(0);
    }break;
    case 1:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(5);
    }break;
    case 2:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(6);
    }break;
    case 3:{
        headItems=new Item;
        headItems->SetCode('W');
        headItems->SetVersion(7);
    }break;
    }//End Switch

    cout<<"[Cleric] Choose One Armor from the Following List by Entering [#]:"<<endl;
    cout<<"[0] Robe"<<endl;
    cout<<"[1] Leather Armor"<<endl;
    cout<<"[2] Chain Mail"<<endl;
    cout<<"Choice?  ";
    cin>>select2;
    while (select2>2){
    cout<<"Invalid Selection of ["<<select2<<"]. Choice?  ";
    cin>>select1;}
    cout<<endl;
    switch(select2){
    case 0:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(0);
        headItems->SetNext(curr);
    }break;
    case 1:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(1);
        headItems->SetNext(curr);
    }break;
    case 2:{
        curr=new Item;
        curr->SetCode('A');
        curr->SetVersion(2);
        headItems->SetNext(curr);
    }break;
    }


    cout<<"You have been granted ["<<numItems<<"] Additional Items."<<endl;
    for (int j=0;j<numItems;j++){
    cout<<"Choose Additional Item to Carry With You by Entering [#]:"<<endl;
    cout<<"[0] Torch"<<endl;
    cout<<"[1] Rope"<<endl;
    cout<<"[2] Food & Wine"<<endl;
    cout<<"Choice?  ";
    cin>>select3;
    while (select3>2){
    cout<<"Invalid Selection of ["<<select3<<"]. Choice?  ";
    cin>>select3;}
    cout<<endl;
    switch(select3){
     case 0:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(0);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 1:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(1);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    case 2:{
        newItem=new Item;
        newItem->SetCode('E');
        newItem->SetVersion(2);
        curr=headItems;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr->SetNext(newItem);
        curr=NULL;
        newItem=NULL;
    }break;
    }}

    if (wis>15){
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls=newItem;
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls->SetNext(newItem);
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        curr=headScrolls->GetNext();
        curr->SetNext(newItem);
        cout<<"Based on Wisdom, You Have Been Granted 3 Spell-Scrolls"<<endl;
    }
    else if(wis>12){
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls=newItem;
        newItem=NULL;
        newItem = new Item;
        newItem->SetCode('E');
        newItem->SetVersion(4);
        headScrolls->SetNext(newItem);
        cout<<"Based on Wisdom, You Have Been Granted 2 Spell-Scrolls"<<endl;
    }
    else{cout<<"Issue Determining Number of Scrolls"<<endl;}

}//End Cleric

else{cout<<"Issue Determining Profession (For Item Selection)"<<endl;}

}//End Function
