#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void nextgreater(char a[],int n)
{
    int i;
    for(i=n-1;i>0;i--)
    {
        if(a[i]>a[i-1])
        {
            break;
        }
    }
    if(i==0)
    {
        cout<<"no next greater no. can be formed"<<endl;
    }
    int x=a[i-1]-'0';
    int mi=INT_MAX;
    int j,minind;
    for(j=i;j<n;j++)
    {
        int k=a[j]-'0';
        if((k-x)<mi)
        {
            mi=k-x;
            cout<<k<<" "<<x;
            cout<<endl;
            minind=j;
        }
    }
    j--;

   swap(&a[i-1],&a[j]);
    sort(a+i,a+n);
}
int main()
{
    char a[]="534976";
    int n=strlen(a);
    nextgreater(a,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
    cout<<a[i];
    }
    return 0;
}
