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
#define pct __popcount
//i fucking hate programming
vi rr(int a,vi&brr){
    int m=sz(brr);
    vi ww(m,1<<30);
    vi dp(1<<m);dp[0]=a;
    FOR(i,1,1<<m){
        int w=31-clz(i);
        dp[i]=dp[i^(1<<w)]&brr[w];
        ww[pct(i)-1]=min(ww[pct(i)-1],dp[i]);
    }
    F0R(i,m)ww[i]=a-ww[i];
    FORd(i,1,m)ww[i]-=ww[i-1];
    return ww;
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vi arr(n),brr(m);
    F0R(i,n)cin>>arr[i];
    F0R(i,m)cin>>brr[i];
    vl ans;
    F0R(i,n){
        trav(a,rr(arr[i],brr))ans.pb(a);
    }
    sort(all(ans),greater<ll>());
    ll tt=accumulate(all(arr),0ll);
    F0R(i,min((ll)sz(ans),k))tt-=ans[i];
    cout<<tt<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}