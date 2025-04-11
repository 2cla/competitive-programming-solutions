#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;

typedef unordered_map<int,int> umi;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz
ll n,ans;
vector<vl>g;
vl arr;
vl rec(ll u,ll p){
    vl tt(n+2);
    if(sz(g[u])==1&&u){
        tt[0]=1e14;return tt;
    }
    ll tot=0;
    trav(a,g[u]){
        if(a==p)continue;
        tot+=arr[a];
        vl ww=rec(a,u);
        F0R(i,n+1)tt[i+1]+=ww[i];
    }
    ll ii=1;
    while(arr[u]>tot){
        if(arr[u]-tot<=tt[ii]){
            tt[ii]-=arr[u]-tot;ans+=ii*(arr[u]-tot);tot=arr[u];
        }else{
            tot+=tt[ii];ans+=ii*tt[ii];tt[ii]=0;ii++;
        }
    }
    tt[0]+=tot-arr[u];
    return tt;
}
void solve(){
    cin>>n;
    arr=vl(n);F0R(i,n)cin>>arr[i];
    ans=0;
    g=vector<vl>(n);
    F0R(i,n-1){
        ll w;cin>>w;w--;
        g[w].pb(i+1);g[i+1].pb(w);
    }
    rec(0,-1);
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}