#include<bits/stdc++.h>
using namespace std;
void printnum(char *a,int n)
{
    int j=0;
    while(n>0)
    {
        if(n&1)
        {
            cout<<a[j];
        }
        n=n>>1;
        j++;
    }
    cout<<endl;
}
void printsub(char *a,int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        printnum(a,i);
    }
}
int power(int a,int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1)
        {
        ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}
int main()
{
    /*int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    //printsub(a,n);*/
    //cout<<power(2,4);
    cout<<0xF0;
    return 0;
}
