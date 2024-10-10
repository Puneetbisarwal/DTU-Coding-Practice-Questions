#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;
    cin>>n>>p;
    int times=0;
    float ans=0;
    float inc=1;
    while(times<=p)
    {
        while(ans*ans<=n)
        {
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
        times++;
    }
    cout<<ans<<endl;
    printf("%.6f",ans);
    return 0;
}
