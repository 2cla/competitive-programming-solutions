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
#define clz __builtin_clzll
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

vector<vector<vl>>dp(61,vector<vl>(61,vl(61,2e18)));
vector<vl>dp2(61,vl(61,2e18));
void rec(){
    dp[0][0][0]=0;
    FOR(i,1,61){
        F0R(j,61){
            F0R(k,61){
                if(j+i<=60)dp[i][j+i][k]=min(dp[i][j+i][k],dp[i-1][j][k]+(1ll<<i));
                if(k+i<=60)dp[i][j][k+i]=min(dp[i][j][k+i],dp[i-1][j][k]+(1ll<<i));
                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
            }
        }
    }
}
void solve(){
    ll x,y;cin>>x>>y;
    ll ans=2e18;
    F0R(i,61){
        F0R(j,61){
            if((x>>i)==(y>>j))ans=min(ans,dp2[i][j]);
        }
    }cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    rec();
    F0R(k,61){
        F0R(j,61){
            F0R(i,61){
                dp2[j][k]=min(dp2[j][k],dp[i][j][k]);
            }
        }
    }
    cin>>t;
    while(t--)solve();
    return 0;
}