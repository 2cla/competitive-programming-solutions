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

vl facts;
vl invfacts;
void facts_invfacts(ll n){
    facts=vl(n);invfacts=vl(n);
    facts[0]=1;invfacts[0]=1;
    FOR(i,1,n)facts[i]=(facts[i-1]*i)%mod;
    invfacts[n-1]=pow(facts[n-1],mod-2,mod);
    FORd(i,1,n-1)invfacts[i]=(invfacts[i+1]*(i+1))%mod;
}
ll nCk(ll n,ll k){
    return mul(facts[n],mul(invfacts[n-k],invfacts[k]));
}
void solve(){
    ll n,k;cin>>n>>k;
    str ss;cin>>ss;
    vector<vl>dp(n,vl(k+1));
    F0R(i,n)dp[i][0]=1;
    if(ss[n-1]=='0')dp[n-1][1]=1;
    F0Rd(i,n-1){
        FOR(j,1,k+1){
            FOR(l,(j+(ss[i]=='1'))/2,j+1){
                dp[i][j]=add(dp[i][j],mul(nCk(j-(j+(ss[i]=='1'))/2,l-(j+(ss[i]=='1'))/2),dp[i+1][l]));
            }
        }
    }
    cout<<dp[0][k]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    facts_invfacts(505);
    cin>>t;
    while(t--)solve();
    return 0;
}