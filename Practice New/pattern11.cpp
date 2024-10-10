#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int space=n-i;
        while(space>0)
        {
            cout<<" ";
            space--;
        }
        int j=1;
        while(j<=i)
        {
            if(j&1)
            {
            cout<<"*";
            }
            else
            {
                cout<<" ";
            }
            j++;
        }
        /*int k=1;
        if(i>=2)
        {
            while(k<=i-1)
            {
            if(k&1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
            k++;
            }
        }*/
        i++;
        cout<<endl;
    }
    return 0;
}
