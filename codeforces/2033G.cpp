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
vi ans;
vi dep;
vi ht;
vector<vpi>binlifts;
map<pi,int>pot;
void depth(int d,int u,int prev){
    dep[u]=d;
    if(sz(g[u])==1&&u)return;
    trav(a,g[u]){
        if(a==prev)continue;
        depth(d+1,a,u);
    }
}
int poten(int u,int prev){
    if(sz(g[u])==1&&u)return 1;
    pqg<int>hp;
    vi tmp;
    int mm=0;
    trav(a,g[u]){
        if(a==prev)continue;
        int tp=poten(a,u);
        mm=max(mm,tp);
        tmp.pb(tp);
        hp.push(tp);
        while(hp.size()>2)hp.pop();
    }
    vi big(2);int i=0;
    while(!hp.empty()){
        big[i]=hp.top();hp.pop();i++;
    }
    i=0;
    trav(a,g[u]){
        if(a==prev)continue;
        if(tmp[i]==big[1])pot[{u,a}]=big[0];
        else pot[{u,a}]=big[1];
        binlifts[a].pb({u,pot[{u,a}]-dep[u]});
        i++;
    }
    ht[u]=mm;
    return mm+1;
}
void binlift(int u,int prev){
    int j=1;
    while(dep[u]>=1<<j){
        int tmp=max(binlifts[u][j-1].s,binlifts[binlifts[u][j-1].f][j-1].s);
        binlifts[u].pb({binlifts[binlifts[u][j-1].f][j-1].f,tmp});
        j++;
    }
    trav(a,g[u]){
        if(a==prev)continue;
        binlift(a,u);
    }
}
int rec(int u,int k){
    int ans=-1000000,n=u;
    F0R(i,18){
        if(k&1<<i){
            ans=max(ans,binlifts[n][i].s);
            n=binlifts[n][i].f;
        }
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    dep=vi(n);ht=vi(n);g=vector<vi>(n);pot=map<pi,int>();
    F0R(_,n-1){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    int root=0;
    depth(0,root,-1);
    binlifts=vector<vpi>(n);
    poten(root,-1);
    binlift(root,-1);
    int q;cin>>q;
    F0R(i,q){
        int v,k;cin>>v>>k;v--;
        cout<<max(ht[v],rec(v,min(dep[v],k))+dep[v])<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}