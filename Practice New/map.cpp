#include<bits/stdc++.h>
using namespace std;
/*class edge
{
    public:
    int source;
    int destination;
    int weight;
};
bool compare(edge e1 ,edge e2)
{
    return e1.weight<e2.weight;
}
int main()
{
    edge a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i].source>>a[i].destination>>a[i].weight;
    }
    for(int i=0;i<5;i++)
    {
        cout<<a[i].source<<" "<<a[i].destination<<" "<<a[i].weight<<endl;
    }
    sort(a,a+5,compare);
    cout<<"after sort"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i].source<<" "<<a[i].destination<<" "<<a[i].weight<<endl;
    }
    return 0;
}
*/
void ch(int a[])
{
    a[2]=a[4];
}
int main()
{
    int un[6]={2,1,5,3,4,5};
    int source=0;
    int i1=-1;
    while(i1!=un[source])
    {
        i1=un[source];
        source=un[i1];
    }
    cout<<un[2]<<endl;
    cout<<i1<<endl;
    ch(un);
    cout<<un[2]<<" "<<un[4];
    return 0;
}
