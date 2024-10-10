#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    int max1=0;
    for(int i=0;i<n;i++){max1=max(max1,a[i]);}
    int fr[max1+1]={0};
    for(int i=0;i<n;i++){fr[a[i]]++;}
    int ans=0;
    //case 1 0,0,0
    ans=ans+(fr[0]*(fr[0]-1)*(fr[0]-2))/6;
    //case2 0,x,x
    for(int i=1;i<=max1;i++)
    {
        ans=ans+fr[0]*((fr[i]*(fr[i]-1))/2);
    }
    //case3 x,x,2x
    for(int i=1;i<=max1;i++)
    {
        ans=ans+fr[2*i]*((fr[i]*(fr[i]-1))/2);
    }
    //case4 x,y,x+y
    for(int i=1;i<=max1;i++)
    {
        for(int j=i+1;i+j<=max1;j++)
        {
            ans=ans+fr[i]*fr[j]*fr[i+j];
        }
    }
    cout<<ans;
    return 0;
}
