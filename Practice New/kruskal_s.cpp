#include<bits/stdc++.h>
using namespace std;

class edge
{
  	public:
    int source;
    int des;
    int weight;
};
bool compare(edge e1 ,edge e2)
{
    return e1.weight<e2.weight;
}
bool Union(int source ,int des ,int un[] ,int v)
{
    int i1=-1,i2=-1;
    while(i1!=un[source])
    {
        i1=un[source];
        source=un[i1];
    }
    while(i2!=un[des])
    {
        i2=un[des];
        des=un[i2];
    }
    if(i1!=i2)
    {
        un[i2]=i1;
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
  	int v,e;
    cin>>v>>e;
    edge input[e];
	for(int i=0;i<e;i++)
    {
        cin>>input[i].source>>input[i].des>>input[i].weight;
    }
    sort(input,input+e,compare);
    edge output[v-1];
    int un[v];
    for(int i=0;i<v;i++)
    {
        un[i]=i;
    }
    int i=0;
    int k=0;
    while(k!=v-1)
    {
        if(Union(input[i].source,input[i].des,un,v))
        {
            output[k]=input[i];
            k++;
        }
        i++;
    }
    for(int i=0;i<v;i++){cout<<un[i]<<" ";}
    cout<<endl;
    for(int i=0;i<v-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].des<<" "<<output[i].weight<<endl;
    }
  return 0;
}
