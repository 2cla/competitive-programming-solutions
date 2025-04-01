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

vector<vl>g;
ll n,c;
void rec(ll u,ll p,vl&dp1,vl&dp2,vl&arr){
    if(sz(g[u])==1&&u){
        dp2[u]=arr[u];return;
    }
    vpl tmp;
    ll dd=0;
    trav(a,g[u]){
        if(a==p)continue;
        rec(a,u,dp1,dp2,arr);
        tmp.pb({dp2[a]-dp1[a],a});
        dd+=dp1[a];
    }
    sort(all(tmp),greater<pl>());
    ll tot=0,k=0;
    dp2[u]=arr[u]+dd;
    trav(a,tmp){
        k++;
        tot+=a.f;
        dp1[u]+=max({0ll,dp2[a.s],dp1[a.s]});
        dp2[u]=max(dp2[u],arr[u]-2*k*c+dd+tot);
    }
}
void solve(){
    cin>>n>>c;
    vl arr(n);F0R(i,n)cin>>arr[i];
    g=vector<vl>(n);
    F0R(i,n-1){
        ll u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    vl dp1(n),dp2(n);
    rec(0,-1,dp1,dp2,arr);
    cout<<max(dp1[0],dp2[0])<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}