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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define um unordered_map
#define us unordered_set
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';

const ll INF=1e17;
void solve(){
    ll n,l;cin>>n>>l;
    vector<pl> arr=vector<pl>(n);
    F0R(i,n){
        ll a,b;cin>>a>>b;
        arr[i]={b,a};
    }
    sort(all(arr));
    vector<vl> dp(n+1,vl(n,INF));dp[1][0]=arr[0].s-arr[0].f;
    int ans=(arr[0].s<=l);
    FOR(i,1,n){
        if(arr[i].s<=l)ans=1;
        dp[1][i]=min(dp[1][i-1],arr[i].s-arr[i].f);
    }
    FOR(i,2,n+1){
        FOR(j,1,n){
            ll tmp=dp[i-1][j-1]+arr[j].s+arr[j].f;
            if(tmp<=l)ans=max(ans,i);
            dp[i][j]=min(dp[i][j-1],tmp-arr[j].f);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}