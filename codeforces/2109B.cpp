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
    ll n,m,a,b;cin>>n>>m>>a>>b;
    ll n1=n,m1=m,a1=a,b1=b;
    ll an1=0;
    while(n1>1){
        if(n1-a1+1>a1){
            an1++;n1=a1;
        }else{
            an1++;n1=n1-a1+1;
        }
        a1=(1+n1)/2;
    }
    b1=(m1+1)/2;
    while(m1>1){
        if(m1-b1+1>b1){
            an1++;m1=b1;
        }else{
            an1++;m1=m1-b1+1;
        }
        b1=(1+m1)/2;
    }
    ll n2=n,m2=m,a2=a,b2=b;
    ll an2=0;
    while(m2>1){
        if(m2-b2+1>b2){
            an2++;m2=b2;
        }else{
            an2++;m2=m2-b2+1;
        }
        b2=(1+m2)/2;
    }
    a2=(n2+1)/2;
    while(n2>1){
        if(n2-a2+1>a2){
            an2++;n2=a2;
        }else{
            an2++;n2=n2-a2+1;
        }
        a2=(1+n2)/2;
    }
    cout<<min(an1,an2)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}