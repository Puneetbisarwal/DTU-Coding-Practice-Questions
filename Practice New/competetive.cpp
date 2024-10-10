#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    s.insert(20);
    s.insert(15);
    s.insert(10);
    s.insert(12);
    s.insert(17);
    set<int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
