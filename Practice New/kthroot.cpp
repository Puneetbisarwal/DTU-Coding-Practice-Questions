#include<bits/stdc++.h>
using namespace std;
unsigned long long int multiply(unsigned long long int m,int k)
{
	unsigned long long int ans=1;
	while(k>0)
	{
		ans=ans*m;
		k--;
	}
	return ans;
}
int root(unsigned long long int n,int k)
{
	unsigned long long int s=0,e=n;
	unsigned long long int ans;
	while(s<=e)
	{
		unsigned long long int m=(s+e)/2*k;
		if(multiply(m,k)==n)
		{
			ans=m;
			break;
		}
		else if(multiply(m,k)<n)
		{
			ans=m;
			s=m+1;
		}
		else
		{
			e=m-1;
		}
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int n;
		int k;
		cin>>n>>k;
		cout<<root(n,k)<<endl;
	}
	return 0;
}
