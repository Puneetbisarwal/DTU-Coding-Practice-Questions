#include<bits/stdc++.h>
using namespace std;
int a;
void change()
{
    a=20;
}
void ch()
{
    int static s=1;
    cout<<s<<endl;
    s++;
}
int main()
{
    a=10;
    cout<<a<<endl;
    change();
    cout<<a<<endl;
    ch();
    ch();
    ch();
    ch();
    return 0;

}


