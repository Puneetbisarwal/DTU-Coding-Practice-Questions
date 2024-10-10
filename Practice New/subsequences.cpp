#include<bits/stdc++.h>
using namespace std;
int subsequences(string s,string out[])
{
    if(s.length()==0)
    {
        out[0]="";
        return 1;
    }
    int ss=subsequences(s.substr(1),out);
    for(int i=0;i<ss;i++)
    {
        out[ss+i]=out[ss+i]+s[0];
        for(int j=0;j<out[i].length();j++)
        {
            out[ss+i]=out[ss+i]+out[i][j];
        }
    }
    return 2*ss;
}
int main()
{
    string s;
    cin>>s;
    string output[1000];
    int k=subsequences(s,output);
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {

        cout<<output[i]<<endl;
    }
    return 0;
}
