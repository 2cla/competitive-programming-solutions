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
    int n;cin>>n;
    vi arr=vi(n);
    F0R(i,n)cin >> arr[i];
    sort(all(arr));
    vector<vi> il=vector<vi>(arr.back()+1);
    F0R(i,n)il[arr[i]].pb(i);
    vector<vi> dl=vector<vi>(arr.back()+1);
    FOR(i,1,sz(dl)){
        int j=1;
        while(j*i<=arr.back()){
            trav(k,il[j*i])dl[i].pb(k);
            j++;
        }
    }
    vl ansa=vl(arr.back()+1);
    FOR(i,1,sz(dl)){
        int j=0;
        trav(k,dl[i]){
            ansa[i]+=j*(n-k-1);
            j++;
        }
    }
    FORd(i,1,ansa.size()){
        int j=2;
        while(j*i<=arr.back()){
            ansa[i]-=ansa[j*i];
            j++;
        }
    }
    ll ans=0;
    F0R(i,sz(ansa))ans+=i*ansa[i];
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}