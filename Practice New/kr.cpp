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
ll par[100];
ll find(ll x){
    arr d;
    while(par[x]>0){
        d.pb(x);
        x=par[x];
    }
    for(auto i : d) par[i]=x;
    return x;
}
void merge(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x!=y){
        par[x]+=par[y];
        par[y]=x;
    }
}
int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=-1;
    while(m--){
        ll x,y;
        cin>>x>>y;
        merge(x,y);
    }
    for(int i=1;i<=n;i++) cout<<par[i]<<" ";

    return 0;
}
