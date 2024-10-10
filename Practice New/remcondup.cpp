#include<bits/stdc++.h>
using namespace std;
void revdup(char *a,int start)
{
	if(start>=strlen(a)-1)
	{
		return ;
	}
	revdup(a,start+1);
	if(a[start]==a[start+1])
	{
		int l=strlen(a);
		cout<<" l = " <<l<<endl;
		cout<<"start = "<<start<<endl;
		for(int i=start+1;i<l;i++)
		{
		    cout<<a[i-1]<<  " = "<<a[i]<<endl;
			a[i-1]=a[i];

		}

		a[l-1]='\0';
	}

}
int main() {
	char s[1001];
	cin>>s;
	revdup(s,0);
	cout<<s;
	return 0;
}
