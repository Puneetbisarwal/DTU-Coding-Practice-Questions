#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int m=INT_MIN;
	for(int i=0;i<n;i++)
	{
		m=max(m,a[i]);
	}
	m=m+1;
	int a1[m]={0};
	for(int i=0;i<n;i++)
	{
		a1[a[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		cout<<a1[i]<<" "<<endl;
	}
	int k=0;
	for(int i=0;i<m;i++)
	{
		while(a1[i]>0)
		{
			a[k]=i;
			k++;
			a1[i]--;
		}
	}
	for(int i=0;i<n;i++){cout<<a[i]<<" ";}
	return 0;
}
