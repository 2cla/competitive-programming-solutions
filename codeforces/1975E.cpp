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

vl cols,prevs,bcs;
vector<vl>g;
set<ll>bcn;
void rec(ll u,ll p){
    prevs[u]=p;
    if(p!=-1&&cols[u])bcs[p]++;
    trav(a,g[u]){
        if(a==p)continue;
        rec(a,u);
    }
}
void solve(){
    ll n,q;cin>>n>>q;
    cols=vl(n+1);prevs=vl(n+1);
    FOR(i,1,n+1)cin>>cols[i];
    g=vector<vl>(n+1);
    g[0].pb(1);g[1].pb(0);
    F0R(i,n-1){
        ll u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    bcs=vl(n+1);
    bcn=set<ll>();
    rec(0,-1);
    ll wc=0,bc=0,wc2=0,bc2=0;
    F0R(i,n+1){
        if(cols[i]){
            if(bcs[i]==2){
                bc++;bcn.ins(i);
            }else if(bcs[i]>2)bc2++;
        }else{
            if(bcs[i]==1)wc++;
            else if(bcs[i]>1)wc2++;
        }
    }
    F0R(i,q){
        ll u;cin>>u;
        if(cols[prevs[u]]){
            if(bcs[prevs[u]]>2)bc2--;
            if(bcs[prevs[u]]==2){
                bc--;bcn.erase(prevs[u]);
            }
        }else{
            if(bcs[prevs[u]]>1)wc2--;
            if(bcs[prevs[u]]==1)wc--;
        }
        if(cols[u]){
            if(bcs[u]>2)bc2--;
            if(bcs[u]==2){
                bc--;bcn.erase(u);
            }
            if(bcs[u]>1)wc2++;
            if(bcs[u]==1)wc++;
        }else{
            if(bcs[u]>2)bc2++;
            if(bcs[u]==2){
                bc++;bcn.ins(u);
            }
            if(bcs[u]>1)wc2--;
            if(bcs[u]==1)wc--;
        }
        if(cols[u])bcs[prevs[u]]--;
        else bcs[prevs[u]]++;
        if(cols[prevs[u]]){
            if(bcs[prevs[u]]>2)bc2++;
            if(bcs[prevs[u]]==2){
                bc++;bcn.ins(prevs[u]);
            }
        }else{
            if(bcs[prevs[u]]>1)wc2++;
            if(bcs[prevs[u]]==1)wc++;
        }
        cols[u]^=1;
        if(!(wc2+bc2)&&wc==1&&bc<=1){
            if(bc==1){
                ll tt=*bcn.begin();
                if(cols[prevs[tt]])cout<<"no\n";
                else cout<<"yes\n";
            }else cout<<"yes\n";
        }else cout<<"no\n";
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