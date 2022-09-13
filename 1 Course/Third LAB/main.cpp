#include <iostream>
#include "MyString.h"
using namespace std;
int main() {
    MyString ctroka("Hello world.I`m a live.");
    MyString finders("Hello world ");
    MyString world("world");
    MyString space(" ");
    MyString local;
    int size = 0;
    char *p, *q = 0;
    int *y;
    cout<<ctroka<<endl;;
    cout<<ctroka.GetLen()<<endl;
    cout<<ctroka.GetChar(6)<<endl;
    cout<<ctroka.Find('.')<<endl;
    cout<<ctroka.Find(world)<<endl;
    cout<<ctroka<<endl;
    cout<<ctroka[3]<<endl;
    cout<<finders<<endl;
    cin>>local;
    cout<<local<<endl;
}