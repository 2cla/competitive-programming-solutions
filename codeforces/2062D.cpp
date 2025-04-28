// I AM A PURE
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=(b)-1;i>=a;i--)
#define F0Rd(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for(auto& a:x)
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define prt(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz
#define pct __builtin_popcount
#define YES cout<<"yes\n"
#define NO cout<<"no\n"

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}

vl lrr,rrr;
vector<vl>g;
pl rec(ll u,ll p){
    if(sz(g[u])==1&&u){
        return {lrr[u],0};
    }
    ll tt=0,mm=0;
    vpl ww;
    trav(a,g[u]){
        if(a==p)continue;
        pl gg=rec(a,u);
        tt+=gg.s;ww.pb(gg);
    }
    trav(a,ww){
        mm=max(mm,tt-a.s+a.f);
    }
    if(mm<=rrr[u]+tt){
        return{max(mm,lrr[u]+tt),tt};
    }
    pl ans={rrr[u]+tt,tt};
    trav(a,ww){
        ans.f+=max(0ll,tt-a.s+a.f-rrr[u]-tt);
        ans.s+=max(0ll,tt-a.s+a.f-rrr[u]-tt);
    }
    return ans;
}
void solve(){
    ll n;cin>>n;
    lrr=vl(n);rrr=vl(n);
    F0R(i,n){
        ll l,r;cin>>l>>r;
        lrr[i]=l;rrr[i]=r;
    }
    g=vector<vl>(n);
    F0R(i,n-1){
        ll u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    cout<<rec(0,-1).f<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}