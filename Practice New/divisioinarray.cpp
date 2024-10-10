#include<bits/stdc++.h>
using namespace std;
#define l 100005
int main()
{
    int n;
    cin>>n;
    int a[l],freq[l];
    freq[0]=1;
    memset(freq,0,sizeof(freq));
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        sum=sum%n;
        sum=(sum+n)%n;
        freq[sum]++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int m=freq[i];
        ans+=m*(m-1)/2;
    }
    cout<<ans;
}
