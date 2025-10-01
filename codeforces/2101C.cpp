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

ll n;
vl arr;
vector<vl>idxl;
ll bty(ll c){
    ll tt=c,sc=0;
    ll l=0,r=n-1;
    pq<ll>lq,rq;
    vl vis(n);
    F0R(i,n){
        if(arr[i]>=c){
            lq.push(-i);rq.push(i);
        }
    }
    while(1){
        if(!tt)return sc;
        if(!sz(lq)||!sz(rq)){
            tt--;
            trav(a,idxl[tt]){
                lq.push(-a);rq.push(a);
            }
            continue;
        }
        ll x1=lq.top();
        ll x2=rq.top();
        if(vis[-x1]){
            lq.pop();continue;
        }
        if(vis[x2]){
            rq.pop();continue;
        }
        sc+=x2+x1;
        vis[x2]=1;vis[-x1]=1;
        lq.pop();rq.pop();
        tt--;
        trav(a,idxl[tt]){
            lq.push(-a);rq.push(a);
        }
    }
}
void solve(){
    cin>>n;
    arr=vl(n);F0R(i,n)cin>>arr[i];
    idxl=vector<vl>(n+1);
    F0R(i,n){
        idxl[arr[i]].pb(i);
    }
    ll lo=1,hi=n;
    while(hi-lo>3){
        ll t1=lo+(hi-lo)/3,t2=hi-(hi-lo)/3;
        if(bty(t1)<bty(t2))lo=t1;
        else hi=t2;
    }
    ll ans=0;
    FOR(i,lo,hi+1){
        ans=max(ans,bty(i));
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}