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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

vi h;
vector<vi> g;
vi cnts;
ll ans;
void rec(int n,int p){
    if(sz(g[n])==1){
        h[n]=0;return;
    }
    trav(a,g[n]){
        if(a==p)continue;
        rec(a,n);
        h[n]=min(h[n],1+h[a]);
    }
}
vi rec2(int n,int p){
    if(sz(g[n])==1)return vi{1,0,0};
    vi tmp(3);
    bool r=(h[n]==1);
    tmp[h[n]]++;
    trav(a,g[n]){
        if(a==p)continue;
        auto tmp2=rec2(a,n);
        F0R(i,3)tmp[i]+=tmp2[i];
        if(h[a]>0)ans+=1LL*r*(cnts[2]-tmp2[2]);
        if(h[a]==1)ans+=1LL*tmp2[2];
    }
    return tmp;
}
void solve(){
    int n;cin>>n;
    ans=0;cnts=vi(3);
    h=vi(n,2);
    g=vector<vi>(n);
    F0R(i,n-1){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    if(n==2){cout<<"0\n";return;}
    int root=0;
    if(sz(g[0])==1)root=g[0][0];
    rec(root,-1);
    trav(a,h)cnts[a]++;
    ans+=1LL*cnts[0]*(n-cnts[0]);
    rec2(root,-1);
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}