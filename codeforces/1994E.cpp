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

vector<vi>g;
int rec(int u,vi&l){
    if(!sz(g[u])){
        l.pb(1);return 1;
    }
    int w=1;
    trav(a,g[u]){
        w+=rec(a,l);
    }
    l.pb(w);return w;
}
void solve(){
    int k;cin>>k;
    vector<vi>wwl(k);vpi ww(k);
    F0R(i,k){
        g=vector<vi>();
        int n;cin>>n;
        F0R(j,n-1){
            int p;cin>>p;
            g[--p].pb(i+1);
        }
        ww.pb({rec(0,wwl[i]),i});
    }
    sort(all(ww),greater<pi>());
    int ans=ww[0].f,k=31-clz(ans),kk=k;
    FOR(j,1,k){
        int tmp=ww[j].f;
        while(1){
            while(k>=0&&1<<k&ans)k--;
            if(tmp>=1<<(k+1)){
                cout<<((1<<(kk+1))-1)<<'\n';return;
            }
            sort(all(wwl[ww[j].s]),greater<int>());
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