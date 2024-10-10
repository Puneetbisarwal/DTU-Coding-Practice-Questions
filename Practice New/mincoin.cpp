#include<bits/stdc++.h>
using namespace std;
int mincoinM(int *a,int n,int *out,int val)
{
    if(val==0)
    {
        return 0;
    }
    if(out[val]!=-1)
    {
        return out[val];
    }
    int ans=INT_MAX,temp;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=val)
        {
            temp=mincoinM(a,n,out,val-a[i]);
            {
                if(temp!=INT_MAX && temp+1<ans)
                {
                    ans=temp;
                }
            }
            out[val]=ans;
        }
    }
    return out[val];
}
int mincoinM(int *a ,int n,int val)
{
    int out[val+1];
    for(int i=0;i<=val;i++)
    {
        out[i]=-1;
    }
    return mincoinM(a,n,out,val);
}
int mincoin(int *a,int n ,int val)
{
    if(val==0)
    {
        return 0;
    }
    int ans=INT_MAX,temp;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=val)
        {
            temp=mincoin(a,n,val-a[i]);
            if(temp!=INT_MAX && temp+1<ans)
            {
                ans=temp+1;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[]={9,6,5,2};
    cout<<mincoin(a,4,30)<<endl;
    cout<<mincoinM(a,4,30)<<endl;
    return 0;
}
