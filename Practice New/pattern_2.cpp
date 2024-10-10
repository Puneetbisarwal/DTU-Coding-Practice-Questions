#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=n;
        int a=0;
        while(j>=i)
        {
            char alpha=65+a;
            cout<<alpha;
            j--;
            a++;
        }
        int k=n;
        int b=n-i;
        while(k>=i)
        {
            char alph=65+b;
            cout<<alph;
            b--;
            k--;
        }
        i++;
        cout<<endl;
    }
    return 0;
}
