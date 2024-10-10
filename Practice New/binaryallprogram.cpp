#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *a,int n,int key)
{
    int e=n-1,s=0,mid;
    //mid=(s+e)/2;
    while(s<=e)
    {
        mid=(s+e)/2;
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
    int s=0,e=n-1,mid,ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
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
    int s=0,e=n-1,mid,ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
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
    int s=0,e=no,mid;
    float ans;
    while(s<=e)
    {
        mid=(s+e)/2;
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
    float inc=0.1;
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
int gcd(int a,int b)
{
    if(b==0){return a;}
    else
        return gcd(b,a%b);
}
int searchsortedrotatedarray(int *a , int s , int e , int key)
{
    if(s>e)
    {
        return -1;
    }
    int mid=(s+e)/2;
    if(a[mid]==key)
    {
        return mid;
    }
    if(a[s]<=a[mid])
    {
        if(key>=a[s] && key<=a[mid])
        {
            return searchsortedrotatedarray(a,s,mid-1,key);
        }
        else
        {
            return searchsortedrotatedarray(a,mid+1,e,key);
        }
    }
    if(key>= a[mid] && key <=a[e])
    {
        return searchsortedrotatedarray(a,mid+1,e,key);
    }
    return searchsortedrotatedarray(a,s,mid-1,key);
}
void rotbyk(int *a,int n,int d)
{
    int g=gcd(n,d);
    for(int i=0;i<g;i++)
    {
        int temp=a[i];
        int j=i;
        while(1)
        {
            int k=j+d;
            if(k>=n)
            {
                k=k-n;
            }
            if(k==i)
            {
                break;
            }
            a[j]=a[k];
            j=k;
        }
        a[j]=temp;
    }
}
int findmaxinrotatedarray(int *a,int s, int e)
{
    if(s>e)
    {
        return -1;
    }
    int mid=(s+e)/2;
    if(a[mid]>=a[mid-1] && a[mid]>=a[mid+1])
    {
        return a[mid];
    }
    if(a[s]>=a[mid])
    {
        return findmaxinrotatedarray(a,s,mid-1);
    }
    else
    {
        return findmaxinrotatedarray(a,mid+1,e);
    }
}
int sum(int *a,int n)
{
    int sum=INT_MIN;
    for(int i=0;i<n;i++){if(a[i]>sum){sum=a[i];}}return sum;
}
bool check(int *a,int n,int s,int k)
{
    int sum=0;
    int ans=1;
    int i=0;
    while(i<n)
    {
        if(sum+a[i]>s)
        {
            sum=a[i];
            ans++;
            if(ans>k){return false;}
        }
        else
        {
            sum+=a[i];
        }
        i++;
    }
    return true;
}
int noofmaxpages(int *a,int n,int k)
{
    int ans;
    int sum1=sum(a,n);
    int s=0,e=sum1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(check(a,n,mid,k))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
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
        cout<<"Ele found at = "<<ans<<endl;
    }
    cout<<"First occ of 2 = "<<firstocc(a,n,2)<<endl;
    cout<<"Last occ of 2 = "<<lastocc(a,n,2)<<endl;
    cout<<"Square root of 10 = "<<squareroot(10,3)<<endl;
    rotbyk(a,n,3);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
    cout<<searchsortedrotatedarray(a,0,n-1,5)<<endl;
    cout<<findmaxinrotatedarray(a,0,n-1)<<endl;
    cout<<"Enter no. of books and student"<<endl;
    int n1,s;
    cin>>n1>>s;
    int a1[n1];
    cout<<"Enter array "<<endl;
    for(int i=0;i<n1;i++){cin>>a1[i];}
    cout<<noofmaxpages(a1,n1,s);
    return 0;
}
