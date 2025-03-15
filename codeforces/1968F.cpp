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

void solve(){
    int n,q;cin>>n>>q;
    vl arr=vl(n);
    F0R(i,n)cin>>arr[i];
    vl pre=vl(n+1);
    map<ll,vi> ids;
    ids[0].pb(0);
    FOR(i,1,n+1){
        pre[i]=pre[i-1]^arr[i-1];
        ids[pre[i]].pb(i);
    }
    F0R(i,q){
        int l,r;cin>>l>>r;
        ll diff=pre[r]^pre[l-1];
        if(!diff){
            cout<<"yes\n";continue;
        }
        auto lo=ub(all(ids[pre[l-1]^diff]),l-1);
        auto hi=ub(all(ids[pre[l-1]]),*lo);
        if(lo!=ids[pre[r]].end()&&hi!=ids[pre[l-1]].end()&&*hi<r){
            cout<<"yes\n";continue;
        }
        cout<<"no\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}