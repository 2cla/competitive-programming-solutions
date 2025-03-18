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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define um unordered_map
#define us unordered_set

void solve(){
    ll n,c;cin>>n>>c;
    vl sarr=vl(n);
    ll odd=0,even=0;
    F0R(i,n){
        cin>>sarr[i];
        if(sarr[i]&1){odd++;
        }else{even++;}
    }
    ll ans=(c+2)*(c+1)+odd*(odd-1)+even*(even-1);ans/=2;
    F0R(i,n){
        ans-=sarr[i]/2+1;
        ans-=c-sarr[i]+1;
    }
    cout<<ans+n<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}