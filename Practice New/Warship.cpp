#include<bits/stdc++.h>
using namespace std;
int noofwarships(int m,int l)
{
    if(l==1)
    {
        return 1;
    }
    l--;
    queue<int> q;
    q.push(2);
    int ans=1;
    q.push(-1);
    while(1)
    {
        if(l==0)
        {
            break;
        }
        int v=q.front();
        q.pop();
        if(v==-1)
        {
            l--;
            q.push(-1);
            continue;
        }
        int val=((v*v)+1)%m;
        ans=ans+val;
        int h=0;
        q.push(0);
        h++;
        while(h<val)
        {
            int c=((v*v)+1)%m-1;
            q.push(c);
            h++;
        }
    }
    return ans;
}
int main()
{
    int m,l;
    cout<<"Enter modulus and layer "<<endl;
    cin>>m>>l;
    cout<<noofwarships(m,l);
    return 0;
}
