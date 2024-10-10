
#include<bits/stdc++.h>
using namespace std;
void revdup(char *s,int start)
{
	if(start>=strlen(s)-1)
	{
		return ;
	}
	revdup(s,start+1);
	if(s[start]==s[start+1] )
	{
	    int e=strlen(s);
		s[e+1]='\0';
		for(int i=e-1;i>=start+1;i--)
		{
			s[i+1]=s[i];
		}
		s[start+1]='*';
	}


}
int main() {
	char s[100];
	cin>>s;
	revdup(s,0);
	cout<<s;
	return 0;
}
