#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *a,int n,int key)
{
    int e=n-1;
    int s=0;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}
int firstocc(int *a,int n,int no)
{
    int ans=-1;
    int e=n-1;
    int s=0;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(a[mid]==no)
        {
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>no)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}
int lastocc(int *a,int n,int no)
{
    int ans=-1;
    int e=n-1;
    int s=0;
    int mid=(s+e)/2;
    while(s<=e)
    {
        if(a[mid]==no)
        {
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>no)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}
float squareroot(int no,int p)
{
    int s=0;
    int e=no;
    int mid;
    float ans;
    mid=(s+e)/2;
    while(s<=e)
    {
        if(mid*mid==no)
        {
            ans=mid;
            break;
        }
        else if(mid*mid<no)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    int k=0;
    int inc=0.1;
    while(k<p)
    {
        while(ans*ans<=no)
        {
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
        k++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=binarysearch(a,n,4);
    if(ans==-1)
    {
        cout<<"Ele not found "<<endl;
    }
    else
    {
        cout<<"Ele found at "<<ans <<" place"<<endl;
    }
    /*cout<<"First occurence of 2 "<< firstocc(a,n,2)<<endl;
    cout<<"last occurence of 2 "<< lastocc(a,n,2)<<endl;
    cout<<" Square root of 15 upto three places "<< squareroot(15,3)<<endl;*/
    return 0;
}
