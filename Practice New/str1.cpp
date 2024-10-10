#include<bits/stdc++.h>
using namespace std;
int permutation(string s,string out[])
{
    if(s.length()==0)
    {
        out[0]="";
        return 1;
    }
    string out1[100];
    int k=permutation(s.substr(1),out1);
    int h=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=out1[i].length();j++)
        {
            out[h++]=out1[i].substr(0,j)+s[0]+out1[i].substr(j);
        }
    }
    return h;
}
int main()
{
    string s;
    cin>>s;
    string out[100];
    int k=permutation(s,out);
    for(int i=0;i<k;i++)
    {
        cout<<out[i]<<endl;
    }
    return 0;
}
