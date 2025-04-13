#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;

typedef unordered_map<int,int> umi;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz

const ll N=2e3+5;
const ll MOD=998244353;
vector<vl>dp(N,vl(N));
vl facts(N);
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    ll ans=0;
    ll t1=1,t2=pow(m,n,MOD);
    ll invm=pow(m,MOD-2,MOD);
    ll pch=1;
    FOR(i,1,k+1){
        if(n>=i)pch=(pch*(n-i+1))%MOD;
        else break;
        t1=(t1*((m+1)/2))%MOD;
        t2=(t2*invm)%MOD;
        ll tmp=(t1*t2)%MOD;
        tmp=(pch*tmp)%MOD;
        tmp=(dp[k][i]*tmp)%MOD;
        ans=(ans+tmp)%MOD;
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    facts[0]=1;
    FOR(i,1,N)facts[i]=(facts[i-1]*i)%MOD;
    int t;
    cin>>t;
    F0R(i,N){
        dp[i][i]=1;dp[i][1]=1;
    }
    FOR(i,1,N){
        FOR(j,2,i){
            dp[i][j]=((j*dp[i-1][j])%MOD+dp[i-1][j-1])%MOD;
        }
    }
    while(t--)solve();
    return 0;
}