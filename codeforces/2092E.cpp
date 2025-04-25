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

const ll MOD=1e9+7;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    map<pl,ll>ww;
    F0R(i,k){
        ll x,y,c;cin>>x>>y>>c;
        ww[{x,y}]=c;
    }
    ll ctr=0;
    FOR(i,2,n){
        if(!ww.count({i,1})||!ww.count({i,m})){
            cout<<pow(2,n*m-k-1,MOD)<<'\n';
            return;
        }
        if(ww.count({i,1}))ctr+=ww[{i,1}];
        if(ww.count({i,m}))ctr+=ww[{i,m}];
    }
    FOR(i,2,m){
        if(!ww.count({1,i})||!ww.count({n,i})){
            cout<<pow(2,n*m-k-1,MOD)<<'\n';
            return;
        }
        if(ww.count({1,i}))ctr+=ww[{1,i}];
        if(ww.count({n,i}))ctr+=ww[{n,i}];
    }
    if(ctr&1){
        cout<<"0\n";return;
    }
    cout<<pow(2,n*m-k,MOD)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}