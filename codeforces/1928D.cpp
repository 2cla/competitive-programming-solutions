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

typedef tuple<int, int, int> ti;
 
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

void solve(){
    ll n,b,x;cin>>n>>b>>x;
    unordered_map<ll,ll> carr;
    F0R(i,n){
        ll c;cin>>c;
        carr[c]++;
    }
    ll mac=0,t=0;
    trav(i,carr){
        ll k=get<0>(i),v=get<1>(i);
        mac=max(mac,k);
        t+=v*k*(k-1);
    }
    ll ans=0;
    FOR(i,1,mac+1){
        ll te=0;
        trav(j,carr){
            ll k=get<0>(j),v=get<1>(j);
            te+=v*((k%i)*(k/i)*(k/i+1)+(i-k%i)*(k/i)*(k/i-1));
        }
        ans=max(ans,b*(t-te)/2-(i-1)*x);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}