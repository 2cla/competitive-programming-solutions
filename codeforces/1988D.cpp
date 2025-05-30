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

vector<vl>g;
vl arr;
vl rec(int u,int p){
    vl tt(sz(g[u])+1);
    F0R(i,sz(tt))tt[i]=(i+1)*arr[u];
    ll ww=0;
    trav(a,g[u]){
        if(a==p)continue;
        vl tmp=rec(a,u);
        pq<pl>hp;
        F0R(i,sz(tmp)){
            hp.push({tmp[i],i});
            if(hp.size()>2)hp.pop();
        }
        pl aa=hp.top();hp.pop();
        if(hp.top().s<sz(tt)){
            tt[hp.top().s]-=hp.top().f;
            tt[hp.top().s]+=aa.f;
        }
        ww+=hp.top().f;
    }
    F0R(i,sz(tt))tt[i]+=ww;
    return tt;
}
void solve(){
    ll n;cin>>n;
    arr=vl(n);F0R(i,n)cin>>arr[i];
    g=vector<vl>(n);
    F0R(i,n-1){
        ll x,y;cin>>x>>y;x--;y--;
        g[x].pb(y);g[y].pb(x);
    }
    vl ans=rec(0,-1);
    cout<<*min_element(all(ans))<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}