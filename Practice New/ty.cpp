#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	int a[100];
	long long int a1,b;
	cin>>a1>>b;
	int i=0;
	while(a1> 0 && b>0)
	{
		if(a1%10 == b % 10)
		{
			a[i]=0;
			i++;
			a1/=10;
			b/=10;
		}
		else
		{
			a[i]=1;
			i++;
			a1/=10;
			b/=10;
		}
	}
	for(int j=i-1;j>=0;j--){cout<<a[j];}
	}
	return 0;
}
