#include<bits/stdc++.h>
using namespace std;
int kadanesmin(int *a,int n)
{
    int sum=0,sumsofar=INT_MAX;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum<sumsofar)
        {
            sumsofar=sum;
        }
        if(sum>0)
        {
            sum=0;
        }
    }
    return sumsofar;
}
int kadanesmax(int *a,int n)
{
    int sum=0,sumsofar=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum>sumsofar)
        {
            sumsofar=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return sumsofar;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){cin>>a[i];}
    int maxka=kadanesmax(a,n);
    int minka=kadanesmin(a,n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    if(minka==sum)
    {
        cout<<maxka;
    }
    else if(maxka==sum)
    {
        cout<<maxka;
    }
    else
    {
        cout<<sum-minka;
    }
	return 0;
}
