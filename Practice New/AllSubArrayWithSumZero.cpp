#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    unordered_map<int,vector<int>> m;
    vector<pair<int,int>> out;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum==0)
        {
            out.push_back(make_pair(0,i));
        }
        if(m.find(sum)!=m.end())
        {
            vector<int> t=m[sum];
            for(auto it=t.begin();it!=t.end();it++)
            {
                out.push_back(make_pair(*it+1,i));
            }
        }
        m[sum].push_back(i);
    }
    for(auto it=out.begin();it!=out.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
