#include<bits/stdc++.h>
int subsetsum(int *a, int n , int output[][20] , int k)
{
	if(n==0)
	{
		if(k==0)
		{
			output[0][0]=0;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int so1[1000][20];
	int sz1=subsetsum(a+1,n-1,so1,k-a[0]);
	int so2[1000][20];
	int sz2=subsetsum(a+1,n-1,so2,k);
	for(int i=0;i<sz2;i++)
	{
		output[i][0]=so2[i][0];
		for(int j=1;j<=so2[i][0];j++)
		{
			output[i][j]=so2[i][j];
		}
	}
	for(int i=0;i<sz1;i++)
	{
		output[i+sz2][0]=so1[i][0]+1;
		output[i+sz2][1]=a[0];
		for(int j=1;j<=so1[i][0];j++)
		{
			output[i+sz2][j+1]=so1[i][j];
		}
	}
	return sz1+sz2;
}
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int output[1000][20];
	int k=subsetsum(a,n,output,0);
	for(int i=0;i<k;i++)
    {
        for(int j=0;j<=output[i][0];j++)
        {
            cout<<output[i][j]<<" ";
        }

        cout<<endl;
    }
	if(k>1)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	}
	return 0;
}
