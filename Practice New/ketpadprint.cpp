#include<bits/stdc++.h>
using namespace std;
int printkeypad(string output[],string options[10],char *a)
{
    if(strlen(a)==0)
    {
        output[0]="";
        return 1;
    }
    int fd=a[0]-'0';
    string so[1000];
    int sa=printkeypad(so,options,a+1);
    string hp=options[fd];
    int k=0;
    for(int i=0;i<hp.length();i++)
    {
        for(int j=0;j<sa;j++)
        {
            output[k++]=hp[i]+so[j];
        }
    }
    return k;
}
int main()
{
    string s[1000];
    string options[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char a[10];

    cin>>a;
    int k=printkeypad(s,options,a);
    for(int i=0;i<k;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
