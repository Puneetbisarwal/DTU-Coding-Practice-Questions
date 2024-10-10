#include<bits/stdc++.h>
using namespace std;
int subsequence(string s, char out[][20])
{
    if(s.length()==0)
    {
        out[0][0]='\0';
        return 1;
    }
    int sa=subsequence(s.substr(1),out);
    for(int i=0;i<sa;i++)
    {
        out[i+sa][0]=s[0];
        for(int j=0;j<strlen(out[i]);j++)
        {
            out[i+sa][j+1]=out[i][j];
        }
    }
    return 2*sa;
}
int main()
{
   string s;
   cin>>s;
   char out[100][20];
   int a=subsequence(s,out);
   for(int i=0;i<a;i++)
   {
       cout<<out[i]<<endl;
   }
   return 0;
}
