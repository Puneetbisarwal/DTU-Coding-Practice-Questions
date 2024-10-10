#include<bits/stdc++.h>
using namespace std;
int maxhistogramarea(int *a,int n)
{
    int top,maxarea=INT_MIN,area,i;
    stack<int> s;
    for(i=0;i<n;i++)
    {
        if(s.empty() || a[i]>a[s.top()])
        {
            s.push(i);
        }
        else
        {
            while(!s.empty())
            {
                if(a[s.top()]<=a[i])
                {
                    break;
                }
                top=s.top();
                s.pop();
                if(s.empty())
                {
                    area=a[top]*i;
                    if(area>maxarea)
                    {
                        maxarea=area;
                    }
                }
                else
                {
                    area=a[top]*(i-s.top()-1);
                    if(area>maxarea)
                    {
                        maxarea=area;
                    }
                }
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
        top=s.top();
        s.pop();
        if(s.empty())
        {
            area=a[top]*i;
            if(area>maxarea)
            {
                maxarea=area;
            }
        }
        else
        {
            area=a[top]*(i-s.top()-1);
            if(area>maxarea)
            {
                maxarea=area;
            }
        }
    }
    return maxarea;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    cout<<maxhistogramarea(a,n);
    return 0;
}
