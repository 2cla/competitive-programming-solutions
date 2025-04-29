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

void solve(){
    ll n,k;cin>>n>>k;
    str ss;cin>>ss;
    vector<vl>dp(k,vl(n));
    F0R(i,n){
        dp[ss[i]-97][i]=1;
    }
    vl tt(k,n);
    F0Rd(i,n){
        F0R(j,k){
            dp[j][i]=tt[j];
        }
        tt[ss[i]-97]=i;
    }
    vl dpp(n+1);
    F0Rd(i,n){
        ll ww=1e9;
        F0R(j,k){
            ww=min(ww,dpp[dp[j][i]]);
        }
        dpp[i]=ww+1;
    }
    debug(dpp);
    ll q;cin>>q;
    F0R(_,q){
        str qq;cin>>qq;
        ll p1=0,p2=0;
        while(p1<sz(qq)&&p2<n){
            if(qq[p1]==ss[p2])p1++;
            p2++;
        }
        if(p1<sz(qq)){
            cout<<"0\n";continue;
        }
        if(p2==n){
            cout<<"1\n";continue;
        }
        cout<<dpp[p2-1]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}