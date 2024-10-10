#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> a;
    vector<int> b;
    int e;
    cin>>e;
    for(int i=0;i<e;i++){int o;
    cin>>o;
    a.push_back(o);}
    for(int i=0;i<e;i++){int h;
    cin>>h;
    b.push_back(h);}
    int c=0;
    while(c<e)
    {
        q.push(a[c]*a[c] + b[c]*b[c]);
        c++;
    }
    int k;
    cin>>k;
    int t=0;
    while(t<k && !q.empty())
    {
        int r=q.top();
        cout<<r<<endl;
        t++;
        q.pop();
    }
    return 0;
}
