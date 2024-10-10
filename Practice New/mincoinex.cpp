#include<bits/stdc++.h>
using namespace std;
int mincoin(int *a,int val,int n)
{
    //cout<<"Val = "<<val<<" Size = "<<n<<endl;
    if(val==0){return 0;}
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;

    ans1=min(ans1,mincoin(a+1,val,n-1));
    if(a[0] <= val)
        ans2=min(ans2,1+mincoin(a,val-a[0],n));

    /*if(ans1 == -1)
        return ans2;
    if(ans2 == -1)
       return ans1;*/
    return min(ans1,ans2);
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
    cout<<mincoin(a,11,n);
    return 0;
}
