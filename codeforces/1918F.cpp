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

vector<vi>g;
pq<int>cc;
int rec(int u,int d){
    if(!sz(g[u]))return 0;
    pq<int>dd;
    trav(a,g[u]){
        dd.push(1+rec(a,d+1));
    }
    int mm=dd.top();dd.pop();
    while(!dd.empty()&&dd.top()>d){
        cc.push(dd.top()-d);dd.pop();
    }
    return mm;
}
void solve(){
    int n,k;cin>>n>>k;
    g=vector<vi>(n);cc=pq<int>();
    F0R(i,n-1){
        int w;cin>>w;w--;
        g[w].pb(i+1);
    }
    int ans=2*(n-1)-rec(0,0);
    while(!cc.empty()&&k){
        ans-=cc.top();cc.pop();k--;
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}