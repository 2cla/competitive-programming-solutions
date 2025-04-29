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
vl ppp,ppp2;
void solve(){
    ll n;cin>>n;
    vl arr(n);F0R(i,n)cin>>arr[i];
    vl brr=arr;
    sort(all(brr),greater<ll>());
    vl crr(n+1);
    FOR(i,1,n+1){
        crr[i]+=brr[i-1]+crr[i-1];
    }
    ll lo=0,hi=n;
    while(lo<hi){
        ll mid=(lo+hi)/2;
        ll ww=crr[n-mid];
        ll gg=ppp2[n-mid];
        if(ww>=gg)hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    int N=6e6;
    vi pp(N+1,1);
    FOR(i,2,N){
        if(!pp[i])continue;
        int j=2;
        while(i*j<=N){
            pp[i*j]=0;j++;
        }
    }
    FOR(i,2,N){
        if(pp[i])ppp.pb(i);
    }
    ppp2=vl(sz(ppp)+1);
    FOR(i,1,sz(ppp)+1){
        ppp2[i]+=ppp2[i-1]+ppp[i-1];
    }
    cin>>t;
    while(t--)solve();
    return 0;
}