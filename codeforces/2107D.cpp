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
vl vis,bk;
tuple<ll,ll,ll,ll>tt;
deque<ll>heads;
pq<tuple<ll,ll,ll>>qq;
pl build(ll u,ll p){
    bk[u]=p;
    pqg<pl>hp;
    trav(a,g[u]){
        if(a==p||vis[a])continue;
        pl ww=build(a,u);
        hp.push({ww.f,ww.s});
        if(sz(hp)>2)hp.pop();
    }
    if(!sz(hp)){
        tuple<ll,ll,ll,ll>tmp={1,u,u,u};
        if(tmp>tt)tt=tmp;
        return {1,u};
    }
    if(sz(hp)==1){
        pl ww=hp.top();
        tuple<ll,ll,ll,ll>tmp={ww.f+1,max(u,ww.s),min(u,ww.s),u};
        if(tmp>tt)tt=tmp;
    }else{
        pl ww1=hp.top();hp.pop();
        pl ww2=hp.top();
        tuple<ll,ll,ll,ll>tmp={ww1.f+ww2.f+1,max(ww1.s,ww2.s),min(ww1.s,ww2.s),u};
        if(tmp>tt)tt=tmp;
    }
    return {hp.top().f+1,hp.top().s};
}
void mark(ll u,ll ss){
    vis[u]=1;
    trav(a,g[u]){
        if(vis[a]||(u!=ss&&a==bk[u]))continue;
        heads.pb(a);
    }
    if(u!=ss)mark(bk[u],ss);
}
void solve(){
    ll n;cin>>n;
    if(n==1){
        cout<<"1 1 1\n";return;
    }
    g=vector<vl>(n);
    heads=deque<ll>();
    bk=vl(n),vis=vl(n);
    F0R(i,n-1){
        ll u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    heads.pb(0);
    pq<tuple<ll,ll,ll,ll>>qq;
    vl ans;
    while(sz(heads)){
        ll hh=heads.front();
        tt={0,0,0,0};
        if(!vis[hh])build(hh,-1);
        heads.pop_front();
        if(!get<0>(tt))continue;
        qq.push(tt);
        
        mark(get<1>(tt),get<3>(tt));
        mark(get<2>(tt),get<3>(tt));
    }
    while(sz(qq)){
        tt=qq.top();
        ans.pb(get<0>(tt));ans.pb(1+get<1>(tt));ans.pb(1+get<2>(tt));qq.pop();
    }
    prt(ans)
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}