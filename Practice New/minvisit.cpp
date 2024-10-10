#include<bits/stdc++.h>
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int>> p;
	int n,k;
	int a[k];
	int type,x,y,j;
	cin>>n>>k;
	while(n--)
	{
		cin>>type;
		if(type%2==0)
		{
		    j=0;
		    while(j<k)
            {
                a[j]=p.top();
                p.pop();
                j++;
            }
			cout<<a[j]<<endl;
            while(j>=0)
            {
                p.push(a[j]);
                j--;
            }
		}
		else
		{
		    cin>>x>>y;
			p.push(x*x+y*y);
		}
	}
	return 0;
}
