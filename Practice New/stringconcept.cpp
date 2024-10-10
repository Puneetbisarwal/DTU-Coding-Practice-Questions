#include<bits/stdc++.h>
using namespace std;
bool compare(string s1,string s2)
{
	if(s1.length()<=s2.length() && s2.substr(0,s1.length())==s1)
    {
        return false;
    }
    else if(s2.length()<=s1.length() && s1.substr(0,s2.length())==s2)
    {
        return true;
    }
    else
    {
        return s1<s2;
    }
}
int main() {
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n,compare);
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
