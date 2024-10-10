#include<bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> arr, int n, int k)
{
    priority_queue<int> q;
    for(int i=0;i<n;i++)
    {
        q.push(arr[i]);
    }
    int j=0;
    while(j<k-1)
    {
        q.pop();
        j++;
    }
    return q.top();
}

void findMedian(int arr[], int n){
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    int ele=0 , maxs=0 ,mins=0;
    for(int i=0;i<n;i++)
    {
        if(ele==0)
        {
            max.push(arr[i]);
			maxs++;
            ele++;
            cout<<max.top()<<endl;

            continue;
        }

        if(maxs>0)
        {
            if(max.top()>arr[i])
            {
                max.push(arr[i]);
                ele++;
                maxs++;
            }
            else
            {
                min.push(arr[i]);
                ele++;
                mins++;
            }
        }

        if(maxs-mins>1)
        {
            min.push(max.top());
            max.pop();
            maxs--;
            mins++;
        }

        if(mins-maxs>1)
        {
            max.push(min.top());
            min.pop();
            mins--;
            maxs++;
        }

        if((ele%2)==0)
        {
            int a1=max.top();
            int a2=min.top();

            cout<<(a1+a2)/2<<endl;
        }
        else
        {
            if(maxs>mins)
            {
                cout<<max.top()<<endl;
            }
            else
            {
                cout<<min.top()<<endl;
            }
        }
    }
}

int main()
{
    /*vector<int> v;
    for(int i=0;i<5;i++)
    {
        int c;
        cin>>c;
        v.push_back(c);
    }
    cout<<kthLargest(v,5,3);*/
    int a[]={6,2,1,3,7,5};
    findMedian(a,6);
    return 0;
}
