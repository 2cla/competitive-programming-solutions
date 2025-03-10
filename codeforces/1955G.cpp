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
typedef vector<bool> vb;
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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

vector<vi> a;
vector<vb> vis;
vl factors(int n) {
    vl fl;
    int p=1;
    while(p*p<=n){
        if(!(n%p)){
            fl.pb(p);fl.pb(n/p);
        }
        p++;
    }
    return fl;
}
bool dfs(int i,int j,int t){
    int n=a.size(),m=a[0].size();
    if(i==n||j==m||vis[i][j])return false;
    vis[i][j]=true;
    if(a[i][j]%t)return false;
    if(i==n-1&&j==m-1)return true;
    return (dfs(i+1,j,t)||dfs(i,j+1,t));
}
void solve(){
    int n,m;cin>>n>>m;
    a=vector<vi>(n,vi(m,0));
    F0R(i,n)F0R(j,m)cin>>a[i][j];
    int g=gcd(a[0][0],a.back().back());
    if(g==1){
        cout<<1<<'\n';return;
    }
    vis=vector<vb>(n,vb(m,0));
    vl fa=factors(g);
    ll ans=1;
    trav(aa,fa){
        trav(a,vis){
            fill(all(a),false);
        }
        if(dfs(0,0,aa)){
            ans=max(ans,aa);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}