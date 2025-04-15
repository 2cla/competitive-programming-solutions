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

const ll MOD=1e9+7;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
pl add(pl p,pl q){
    if(!p.f)return q;
    if(!q.f)return p;
    return{((p.f*q.s)%MOD+(q.f*p.s)%MOD)%MOD,(p.s*q.s)%MOD};
}
void solve(){
    ll n,k;cin>>n>>k;
    ll aa=0,bb=0;
    F0R(i,k){
        ll t;cin>>t;
        aa=(aa+t)%MOD;
    }
    F0R(i,n-k){
        ll t;cin>>t;
        bb=(bb+t)%MOD;
    }
    pl a1,a2;
    a1=add({(aa*((n-k+2)/2))%MOD,n-k+1},{(bb*((n-k+1)/2))%MOD,n-k});
    a2=add({(aa*((n-k+1)/2))%MOD,n-k+1},{(bb*((n-k)/2))%MOD,n-k});
    cout<<(a1.f*pow(a1.s,MOD-2,MOD))%MOD<<' '<<(a2.f*pow(a2.s,MOD-2,MOD))%MOD<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}