#include<bits/stdc++.h>
using namespace std;
bool comp(string s,string b)
{
    return s>b;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<s.length()<<endl;
    int a=s.length();
    sort(s.begin(),s.end(),comp);
    cout<<s<<endl;
    char b[]="asasccsv";
    sort(b,b+strlen(b));
    cout<<b;

    return 0;
}
