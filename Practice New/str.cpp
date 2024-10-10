#include<iostream>
using namespace std;
int main() {
	int m,n,k,s;
	cin>>m>>n>>k>>s;
	char a[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int i=0;
	while(i<m)
	{
		int j=0;
		while(j<n)
		{
			if(a[i][j]=='.')
			{

				cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" subtract two "<<"("<<s<<"- 2 ) = "<<s-2<<endl;
				s=s-2;
				if(j==n-1)
                {
                    cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" we won't subtract bcoz last ele  "<<"("<<s<<"- 0 ) = "<<s<<endl;
                    j++;
                    continue;
                }
				cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" subtract one "<<"("<<s<<"- 1 ) = "<<s-1<<endl;
                s=s-1;
                j++;
                continue;
			}
			else if(a[i][j]=='*')
			{

				cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" add 5 "<<"("<<s<<"+ 5 ) = "<<s+5<<endl;
				s=s+5;
				if(j==n-1)
                {
                    cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" we won't subtract bcoz last ele  "<<"("<<s<<"- 0 ) = "<<s<<endl;
                    j++;
                    continue;
                }
				cout<< " at index ( i , j ) "<<i<< " " << j<<" "<< " value is "<< a[i][j]<<" subtract one "<<"("<<s<<"- 1 ) = "<<s-1<<endl;
                s=s-1;
                j++;
                continue;
			}
			else if(a[i][j]=='#')
			{
				break;
			}
		}
		i++;
	}
	if(s>=k)
	{
		cout<<"Yes"<<endl;
		cout<<s;
	}
	else
	{
		cout<<"No"<<endl;
		cout<<s;
	}

	return 0;
}
