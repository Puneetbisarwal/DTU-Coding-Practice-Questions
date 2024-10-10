#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    cin>>i;
    int n;
    cin>>n;
    int j= ~0<<i;
    cout<<(n&j);
    return 0;
}
