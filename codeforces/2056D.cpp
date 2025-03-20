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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';

void solve(){
    ll n;cin>>n;
    ll ans=(n*(n+1))/2;
    vector<vl>pre(n+1,vl(11));
    vl arr(n);
    F0R(i,n){
        ll tmp;cin>>tmp;
        arr[i]=tmp;
        FOR(j,1,11){
            if(tmp<=j)pre[i+1][j]++;
            pre[i+1][j]+=pre[i][j];
        }
    }
    vector<map<int,int>>sets(10,{{0,1}});
    vector<map<pi,int>>sets2(10);
    FOR(i,1,10)sets2[i][{0,0}]=1;
    F0R(i,n){
        FORd(j,1,10){
            ans-=1ll*sets[j][2*pre[i+1][j]-i-1];
            ans+=1ll*sets2[j][{2*pre[i+1][j]-i-1,2*pre[i+1][j+1]-i-1}];
            sets[j][2*pre[i+1][j]-i-1]++;
            sets2[j][{2*pre[i+1][j]-i-1,2*pre[i+1][j+1]-i-1}]++;
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