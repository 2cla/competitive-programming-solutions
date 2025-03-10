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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

int check(ll num, vl xarr){
    if((xarr.back()|num)!=num)return -1;
    int n=xarr.size();
    int k=0;
    FOR(i,1,n){
        if((xarr[i]|num)==num)k++;
    }
    return k;
}
void solve(){
    int n,x;cin>>n>>x;
    vl arr(n);
    F0R(i,n)cin>>arr[i];
    vl xarr={0};
    F0R(i,n)xarr.pb(xarr.back()^arr[i]);
    int ans=check(x,xarr);
    F0R(i,30){
        if(1<<i&x){
            ll x1=x^(1<<i);
            x1|=(1<<i)-1;
            ans=max(ans,check(x1,xarr));
        }
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