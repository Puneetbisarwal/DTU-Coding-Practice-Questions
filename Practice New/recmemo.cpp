#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int fibom(int n,int *out)
{
    if(n==0||n==1)
    {
        out[n]=n;
        return out[n];
    }
    if(out[n]>0)
    {
        return out[n];
    }
    out[n]=fibom(n-1,out)+fibom(n-2,out);
    return out[n];
}
int fibom(int n)
{
    int storage[n+1];
    memset(storage,-1,sizeof(storage));
    return fibom(n,storage);
}
int fibodp(int n)
{
    int out[n+1];
    out[0]=0;
    out[1]=1;
    for(int i=2;i<=n;i++)
    {
        out[i]=out[i-1]+out[i-2];
    }
    return out[n];
}
int reach1(int n)
{
    if(n==1)
    {
        return 0;
    }
    int min=reach1(n-1);
    int min1,min2;
    if(n%2==0)
    {
        min1=reach1(n/2);
        if(min>min1)
        {
            min=min1;
        }
    }
    if(n%3==0)
    {
        min2=reach1(n/3);
        if(min>min2)
        {
            min=min2;
        }
    }
    return min+1;
}
int reach1M(int n,int *out)
{
    if(n==1)
    {
        out[n]=0;
    }
    if(out[n]!=-1)
    {
        return out[n];
    }
    int min,min1,min2;
    min=reach1M(n-1,out);
    if(n%2==0)
    {
       min1=reach1M(n/2,out);
       if(min>min1)
       {
           min=min1;
       }
    }
    if(n%3==0)
    {
       min2=reach1M(n/3,out);
       if(min>min2)
       {
           min=min2;
       }
    }
    out[n]=1+min;
    return out[n];
}
int reach1M(int n)
{
    int out[n+1];
    memset(out,-1,sizeof(out));
    return reach1M(n,out);
}
int reach1Dp(int n)
{
    int out[n+1];
    out[1]=0;
    int min;
    for(int i=2;i<=n;i++)
    {
        min=out[n-1];
        if(i%2==0)
        {
            if(min>out[i/2])
            {
                min=out[i/2];
            }
        }
        if(i%3==0)
        {
            if(min>out[i/3])
            {
                min=out[i/3];
            }
        }
        out[i]=min+1;
    }
    return out[n];
}
int staircase(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    if(n==3)
    {
        return 4;
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
int staircaseM(int n,int *out)
{
    if(n==0)
    {
        out[0]=0;
    }
    if(n==1)
    {
        out[1]=1;
    }
    if(n==2)
    {
        out[2]=2;
    }
    if(n==3)
    {
        out[3]=4;
    }
    if(out[n]!=-1)
    {
        return out[n];
    }
    out[n]=staircaseM(n-1,out)+staircaseM(n-2,out)+staircaseM(n-3,out);
    return out[n];
}
int staircaseM(int n)
{
    int out[n+1];
    memset(out,-1,sizeof(out));
    staircaseM(n,out);
}
int staircaseDp(int n)
{
    int out[n+1];
    out[0]=0;
    out[1]=1;
    out[2]=2;
    out[3]=4;
    for(int i=4;i<=n;i++)
    {
        out[i]=out[i-1]+out[i-2]+out[i-3];
    }
    return out[n];
}
int coinex(int n)
{
    if(n<=3)
    {
        return n;
    }
    int ans=coinex(n/2)+coinex(n/3)+coinex(n/4);
    return max(ans,n);
}
int coinexM(int n,int *out)
{
    if(n<=3)
    {
        out[n]=n;
    }
    if(out[n]!=-1)
    {
        return out[n];
    }
    int ans= coinexM(n/2)+coinexM(n/3)+coinexM(n/4);
    out[n]=max(ans,n);
    return out[n];
}
int coinexM(int n)
{
    int out[n+1];
    memset(out,-1,sizeof(out));
    return coinexM(n,out);
}
int coinexDp(int n)
{
    int out[n+1];
    out[0]=0;
    out[1]=1;
    out[2]=2;
    out[3]=3;
    int ans;
    for(int i=0;i<=n;i++)
    {
        ans=out[i/2]+out[i/3]+out[i/4];
        out[i]=max(i,ans);
    }
    return out[n];
}
int minnotosq(int n)
{
    if(n<=3)
    {
        return n;
    }
    int min=INT_MAX,ans;
    for(int i=1;i*i<=n;i++)
    {
        ans=i*i+minnotosq(n-i*i);
        if(ans<min)
        {
            min=ans;
        }
    }
    return min;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<"fibom "<<fibom(n)<<endl;
    cout<<"fibodp "<<fibodp(n)<<endl;
    cout<<"fibo "<<fibo(n)<<endl;
    cout<<"reach1Dp "<<reach1Dp(n)<<endl;
    cout<<"reach1M "<<reach1M(n)<<endl;
    cout<<"reach1 "<<reach1(n)<<endl;
    cout<<"staircaseDp "<<staircaseDp(n)<<endl;
    cout<<"staircaseM "<<staircaseM(n)<<endl;
    cout<<"staircase "<<staircase(n)<<endl;
    cout<<"coinexDp "<<coinexDp(n)<<endl;
    cout<<"coineM "<<coinexM(n)<<endl;
    cout<<"coinex "<<coinex(n)<<endl;
    cout<<"mintosqno "<<minnotosq(n)<<endl;
    return 0;
}
