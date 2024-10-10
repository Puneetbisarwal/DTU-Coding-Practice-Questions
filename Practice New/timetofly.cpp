#include<bits/stdc++.h>
using namespace std;
int multiplyself(int a,int b)
{
    if(b==0)
    {
        return 0;
    }

    return a+multiplyself(a,b-1);
}
int stringtoint(char *a,int n)
{
    if(n==0)
    {
        return 0;
    }
    int ans=stringtoint(a,n-1);
    return ans*10+(a[n-1]-'0');
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<multiplyself(a,b)<<endl;
    int n;
    cin>>n;
    char a1[n];
    cin>>a1;
    cout<<stringtoint(a1,n);
    return 0;
}
