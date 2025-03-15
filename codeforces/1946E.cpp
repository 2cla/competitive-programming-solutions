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

const ll mod=1000000007;
const int gg=200001;
ll facts[gg];
ll invfacts[gg];

ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}

ll help(vi &a){
    int m=sz(a);
    ll ans=1;
    F0R(i,m-1){
        if(a[i]-a[i+1]>1){
            ans=(ans*facts[a[i]-2])%mod;
            ans=(ans*invfacts[a[i]-2-(a[i]-a[i+1]-1)])%mod;
        }
    }
    return ans;
}    
void solve(){
    int n,m1,m2;cin>>n>>m1>>m2;
    vi a1=vi(m1),a2=vi(m2);
    F0R(i,m1)cin>>a1[m1-i-1];
    F0R(i,m2)cin>>a2[i];
    if(a1[0]!=a2[0]||a1.back()!=1||a2.back()!=n){cout<<0<<'\n';return;}
    F0R(i,m2)a2[i]=n+1-a2[i];
    ll ans=(invfacts[a1[0]-1]*facts[n-1])%mod;
    ans=(ans*invfacts[a2[0]-1])%mod;
    ans=(ans*help(a1))%mod;
    ans=(ans*help(a2))%mod;
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    facts[0]=1;invfacts[0]=1;
    FOR(i,1,gg)facts[i]=(facts[i-1]*i)%mod;
    invfacts[gg-1]=pow(facts[gg-1],mod-2,mod);
    FORd(i,1,gg-1)invfacts[i]=(invfacts[i+1]*(i+1))%mod;
    cin>>t;
    while(t--)solve();
    return 0;
}