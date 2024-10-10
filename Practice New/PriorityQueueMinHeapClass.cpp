#include<bits/stdc++.h>
using namespace std;
class PriorityMinQueue
{
    private:
    vector<int> v;
    public:
    void RemoveMin()
    {
        int s=v.size();
        if(s==0)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        int a=v[0];
        cout<<a<<endl;
        v[0]=v[s-1];
        v.pop_back();
        int minindex=0;
        int i=minindex;
        int child1=2*i+1,child2=2*i+2;
        while(child1<s-1)
        {
            if(v[i]>v[child1])
            {
                i=child1;
            }
            if(child2<s-1 && v[i]>v[child2])
            {
                i=child2;
            }
            if(i==minindex)
            {
                return;
            }
            swap(v[i],v[minindex]);
            minindex=i;
            child1=2*minindex+1;
            child2=2*minindex+2;

        }
    }
    bool IsEmpty()
    {
        if(v.size()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Insert(int k)
    {
        v.push_back(k);
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
    int GetSize()
    {
        return v.size();
    }
    void GetMin()
    {
        if(v.size()==0)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<v[0]<<endl;
    }
};
int main()
{
    PriorityMinQueue p;
    cout<<"Enter 1 for GetMin"<<endl;
    cout<<"Enter 2 for GetSize"<<endl;
    cout<<"Enter 3 for IsEmpty"<<endl;
    cout<<"Enter 4 for Insert"<<endl;
    cout<<"Enter 5 for RemoveMin"<<endl;
    cout<<"Enter -1 to exit"<<endl;
    int n;
    cin>>n;
    while(n!=-1)
    {
    switch(n)
    {
    case 1:
        p.GetMin();
        break;
    case 2:
        cout<<p.GetSize()<<endl;
        break;
    case 3:
        if(p.IsEmpty())
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            cout<<"Not Empty"<<endl;
        }
        break;
    case 4:
        cout<<"Enter ele to be inserted"<<endl;
        int r;
        cin>>r;
        p.Insert(r);
        break;
    case 5:
        p.RemoveMin();
        break;
    default:
        return 0;
    }
    cin>>n;
    }
    return 0;
}
