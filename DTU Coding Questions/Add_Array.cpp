#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }

    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    int b=max(n1,n2);
    int a[b+1];
    int k=0,carry=0;
    int i=n1-1,j=n2-1;
    while(i>=0 && j>=0)
    {
        int h=arr1[i]+arr2[j]+carry;
        a[k]=h%10;
        carry=h/10;
        k++;
        i--;
        j--;
    }
    while(i>=0)
    {
        int h=arr1[i]+carry;
        a[k]=h%10;
        carry=h/10;
        k++;
        i--;
    }
    while(j>=0)
    {
        int h=arr2[j]+carry;
        a[k]=h%10;
        carry=h/10;
        k++;
        j--;
    }
    while(carry>0)
    {
        a[k]=carry%10;
        k++;
        carry=carry/10;
    }

    for(int l=k-1;l>=0;l--)
    {

        cout<<a[l];
    }
    return 0;
}
