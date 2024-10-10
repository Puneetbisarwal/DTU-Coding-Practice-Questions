#include<bits/stdc++.h>
using namespace std;
int keypad(char *a,string out[] , string help[])
{
	if(strlen(a)==0)
	{
		out[0]="";
		return 1;
	}
	string so[1000];
	int small=keypad(a+1,so,help);
	string hp=help[a[0]-'0'];
	int k=0;
	for(int i=0;i<hp.length();i++)
	{
		for(int j=0;j<small;j++)
		{
		    cout<< "out["<<k<<"] = "<<so[j]<<" + "<< hp[i]<<endl;
			out[k++]=hp[i]+so[j];
		}
	}
	return k;
}
int main() {
	char a[10];
	cin>>a;
	string help[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
	string output[1000];
	int k=keypad(a,output,help);
	for(int i=0;i<k;i++)
	{
		cout<<output[k]<<endl;
	}
	return 0;
}
