#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int space=n-i;
        while(space>=1)
        {
            cout<<" ";
            space--;
        }
        /*int j=1;
        while(j<=i)
        {
            cout<<j;
            j++;
        }
        if(i>=2)
        {
            int k=i+1;
            while(k<=i+j-2)
            {
                cout<<k;
                k++;
            }
        }*/
        int j=1;
        while(j<=i*2-1)
        {
            cout<<j;
            j++;
        }
        i++;
        cout<<endl;
    }
    return 0;
}
