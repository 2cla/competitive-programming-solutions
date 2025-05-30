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
    int m,x;cin>>m>>x;
    vl carr=vl(m);
    vl harr=vl(m);
    int hsum=0;
    F0R(i,m){cin>>carr[i];cin>>harr[i];hsum+=harr[i];}
    ll dp[m+1][hsum+1];
    F0R(i,m+1)fill_n(dp[i],hsum+1,-1);
    dp[0][0]=0;
    F0R(i,m){
        F0R(j,hsum+1){
            if(dp[i][j]==-1)continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+x);
            if(dp[i][j]>=carr[i])dp[i+1][j+harr[i]]=max(dp[i+1][j+harr[i]],dp[i][j]+x-carr[i]);
        }
    }
    F0Rd(i,hsum+1){
        if(dp[m][i]!=-1){cout<<i<<'\n';return;}
    }
    cout<<0<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}