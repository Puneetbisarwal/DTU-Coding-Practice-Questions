#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int sou;
    int des;
};
void merge(int x ,int y ,int *parent)
{
    parent[x]=min(parent[x],parent[y]);
    parent[y]=x;
}
int find(int x ,int *parent)
{
    vector<int> v;
    while(parent[x]>0)
    {
        v.push_back(x);
        x=parent[x];
    }
    for(int i=0;i<v.size();i++)
    {
        parent[v[i]]=x;
    }
    return x;
}
int main()
{
    int n,e;
    cin>>n>>e;
    edge a[e];
    for(int i=0;i<e;i++)
    {
        cin>>a[i].sou>>a[i].des;
    }
    int parent[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-i;
    }
    for(int i=0;i<e;i++)
    {
        int o=find(a[i].sou,parent);
        int j=find(a[i].des,parent);
        if(0!=j)
        {
            merge(o,j,parent);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    cout<<"enter q"<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        static int i=1;
        cout<<i<<endl;
        i++;
        int p,v;
        cin>>p>>v;
        int k=find(p,parent);
        int l=find(v,parent);
        cout<<l<<" "<<k<<endl;
        if(l!=k)
        {
            if(parent[k]>parent[l])
            {
                cout<<v<<endl;
            }
            else
            {
                cout<<p<<endl;
            }
        }
        else
        {
            cout<<"tie"<<endl;
        }
    }
    return 0;
}
