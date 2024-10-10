#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll printnum1(ll *a,ll n)
{
    ll j=0ll;
    ll deno=1ll;
    while(n>0)
    {
        if(n&1)
        {
            deno=deno*a[j];
        }
        n=n>>1;
        j++;
    }
    return deno;
}
ll printsub2(ll *a,ll n,ll n1)
{
    ll ans=0ll;
    for(ll i=1;i<(1<<n);i++)
    {
        ll setbit=__builtin_popcount(i);
        ll ans1=printnum1(a,i);
        if(setbit&1)
        {
            ans=ans+n1/ans1;
        }
        else
        {
            ans=ans-n1/ans1;
        }
    }
    return ans;
}
void uniquesec()
{
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans=ans^a[i];
    }
    int temp=ans;
    int pos=0;
    while(!temp&1)
    {
        pos++;
        temp=temp>>1;
    }
    int mask=1<<pos;
    int a1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]&mask)
        {
            a1=a1^a[i];
        }
    }
    int b=ans^a1;
    cout<<min(a1,b)<<" "<<max(a1,b)<<endl;
}
void counttri()
{
	int a[64]={0};
	int n,no,j;
	cin>>n;
	while(n--)
	{
		j=0;
		cin>>no;
		while(no>0)
		{
			if(no&1)
			{
				a[j]++;
			}
			no=no>>1;
			j++;
		}
	}
	int ans=0;
	int pow=1;
	for(int i=0;i<64;i++)
	{
		a[i]=a[i]%3;
		ans=ans+pow*a[i];
		pow=pow*2;
	}
	cout<<ans<<endl;

}

int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    ll a[]={2,3,5,7,11,13,17,19};
    cout<<printsub2(a,8ll,n)<<endl;
    }
    uniquesec();*/
    counttri();
    return 0;
}
