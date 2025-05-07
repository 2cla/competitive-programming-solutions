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

vector<vl>g;
vl ww,tt,ss;
ll rec(ll u,ll p,ll l){
    ll aa=0;
    if(g[u][0]!=-1)aa+=rec(g[u][0],u,l);
    if(ww[u]!=-1){
        tt[l+aa]=ww[u];
        ss.pb(l+aa);
    }
    if(g[u][1]!=-1)aa+=rec(g[u][1],u,l+aa+1);
    return aa+1;
}
void solve(){
    ll n,c;cin>>n>>c;
    g=vector<vl>(n,vl(2,-1));
    ww=vl(n);
    ss=vl();ss.pb(0);ss.pb(n+1);
    tt=vl(n+2);tt[0]=1;tt[n+1]=c;
    F0R(i,n){
        ll u,v,w;cin>>u>>v>>w;u--;v--;
        if(u!=-2)g[i][0]=u;
        if(v!=-2)g[i][1]=v;
        ww[i]=w;
    }
    rec(0,-1,1);
    ll ans=1;
    sort(all(ss));
    F0R(i,sz(ss)){
        if(!i)continue;
        ll tm=1,nn=tt[ss[i]]-tt[ss[i-1]]+ss[i]-ss[i-1]-1,kk=ss[i]-ss[i-1]-1;
        F0R(j,kk){
            tm=mul(tm,nn);
            tm=mul(tm,inv(j+1));
            nn--;
        }
        ans=mul(ans,tm);
    }cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}