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

vl b1,b2;
vector<vl>dp;
vector<vl>g;
void rec(int u,int p){
    b1[u]=(p==-1)?0:p;
    b2[u]=(p==-1)?0:b1[p];
    if(sz(g[u])==1&&u)return;
    trav(a,g[u]){
        if(a==p)continue;
        rec(a,u);
    }
}
void rec2(int i,int u,int p){
    if(u){
        if(i>0)dp[i][u]=2+dp[i-1][b2[u]]-(!p);
        dp[i][u]=min(dp[i][u],2*sz(g[u])+dp[i][b2[u]]-(!p));
    }
    if(sz(g[u])==1&&u)return;
    trav(a,g[u]){
        if(a==p)continue;
        rec2(i,a,u);
    }
}
void solve(){
    ll n,q;cin>>n>>q;
    g=vector<vl>(n);
    F0R(i,n-1){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    b1=vl(n);b2=vl(n);dp=vector<vl>(n+1,vl(n,1e10));
    F0R(i,n+1)dp[i][0]=0;
    rec(0,-1);
    F0R(i,n+1)rec2(i,0,-1);
    F0R(i,q){
        int v,p;cin>>v>>p;v--;
        cout<<1+dp[p][b1[v]]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}