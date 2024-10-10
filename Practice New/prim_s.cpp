#include<bits/stdc++.h>
using namespace std;
int findMin(int *weight,int *visited,n)
{
    int Minvertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (Minvertex==-1) || weight[Minvertex] < weight[i])
        {
            Minvertex=i;
        }
    }
    return Minvertex;
}
void Prims(int **edge,int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int weight[n];
    weight[0]=0;
    for(int i=1;i<n;i++)
    {
        weight[i]=INT_MAX;
    }
    int parent[n];
    parent[0]=-1;
    for(int i=0;i<n;i++)
    {
        int MinVertex=findMin(weight,visited);
        visited[MinVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edge[MinVertex][j]!=0 && !visited[j])
            {
                weight[j]=edge[MinVertex][j];
                parent[j]=MinVertex;
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,e;
    cin>>n>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int sou,des,weight;
        cin>>sou>>des>>weight;
        edge[sou][des]=weight;
        edge[des][sou]=weight;
    }
    Prims(edge,n,e);
    return 0;
}
