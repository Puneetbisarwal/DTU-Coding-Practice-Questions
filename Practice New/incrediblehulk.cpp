#include<bits/stdc++.h>
using namespace std;
int findpower(int n)
{
	int pow=1,ans=INT_MIN;
	while(pow<=n)
	{
		ans=pow;
		pow=pow*2;
	}
	return ans;
}
int countsteps(int n)
{
	int steps=0,k;
	while(n!=0)
	{
		k=findpower(n);
		n=n-k;
		steps++;
	}
	return steps;
}
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<countsteps(n)<<endl;
	}
	return 0;
}
