#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int sou;
    int des;
};
int FindNaive(int x ,int *parent)
{
    while(x!=parent[x])
    {
        x=parent[x];
    }
    return x;
}
void MergeNaive(int x , int y ,int *parent)
{
    int i=FindNaive(x,parent);
    int j=FindNaive(y,parent);
    if(i!=j)
    {
        parent[j]=i;
    }
}
int FindSec(int x , int *parent)
{
    while(parent[x]>0)
    {
        x=parent[x];
    }
    return x;
}
void MergeSec(int x,int y,int *parent)
{
    int i=FindSec(x,parent);
    int j=FindSec(y,parent);
    if(i!=j)
    {
        parent[i]+=parent[j];
        parent[j]=i;
    }
}
int FindPathCompressionByUnion(int x , int *parent)
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
void MergePathCompressionByUnion(int x ,int y ,int *parent)
{
    int i=FindPathCompressionByUnion(x,parent);
    int j=FindPathCompressionByUnion(y,parent);
    if(i!=j)
    {
        parent[i]+=parent[j];
        parent[j]=i;
    }
}
int FindPathCompressionByUnionByRank(int x ,int *parent)
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
void MergePathCompressionByUnionByRank(int x ,int y ,int *parent ,int *rank)
{
    int i=FindPathCompressionByUnionByRank(x,parent);
    int j=FindPathCompressionByUnionByRank(y,parent);
    if(i!=j)
    {
        if(rank[i]>rank[j])
        {
            parent[j]=i;
            rank[i]+=rank[j];
        }
        else
        {
            parent[i]=j;
            rank[j]+=rank[i];
        }

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
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
        parent[i]=i;
    }
    int x,y;
    for(int i=0;i<e;i++)
    {
     MergeNaive(a[i].sou,a[i].des,parent);
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    int parent1[n];
    for(int i=0;i<n;i++)
    {
        parent1[i]=-1;
    }
    for(int i=0;i<e;i++)
    {
     MergeSec(a[i].sou,a[i].des,parent1);
    }
    for(int i=0;i<n;i++)
    {
        cout<<parent1[i]<<" ";
    }
    int parent2[n];
    for(int i=0;i<n;i++)
    {
        parent2[i]=-1;
    }
    for(int i=0;i<e;i++)
    {
        MergePathCompressionByUnion(a[i].sou,a[i].des,parent2);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<parent2[i]<<" ";
    }
    int parent3[n],rank[n];
    for(int i=0;i<n;i++)
    {
        parent3[i]=-1;
        rank[i]=1;
    }
    for(int i=0;i<e;i++)
    {
        MergePathCompressionByUnionByRank(a[i].sou,a[i].des,parent3,rank);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<parent3[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        cout<<rank[i]<<" ";
    }
    return 0;
}

