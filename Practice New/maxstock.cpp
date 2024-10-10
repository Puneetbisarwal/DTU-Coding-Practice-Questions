#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    int count=0;
    stack<int> s;
    int out[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        count=1;
        if(i==0 || a[i]<=s.top())
        {
            s.push(i);
            out[k]=count;
            k++;
        }
        else
        {
            while(!s.empty())
            {
                if(a[i]<a[s.top()])
                {
                    break;
                }
                else
                {
                    s.pop();
                    count++;
                }
            }
            out[k]=count;
            k++;
            s.push(i);
        }
    }
    for(int i=0;i<count;i++)
    {
        cout<<out[i]<<" ";
    }
    return 0;
}
