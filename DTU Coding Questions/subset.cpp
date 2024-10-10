#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void pri(int *a,int n,int i,int &m)
{
    int j=0,ans=0;
    while(i>0)
    {
        if(i&1)
        {
            ans=ans^a[j];
        }
        j++;
        i=i>>1;
    }
    if(ans>m)
    {
        m=ans;
    }
}
int pr(int *a,int n)
{
    int ans=INT_MIN;
    for(int i=0;i<(1<<n);i++)
    {
        pri(a,n,i,ans);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    cout<<pr(a,n);

return 0;
}
