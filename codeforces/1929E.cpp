// I AM A PURE
#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
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
#define dbg debug

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vi>g;
map<int,vi>kk;
vi ww,jj,dp2;
int k;
vi rec(int u,int p){
    vi tt(k);
    trav(a,g[u]){
        if(a==p)continue;
        vi tt2=rec(a,u);
        F0R(i,k){
            tt[i]+=tt2[i];
        }
    }
    trav(a,kk[u])tt[a]++;
    int mm=0;
    F0R(i,k){
        if(tt[i]&1)mm|=1<<i;
    }
    ww[mm]=1;
    return tt;
}
void solve(){
    int n;cin>>n;
    g=vector<vi>(n);
    F0R(i,n-1){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    cin>>k;
    kk=map<int,vi>();
    F0R(i,k){
        int a,b;cin>>a>>b;a--;b--;
        kk[a].pb(i);kk[b].pb(i);
    }
    ww=vi(1<<k);
    dp2=vi(1<<k);
    jj=vi();
    rec(0,-1);
    F0R(i,1<<k){
        if(ww[i])jj.pb(i);
    }
    debug(jj);
    deque<pi>qq;qq.pb({0,0});
    while(!qq.empty()){
        auto[x,y]=qq.front();
        if(dp2[x]){
            qq.pop_front();continue;
        }
        if(x==(1<<k)-1){
            cout<<y<<'\n';return;
        }
        dp2[x]=1;
        trav(a,jj){
            qq.pb({x|a,y+1});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}