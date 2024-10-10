#include<bits/stdc++.h>
using namespace std;
int maxcoin(int *a,int si,int ei,int os,int es)
{
    if(si>ei)
    {
        return 0;
    }
    int sum1=0,sum2=0;
    if(os>es)
    {
        sum1=(int a*,si+1,ei,os-a[si],es);
    }
    else
    {

    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int os=0,es=0;
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0,k=1;i<n,k<n;i=i+2,k=k+2)
    {
        os=os+a[k];
        es=es+a[i];
    }
    cout<<maxcoin(a,0,n-1,os,es);
    return 0;
}
