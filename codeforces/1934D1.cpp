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
#define print(x) trav(a,x)cout<<a<<' ';cout<<'\n';

void solve(){
    ll n,m;cin>>n>>m;
    ll i=59;
    vl arr={n};
    while(1){
        if(1ll<<i&n&&1ll<<i&m){
            cout<<"1\n";
            cout<<arr[0]<<' '<<m<<'\n';
            return;
        }
        if(1ll<<i&n&&!(1ll<<i&m)){
            ll j=i-1;
            while(j>=0){
                if(1ll<<j&m&&!(1ll<<j&n)){
                    cout<<"-1\n";return;
                }
                if(1ll<<j&n){
                    n|=(1ll<<(j+1))-1;n^=(1ll<<i);arr.pb(n);
                    cout<<sz(arr)-(n==m)<<'\n';
                    if(n!=m)arr.pb(m);
                    print(arr)return;
                }
                j--;
            }
            cout<<sz(arr)<<'\n';
            arr.pb(m);
            print(arr)return;
        }
        i--;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}