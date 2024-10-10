#include<bits/stdc++.h>
using namespace std;
int KnapSack(int *weight , int * value ,int n,int i,int maxweight)
{
    if(i==n || maxweight==0)
    {
        return 0;
    }
    if(weight[i]>maxweight)
    {
        KnapSack(weight,value,n,i+1,maxweight);
    }
    else
    {
        int ans1=value[i]+KnapSack(weight,value,n,i+1,maxweight-weight[i]);
        int ans2=KnapSack(weight,value,n,i+1,maxweight);
        return max(ans1,ans2);
    }
}
/*int KnapSackM(int *weight ,int *value ,int n ,int i,int j , int maxWeight ,int *ans)
{
    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }
    if(maxWeight==0 || i==n || j==0)
    {
        ans[i][j]=0;
        return ans[i][j];
    }
    if(weight[i]>maxWeight)
    {

    }
    return ans[n];
}*/
/*int KnapSackDp(int *weight , int * value , int n ,int maxWeight)
{
    int ans[n+1]=0;
    for(int i=0;i<=n;i++)
    {
        if(weight[i]>maxWeight)
        {
            ans[i]=ans[i-1];
        }
        else
        {
            ans[i]=max(value)
        }
    }
}*/
/*int KnapSackM(int *weight,int *value,int n,int maxWeight)
{
    int ans[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            ans[i][j]=-1;
        }
    }
    return KnapSackM(weight,value,n,0,0,maxWeight,ans);
}*/
int KnapSackDp1(int *weight , int * value , int n ,int maxWeight)
{
    int *pre=new int[maxWeight+1];
    int *curr=new int[maxWeight+1];
    for(int i=0;i<=maxWeight;i++)
    {
        pre[i]=0;
        curr[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            if(weight[i-1]<=j)
            {
                curr[j]=max(value[i-1]+pre[j-weight[i-1]],pre[j]);
            }
            else
            {
                curr[j]=pre[j];
            }
        }
        pre=curr;
        curr=new int[maxWeight];

    }
    return curr[maxWeight];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int weight[n],value[n];
    cout<<"Enter 1st Weight and then it's corresponding value "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i];
    }
    int maxweight;
    cin>>maxweight;
    cout<<KnapSackDp1(weight,value,n,maxweight)<<endl;
    cout<<KnapSack(weight,value,n,0,maxweight);
    return 0;
}
