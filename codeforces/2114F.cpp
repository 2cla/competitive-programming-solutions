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

vl factors(ll n){
    ll m=1;
    vl facts;
    while(m*m<n){
        if(!(n%m)){
            facts.pb(m);facts.pb(n/m);
        }
        m++;
    }
    if(m*m==n)facts.pb(m);
    return facts;
}
ll s2(ll n,ll k){
    vl ff=factors(n);
    vl ff2;
    trav(a,ff){
        if(a<=k)ff2.pb(a);
    }
    set<ll>vis;
    deque<pl>qq;qq.pb({n,0});
    while(!qq.empty()){
        auto[x,y]=qq.front();
        qq.pop_front();
        if(x==1)return y;
        if(vis.count(x))continue;
        vis.ins(x);
        trav(a,ff2){
            if(a==1)continue;
            if(!(x%a))qq.pb({x/a,y+1});
        }
    }
    return -1;
}
void solve(){
    ll x,y,k;cin>>x>>y>>k;
    ll gg=gcd(x,y);
    x/=gg;y/=gg;
    ll a1=s2(x,k),a2=s2(y,k);
    if(a1==-1||a2==-1){
        cout<<"-1\n";
    }else cout<<a1+a2<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}