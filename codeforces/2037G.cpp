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

const ll mod=998244353;
vb nums(1000001,true);
vl primes;
vector<vl> primelist(1000001);
vector<pl> dp(1000001);
pair<vl,vl> pie(vl ps){
    pair<vl,vl> fa;
    vl dpp(1<<(sz(ps)),1);
    FOR(i,1,sz(dpp)){
        dpp[i]=dpp[i^1<<(31-__builtin_clz(i))]*ps[31-__builtin_clz(i)];
        if(__builtin_popcount(i)&1)fa.f.pb(dpp[i]);
        else fa.s.pb(dpp[i]);
    }
    return fa;
}
void solve(){
    ll n;cin>>n;
    ll tmp=1;
    vl arr(n);
    F0R(i,n)cin>>arr[i];
    pair<vl,vl> fa=pie(primelist[arr[0]]);
    trav(a,fa.f)dp[a].f=1;
    trav(a,fa.s)dp[a].f=1;
    FOR(i,1,n){
        tmp=0;
        fa=pie(primelist[arr[i]]);
        trav(a,fa.f){
            dp[a].s=(dp[a].f+2*dp[a].s)%mod;
            dp[a].f=(mod-dp[a].s)%mod;
            tmp=(tmp+dp[a].s)%mod;
        }
        trav(a,fa.s){
            dp[a].s=(dp[a].f+2*dp[a].s)%mod;
            dp[a].f=(mod-dp[a].s)%mod;
            tmp=(mod+tmp-dp[a].s)%mod;
        }
        trav(a,fa.f)dp[a].f=(dp[a].f+tmp)%mod;
        trav(a,fa.s)dp[a].f=(dp[a].f+tmp)%mod;
    }
    cout<<tmp%mod<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    FOR(i,2,1000001){
        int j=2;
        while(j*i<=1000000){
            nums[j*i]=false;j++;
        }
    }
    FOR(i,2,1000001){
        if(nums[i])primes.pb(i);
    }
    trav(a,primes){
        int j=1;
        while(j*a<=1000000){
            primelist[j*a].pb(a);j++;
        }
    }
    solve();
    return 0;
}