#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int i=7,j;
    for(int i=7;i>0;i--)
    {
        j=rand()%(i+1);
        cout<<"i ="<<i<<" , "<<"j"<<" = "<<j<<endl;
    }
    string s[3];
    s[0]="";
    s[1]="abc";
    s[2]="abcde";
    for(int i=0;i<3;i++)
    {
        cout<<s[i].length()<<endl;
    }
    map<int,char> m;
    int o=65;
    for(int i=1;i<=26;i++)
    {
        m[i]=o;
        o++;
    }
    for(int i=1;i<=26;i++)
    {
        cout<<m[i]<<" ";
    }
    return 0;
}
