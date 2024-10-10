#include<bits/stdc++.h>
using namespace std;
#define m 1000005
int main() {
    int t;
    cin>>t;
    vector<int> v;
	bool prime[m];
    while(t--)
    {
	int n;
	cin>>n;
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<m;i++)
	{
		if(prime[i]==true)
		{
			for(int j=i*i;j<m;j=j+i)
			{
				prime[j]=false;
			}
		}
	}
	for(int j=2;j<m;j++)
	{
		if(prime[j])
		{
			v.push_back(j);
		}
	}
	cout<<v[n-1]<<endl;
    }
	return 0;
}
