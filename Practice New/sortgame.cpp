#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string,int> p1,pair<string,int> p2)
{
	if(p1.second==p2.second)
	{
		return p1.first<p2.first;
	}
	return p1.second>p2.second;
}
int main() {
	int n,min;
	cin>>n>>min;
	pair<string,int> a[n];
	string name;
	int sal;
	for(int i=0;i<n;i++)
	{
		cin>>name;
		cin>>sal;
		a[i].first=name;
		a[i].second=sal;
	}
	sort(a,a+n,compare);
	for(int i=0;i<n;i++)
	{
		if(a[i].second>=min)
		{
			cout<<a[i].first<<" "<<a[i].second<<endl;
		}
	}
	return 0;
}
