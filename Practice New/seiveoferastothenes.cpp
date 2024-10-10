#include<bits/stdc++.h>
using namespace std;
void SeiveofEratosthenes(int n)
{
    bool freq[n+1];
    memset(freq,true,sizeof(freq));
    for(int i=2;i*i<=n;i++)
    {
        if(freq[i])
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                freq[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(freq[i])
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int n;
    cin>>n;
    SeiveofEratosthenes(n);
    return 0;
}
