#include<bits/stdc++.h>
using namespace std;
int printkeypad(int n,string out[],string help[])
{
    if(n==0)
    {
        out[0]="";
        return 1;
    }
    int ld=n%10;
    int sn=n/10;
    string so[100];
    int s_size=printkeypad(sn,so,help);
    string s=help[ld];
    int k=0;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<s_size;j++)
        {
            out[k++]=so[j]+s[i];
        }
    }
    cout<<k<<endl;
    return k;
}
int printkeypad(string out[],int n)
{
    string help[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return printkeypad(n,out,help);
}
int main()
{
    int n;
    cin>>n;
    string s[100];
    int k=printkeypad(s,n);
    for(int i=0;i<k;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
