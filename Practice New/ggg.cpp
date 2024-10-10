#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void printnum(int n)
{
    int g,l;
    for(int i=1;i<n;i++)
    {
        g=gcd(max(i,n-i),min(i,n-i));
        l=(i*(n-i))/g;
        if((l+g)==n)
        {
            cout<<i<<" "<<n-i<<endl;
            break;
        }
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printnum(n);
    }
    return 0;
}
