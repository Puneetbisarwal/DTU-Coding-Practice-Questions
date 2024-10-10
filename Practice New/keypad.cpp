
#include<bits/stdc++.h>
using namespace std;
int keypad(int n,string out[] , string help[])
{
	if(n==0)
	{
		out[0]="";
		return 1;
	}
	string so[1000];
	int ld=n%10;
	int small=keypad(n/10,so,help);

	string hp=help[ld];

	int k=0;
	for(int i=0;i<hp.length();i++)
	{
		for(int j=0;j<small;j++)
		{
		    cout<< "out["<<k<<"] = "<<so[j]<<" + "<< hp[i]<<endl;
			out[k]=so[j]+hp[i];
			k++;
		}
	}
	return k;
}
int main() {
	string help[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	/*string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };*/
	string out[1000];
	int k=keypad(567,out,help);
	for(int i=0;i<k;i++)
	{
		cout<<out[k]<<endl;
	}
	return 0;
}
