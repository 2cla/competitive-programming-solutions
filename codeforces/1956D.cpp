#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
using namespace __gnu_pbds;
 
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
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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

vpi ans;
void rec(int l,int r){
    if(r<=l)return;
    rec(l,r-1);
    ans.pb({l,r-1});
    if(r>l+1)ans.pb({l+1,r-1});
    rec(l+1,r);
}
void solve(){
    int n;cin>>n;
    ans=vpi();
    vi arr(n);F0R(i,n)cin>>arr[i];
    int b=0,bb=0;
    F0R(i,1<<n){
        int w=-1,tt=0;
        F0R(j,n){
            if(i&1<<j){
                tt+=(j-w-1)*(j-w-1);
                tt+=arr[j];
                w=j;
            }
        }
        tt+=(n-w-1)*(n-w-1);
        if(tt>b){
            b=tt;bb=i;
        }
    }
    int w=-1;
    F0R(i,n){
        if(bb&1<<i){
            rec(w+1,i-1);
            if(w+1<=i-1)ans.pb({w+1,i-1});
            w=i;
            continue;
        }
        if(!arr[i])continue;
        ans.pb({i,i});
    }
    rec(w+1,n-1);
    if(w+1<=n-1)ans.pb({w+1,n-1});
    cout<<b<<' '<<sz(ans)<<'\n';
    trav(a,ans){
        cout<<a.f+1<<' '<<a.s+1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}