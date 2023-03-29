#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "Biology.h"
#include "Race.h"
#include "Profession.h"
#include "Character.h"

using namespace std;

int main()
{
    Character * newGuy=NULL;
    Biology * head=NULL;
    Biology * curr=NULL;
    Biology * curr2=NULL;
    for(int i=1;i<6;i++){
    cout<<"PLAYER "<<i<<" ";
    newGuy = new Character;
    if(head==NULL){head=(Biology*)newGuy;}
    else{
        curr=head;
        while(curr->GetNext()!=NULL){curr=curr->GetNext();}
        curr2=(Biology*)newGuy;
        curr->SetNext(curr2);
    }
    curr=NULL;
    curr2=NULL;
    newGuy=NULL;
    cout<<endl<<endl;
    }

    Character * curr3;
    curr3=(Character*)head;
    while(curr3!=NULL){
        curr3->Display();
        cout<<endl<<endl;
        curr=(Biology*)curr3;
        curr=curr->GetNext();
        curr3=(Character*)curr;
    }


    return 0;
}
