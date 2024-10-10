#include<bits/stdc++.h>
using namespace std;
int nooftiles(int n)
{
    if(n<0){return 0;}
    if(1<=n && n<=3)
    {
        return 1;
    }
    if(n==4){return 2;}
    return nooftiles(n-1)+ nooftiles(n-4);
}
int main()
{
    int n;
    cin>>n;
    cout<<nooftiles(n)<<endl;
    return 0;
}
