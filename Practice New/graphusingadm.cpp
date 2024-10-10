#include<bits/stdc++.h>
using namespace std;
void PrintDfs(int **edge ,int n,bool *visited,int sv)
{
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edge[sv][i]==1 && !visited[i])
        {
            PrintDfs(edge,n,visited,i);
        }
    }
}
void PrintDfs(int **edge ,int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        PrintDfs(edge,n,visited,i);
    }
}
void PrintBfs(int **edge ,int n,bool *visited,int sv)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int current=q.front();
        cout<<current<<" ";
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(i==current)
            {
                continue;
            }
            if(edge[current][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
void PrintBfs(int **edge ,int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        PrintBfs(edge,n,visited,i);
    }
}
bool HasPath(int **edge ,int n , int sv ,int ev , bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(edge[current][i]==1 && !visited[i])
            {
                if(i==ev)
                {
                    return true;
                }
                else
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    return false;
}
bool HasPath(int **edge ,int n , int sv ,int ev)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    return HasPath(edge,n,sv,ev,visited);
}
void GetPath(int **edge , int n ,int sv ,int ev ,bool *visited ,vector<int> &v)
{
    if(sv==ev)
    {
        v.push_back(sv);
        visited[sv]=true;
        return ;
    }
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edge[sv][i]==1 && !visited[i])
        {
            vector<int> v1;
            GetPath(edge,n,i,ev,visited,v1);
            if(v1.size()>0)
            {
                v.push_back(sv);
                for(int i=0;i<v1.size();i++)
                {
                    v.push_back(v1[i]);
                }
            }
        }
    }
}
void GetPath(int **edge ,int n ,int v1 ,int v2)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int> v;
    GetPath(edge,n,v1,v2,visited,v);
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
}
bool GetPathBfs(int **edge ,int n ,int sv ,int ev ,bool *visited ,vector<int> &v)
{
    unordered_map<int,int> m;
    queue<int> q;
    cout<<"push sv in queue "<<sv<<endl;
    q.push(sv);
    visited[sv]=true;
    bool flag=false;
    while(!q.empty() && !flag)
    {
        int current=q.front();
        cout<<current<<endl;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(edge[current][i]==1 && !visited[i])
            {
                cout<<" i = "<<i<<endl;
                m[i]=current;
                cout<<"m[i]=current " << current<<endl;
                q.push(i);
                visited[i]=true;
                if(i==ev)
                {
                    flag=true;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        return NULL;
    }
    else
    {
        int current=ev;
        v.push_back(current);
        while(current!=sv)
        {
            current=m[current];
            v.push_back(current);
        }
    }
    return flag;
}
void GetPathBfs(int **edge , int n,int v1 ,int v2)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int> v;
    if(GetPathBfs(edge,n,v1,v2,visited,v))
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    else
    {
        cout<<"NO";
    }
}
void AllConnectedComponents(int **edge ,int n ,bool *visited ,vector<int> *so ,int sv)
{
    so->push_back(sv);
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edge[sv][i]==1 && !visited[i])
        {
            AllConnectedComponents(edge,n,visited,so,i);
        }
    }
}
void AllConnectedComponents(int **edge ,int n)
{
    vector<vector<int>*> *v=new vector<vector<int>*>;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> *so=new vector<int>;
            AllConnectedComponents(edge,n,visited,so,i);
            v->push_back(so);
        }
    }
    for(int i=0;i<v->size();i++)
    {
        vector<int>* com=v->at(i);
        for(int j=0;j<com->size();j++)
        {
            cout<<com->at(j)<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter number of vertices and edges "<<endl;
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
        int a,b;
        cin>>a>>b;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    PrintDfs(edge,n);
    cout<<endl;
    PrintBfs(edge,n);
    cout<<endl;
    cout<<"Enter two vertices to find path between them"<<endl;
    int v1,v2;
    cin>>v1>>v2;
    cout<<HasPath(edge,n,v1,v2);
    cout<<endl;
    cout<<"Enter vetices to get path between them "<<endl;
    int v3,v4;
    cin>>v3>>v4;
    cout<<"Path dfs"<<endl;
    GetPath(edge,n,v3,v4);
    cout<<endl;*/
    cout<<"Path Bfs"<<endl;
    GetPathBfs(edge,n,v3,v4);
    AllConnectedComponents(edge,n);
    return 0;
}

