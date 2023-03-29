#include "Item.h"
using namespace std;
Item::Item()
{
    code='0';
    version=0;
    next=NULL;
}

Item::~Item()
{
    cout<<"Item Removed From List"<<endl;
}
