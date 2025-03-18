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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define safe_map unordered_map<ll, ll, custom_hash>

const ll mod=998244353;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
ll mul(ll a,ll b) {
    return (a*b)%mod;
}
void solve(){
    int k,n;cin>>k>>n;
    vl bigfact=vl(20),fact=vl(20),invfact=vl(20);
    bigfact[0]=1;fact[0]=1;invfact[0]=1;
    FOR(i,1,20)bigfact[i]=(bigfact[i-1]*(n-i+2))%mod;
    FOR(i,1,20)fact[i]=(fact[i-1]*i)%mod;
    invfact.back()=pow(fact.back(),mod-2,mod);
    FORd(i,1,19)invfact[i]=(invfact[i+1]*(i+1))%mod;
    int a=32-__builtin_clz(k);
    vector<vector<safe_map>> dp(k+1,vector<safe_map>(a+1));
    dp[1][0][1]=1;
    F0R(i,a){
        FOR(j,1,k+1){
            if(dp[j][i].empty())continue;
            int ctr=dp[j][i][1];
            int p=2;
            while(j*p<=k){
                ll q=p,c=1;
                while(ctr&&j*q<=k){
                    dp[j*q][i+c][p]+=mul(mul(mul(ctr,fact[i+c]),invfact[c]),invfact[i]);
                    dp[j*q][i+c][p]%=mod;
                    c++;q*=p;
                }
                if(dp[j][i].count(p)){
                    ctr+=dp[j][i][p];ctr%=mod;
                }
                p++;
            }
        }
    }
    cout<<n<<' ';
    FOR(j,2,k+1){
        ll ans=0;
        F0R(i,a+1){
            ll tmp=0;
            trav(a,dp[j][i]){
                tmp+=a.sec;tmp%=mod;
            }
            tmp=mul(mul(tmp,bigfact[i+1]),invfact[i+1]);
            ans+=tmp;ans%=mod;
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}