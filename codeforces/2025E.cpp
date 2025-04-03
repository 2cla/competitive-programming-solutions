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

const ll MOD=998244353;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
ll nCk(ll n,ll k,vl&facts,vl&invfacts){
    ll tmp=(facts[n]*invfacts[k])%MOD;
    return(tmp*invfacts[n-k])%MOD;
}
void solve(){
    ll n,m;cin>>n>>m;
    ll N=2e3+10;
    vl facts(N);
    vl invfacts(N);
    facts[0]=1;invfacts[0]=1;
    FOR(i,1,N)facts[i]=(facts[i-1]*i)%MOD;
    invfacts[N-1]=pow(facts[N-1],MOD-2,MOD);
    FORd(i,1,N-1)invfacts[i]=(invfacts[i+1]*(i+1))%MOD;
    vl cat(m/2+1,1);
    F0R(i,m/2){
        cat[i]=(MOD+nCk(m,m/2+i,facts,invfacts)-nCk(m,m/2+i+1,facts,invfacts))%MOD;
    }
    vl dp(m/2+1),dp2(m/2+1);dp[0]=1;
    F0R(i,n-1){
        F0Rd(j,m/2+1){
            F0R(k,m/2+1){
                if(j+k>m/2)continue;
                dp2[j+k]=(dp2[j+k]+dp[j]*cat[k])%MOD;
            }
        }
        swap(dp,dp2);fill(all(dp2),0);
    }
    ll ans=0;
    F0R(i,m/2+1){
        ans=(ans+cat[i]*dp[i])%MOD;
    }
    cout<<ans<<'\n';
}   
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);solve();
    return 0;
}