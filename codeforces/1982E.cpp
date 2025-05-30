#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
using namespace __gnu_pbds;
 
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
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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

vector<vl>dp;
const ll MOD=1e9+7;
ll ans,n;
ll add(ll a,ll b){
    return (a+b)%MOD;
}
ll mul(ll a,ll b){
    return (a*b)%MOD;
}
ll rec(ll i,ll k){
    if(i<=k){
        ll tt=(((1ll<<(i+1))-1)&n)%MOD;
        ans=add(ans,mul(tt,tt+1));
        return -1;
    }
    ans=add(ans,dp[i][k]);
    return k-1;
}
void solve(){
    ans=0;
    ll k;cin>>n>>k;
    F0Rd(i,60){
        if(k<0)break;
        if(n&1ll<<i){
            k=rec(i,k);
        }
    }
    cout<<mul(ans,5e8+4)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    dp=vector<vl>(62,vl(62));
    F0R(i,62)dp[i][0]=2;dp[1][1]=6;dp[2][1]=12;
    FOR(i,3,62)dp[i][1]=dp[i-1][1]+2;
    FOR(j,1,62){
        FOR(i,2,62){
            if(i>=j){
                dp[j][i]=mul((1ll<<j)%MOD,((1ll<<j)+1)%MOD);
            }else if(i+1==j){
                dp[j][i]=mul((1ll<<j)%MOD,((1ll<<j)-1)%MOD);
            }else{
                dp[j][i]=add(dp[j-1][i-1],dp[j-1][i]);
            }
        }
    }
    while(t--)solve();
    return 0;
}