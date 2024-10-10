#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,vector<int>> m1;
    m1[1].push_back(4);
    m1[1].push_back(3);
    m1[1].push_back(6);
    m1[2].push_back(8);
    m1[2].push_back(9);
    m1[2].push_back(10);
    for(auto it=m1.begin();it!=m1.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<endl;
        }
    }
   // unordered_map<int,int> m;
    /*map<int,int> m;
    m[1]=2;
    m[2]=32;
    m[10]=-100;
    m[187]=56;
    //iterator unordered_map<int,int> :: it;
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first <<" "<<it->second<<" ";
    }*/
    /*vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout<<v.size();*/
    return 0;
}
