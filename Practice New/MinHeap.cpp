#include<bits/stdc++.h>
using namespace std;
void DownHeapify(vector<int> &v)
{
    int i=0;
    int child1=2*i+1 , child2=2*i+2;
    while(child1<v.size())
    {
        if(v[i]>v[child1])
        {
            swap(v[i],v[child1]);
            i=child1;
            child1=i*2+1;
            child2=i*2+2;
        }
        else if(child2<v.size() && v[i]>v[child2])
        {
            i=child2;
            child1=i*2+1;
            child2=i*2+2;
        }
        else
        {
            return;
        }
    }
}
void Delete(vector<int> &v)
{
    if(v.size()==0)
    {
        cout<<"Heap Is Empty"<<endl;
        return;
    }
    cout<<"Deleted ele is "<<v[0]<<endl;
    v[0]=v[v.size()-1];
    v.pop_back();
    DownHeapify(v);
}
void UpHeapify(vector<int> &v)
{
    int i=v.size()-1;
    int child=(i-1)/2;
    while(i>0)
    {
        if(v[i]<v[child])
        {
            swap(v[i],v[child]);
            i=child;
            child=(i-1)/2;
        }
        else
        {
            return;
        }
    }
}
void Insert(int k,vector<int> &v)
{
    v.push_back(k);
    UpHeapify(v);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> MinHeap;
    int n;
    do
    {
        cout<<"Enter 1 to Insert"<<endl;
        cout<<"Enter 2 to delete Min Ele"<<endl;
        cout<<"Enter -1 to exit"<<endl;

        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Enter element to insert"<<endl;
            int k;
            cin>>k;
            Insert(k,MinHeap);
            break;
        case 2:
            Delete(MinHeap);
            break;
        default:
            break;
        }
    }while(n!=-1);
    return 0;
}
