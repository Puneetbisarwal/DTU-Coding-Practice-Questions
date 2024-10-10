#include <iostream>
#include <vector>
using namespace std;

int coinChange(int S[],int m,int n)
{
    if(n < 0)
        return 0;

    if(n == 0)
        return 1;


    if (m <=0 && n >= 1)
        return 0;


    return coinChange( S, m - 1, n ) + coinChange( S, m, n-S[m-1] );
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];

    }
    cout<<coinChange(arr,m,n)<<endl;
    return 0;
}
