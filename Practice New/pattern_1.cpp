#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    int val=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout<<val;
            val++;
            j++;
        }
        i++;
        cout<<endl;
    }
    return 0;
}
