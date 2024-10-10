
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll>> matrix;
typedef vector<ll> arr;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> pv;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
ll par[10000];
struct edge{
    ll s,e,w;
};
ll find(ll x){
    while(par[x]>0){
        x=par[x];
    }
    return x;
}
void merge(ll a,ll b){
    par[a]+=par[b];
    par[b]=a;
}
int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    vector<edge>a;
    while(m--){
        edge x;
        cin>>x.s>>x.e>>x.w;
        a.pb(x);
    }
    sort(all(a),[](edge x,edge y){
       return x.w<y.w;
    });
    ll sum=0;
    for(int i=1;i<=n;i++) par[i]=-1;
    for(auto i : a){
        ll x=find(i.s);
        ll y=find(i.e);
        if(x!=y){
           // cout<<i.s<<" "<<i.e<<endl;
            merge(x,y);
            sum+=i.w;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<par[i]<<" ";
    }
    cout<<sum<<endl;
    return 0;
}
