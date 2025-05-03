// I AM A PURE
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct tnode {
    int ed[2];
    int cnt;
    tnode() {
        ed[0]=ed[1]=-1;
        cnt = 0;
    }
};
vector<tnode>ee,oo;
void tinsert(int ss,vector<tnode>&tt){
    int idx=0;
    tt[idx].cnt++;
    F0Rd(i,30){
        int e=(ss>>i)&1;
        if(tt[idx].ed[e]==-1){
            tt[idx].ed[e]=sz(tt);
            tt.pb(tnode());
        }
        idx=tt[idx].ed[e];
        tt[idx].cnt++;
    }
}
void tremove(int ss,vector<tnode>&tt){
    int idx=0;
    tt[idx].cnt--;
    F0Rd(i,30){
        int e=(ss>>i)&1;
        idx=tt[idx].ed[e];
        tt[idx].cnt--;
    }
}
int s2(int ss,vector<tnode>&tt){
    tnode al=tt[0];
    int ans=0;
    F0Rd(i,30){
        if(al.ed[ss>>i&1]!=-1&&tt[al.ed[ss>>i&1]].cnt){
            ans|=(ss>>i&1)<<i;
            al=tt[al.ed[ss>>i&1]];
        }else{
            ans|=((ss>>i&1)^1)<<i;
            al=tt[al.ed[(ss>>i&1)^1]];
        }
    }
    return ans;
}
vector<vi>g;
map<pi,int>ww;
vi xx,dd;
void rec(int u,int p,int d){
    if(u)xx[u]=xx[p]^ww[{u,p}];
    dd[u]=d;
    if(d&1)tinsert(xx[u],oo);
    else tinsert(xx[u],ee);
    trav(a,g[u]){
        if(a==p)continue;
        rec(a,u,d+1);
    }
}
void solve(){
    int n,m;cin>>n>>m;
    g=vector<vi>(n);
    ww=map<pi,int>();
    xx=vi(n);dd=vi(n);
    F0R(i,n-1){
        int u,v,w;cin>>u>>v>>w;u--;v--;
        g[u].pb(v);g[v].pb(u);
        ww[{u,v}]=w;ww[{v,u}]=w;
    }
    int ff=0;
    ee=vector<tnode>(1),oo=vector<tnode>(1);
    rec(0,-1,0);
    F0R(_,m){
        char ss;cin>>ss;
        if(ss=='^'){
            int y;cin>>y;
            ff^=y;
        }else{
            int v,x;cin>>v>>x;v--;
            int hh=x^xx[v];
            if(dd[v]&1)hh^=ff;
            int ans=0,tmp=0;
            if(dd[v]&1)tremove(xx[v],oo);
            else tremove(xx[v],ee);
            if(ee[0].cnt){
                tmp=s2(((1<<30)-1)^hh,ee);
                ans=max(ans,tmp^hh);
            }
            if(oo[0].cnt){
                tmp=s2(((1<<30)-1)^hh^ff,oo);
                ans=max(ans,tmp^hh^ff);
            }
            cout<<ans<<' ';
            if(dd[v]&1)tinsert(xx[v],oo);
            else tinsert(xx[v],ee);
        }
    }cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}