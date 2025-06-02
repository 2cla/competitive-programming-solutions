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

void solve(){
    ll n,m,l;cin>>n>>m>>l;
    vl arr(l);F0R(i,l)cin>>arr[i];
    vector<vl>g(n);
    F0R(i,m){
        ll u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    vl evis(n,-1),ovis(n,-1);
    deque<pl>qq;qq.pb({0,0});
    while(!qq.empty()){
        auto[x,y]=qq.front();qq.pop_front();
        if(y&1){
            if(ovis[x]!=-1)continue;
            ovis[x]=y;
        }else{
            if(evis[x]!=-1)continue;
            evis[x]=y;
        }
        trav(a,g[x]){
            qq.pb({a,y+1});
        }
    }
    sort(all(arr));
    ll tt=accumulate(all(arr),0ll);
    ll t2=-1;
    if(tt&1){
        trav(a,arr){
            if(a&1){
                t2=tt-a;break;
            }
        }
    }else{
        trav(a,arr){
            if(a&1){
                t2=tt-a;break;
            }
        }
    }
    debug(tt,t2);
    debug(ovis,evis);
    F0R(i,n){
        if(tt&1){
            if(ovis[i]>=0&&ovis[i]<=tt){
                cout<<"1";continue;
            }
            if(t2!=-1&&evis[i]>=0&&evis[i]<=t2){
                cout<<"1";continue;
            }
        }else{
            if(t2!=-1&&ovis[i]>=0&&ovis[i]<=t2){
                cout<<"1";continue;
            }
            if(evis[i]>=0&&evis[i]<=tt){
                cout<<"1";continue;
            }
        }cout<<"0";
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