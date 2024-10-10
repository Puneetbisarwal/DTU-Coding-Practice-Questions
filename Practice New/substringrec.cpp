#include<bits/stdc++.h>
using namespace std;
int keypad(char s[] , string out[] , string help[])
{
	if(strlen(s)==0)
	{
		out[0]="";
		return 1;
	}
	string so[10000];
	int fd=s[0]-'0';
	string hp=help[fd];
	int sa=keypad(s+1,so,help);
	int k=0;
	for(int i=0;i<hp.length();i++)
	{
		for(int j=0;j<sa;j++)
		{
			out[k++]=hp[i]+so[j];
		}
	}
	return k;
}
int main() {
	char s[100];
	cin>>s;
	string out[10000];
	string help[]={"",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int k=keypad(s,out,help);
	for(int i=0;i<k;i++)
	{
		cout<<out[i]<<endl;
	}
	return 0;
}
