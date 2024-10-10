#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int i=1;
    while(i<=2*n)
    {
        int space;
        if(i>n)
        {
            space=2*(i-n)-1;
        }
        else
        {
        space=n-i;
        }
        while(space>0)
        {
            cout<<" ";
            space--;
        }
        int j;
        if(i>n)
        {
            j=2*(i)-n-1;
        }
        else
        {
            j=1;
        }

        while(j<=2*i-1)
        {
            cout<<"*";
            j++;
        }

        cout<<endl;
        i++;
    }
    /*i=1;
    while(i<=n)
    {
        int space=1;
        while(space<=i)
        {
            cout<<" ";
            space++;
        }
        int j=1;
        while(j<=2*(n-1)-2*i+1)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
*/

    return 0;
}
