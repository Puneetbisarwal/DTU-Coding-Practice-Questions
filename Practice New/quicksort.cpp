
#include<iostream>
using namespace std;
int partition(int a[],int si,int ei)
{
	int count=0;
	int piv=a[si];
	for(int i=si+1;i<=ei;i++)
	{
		if(a[i]<=piv)
		{
			count++;
		}
	}
	int pivpos=si+count;
	int temp=a[pivpos];
	a[pivpos]=a[si];
	a[si]=temp;
	int i=si;
	int j=ei;
	while(i<pivpos && j>pivpos)
	{
		if(a[i]<=a[pivpos])
		{
			i++;
		}
		else if(a[j]>a[pivpos])
		{
			j--;
		}
		else
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	return pivpos;
}
void quicksort(int a[],int si,int ei)
{
	if(si>ei)
	{
		return;
	}
	int pivpos=partition(a,si,ei);
	quicksort(a,si,pivpos-1);
	quicksort(a,pivpos+1,ei);
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){cin>>a[i];}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){cout<<a[i]<<" ";}
	return 0;
}
