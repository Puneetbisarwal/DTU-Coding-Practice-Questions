#include<bits/stdc++.h>
using namespace std;
void bubblesort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}
void selectionsort(int *a,int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}
void insertionsort(int *a,int n)
{
    int val,j;
    for(int i=1;i<n;i++)
    {
        val=a[i];
        j=i-1;
        while(j>=0 && a[j] > val)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }
}
void mergetwosortedarray(int *a1,int n1,int *a2,int n2,int *a)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a1[i]>a2[j])
        {
            a[k]=a2[j];
            j++;
            k++;
        }
        else
        {
            a[k]=a1[i];
            i++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=a2[j];
        k++;
        j++;
    }
}
void merge_sort(int *a, int n)
{
    if(n==1)
    {
        return;
    }
    int mid=n/2;
    int a1[mid],a2[n-mid];
    for(int i=0;i<mid;i++)
    {
        a1[i]=a[i];
    }
    for(int j=mid;j<n;j++)
    {
        a2[j-mid]=a[j];
    }
    merge_sort(a1,mid);
    merge_sort(a2,n-mid);
    mergetwosortedarray(a1,mid,a2,n-mid,a);
}
int partition1(int *a,int s,int e)
{
    int c=0;
    int piv=a[s];
    for(int i=s+1;i<=e;i++)
    {
        if(a[i]<=piv)
        {
            c++;
        }
    }
    int pos=s+c;
    swap(a[s],a[pos]);
    int i=s,j=e;
    while(i<pos && j>pos)
    {
        if(a[i]<=piv)
        {
            i++;
        }
        else if(a[j]>piv)
        {
            j--;
        }
        else
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    return pos;
}
void quick_sort(int *a,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int pivpos=partition1(a,s,e);
    quick_sort(a,s,pivpos-1);
    quick_sort(a,pivpos+1,e);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    //bubblesort(a,n);
    //selectionsort(a,n);
    //insertionsort(a,n);
    merge_sort(a,n);
    //int a1[n];
    //for(int i=0;i<n;i++){cin>>a1[i];}
    //int a2[2*n];
    //mergetwosortedarray(a,n,a1,n,a2);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<endl;
    //for(int i=0;i<2*n;i++){cout<<a2[i]<<" ";}
}
