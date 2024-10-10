
#include<iostream>
using namespace std;
int main() {
	char s[100];
	char a1[201];
	cin>>s;
	int i=0,l=0;
	int c=1;
	while(s[i]!='\0')
	{
		if(s[i]!=s[i+1])
		{
			a1[l]=s[i];
			l++;
			a1[l]=c+'0';
			l++;
			c=1;
			i++;
		}
		else
		{
			c++;
			i++;
		}
	}
	a1[l]='\0';
	int p=0;
	while(a1[p]!='\0')
	{
		cout<<a1[p];
		p++;
	}
	return 0;
}
