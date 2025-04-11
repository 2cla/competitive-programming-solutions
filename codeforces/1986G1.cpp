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

const int N=5e5+5;
vector<vi>facts(N);
void solve(){
    int n;cin>>n;
    vi arr(n);F0R(i,n)cin>>arr[i];
    vector<map<int,int>>mm(n+1);
    ll ans=0;
    F0R(i,n){
        int tmp=gcd(arr[i],i+1);
        int a=arr[i]/tmp,b=(i+1)/tmp;
        trav(c,facts[a]){
            ans+=1ll*mm[b][c];
        }
        trav(c,facts[a]){
            mm[c][b]++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    FOR(i,1,N){
        int j=1;
        for (int j=i;j<N;j+=i){
            facts[j].pb(i);
        }
    }
    cin>>t;
    while(t--)solve();
    return 0;
}