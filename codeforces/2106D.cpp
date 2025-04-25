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

void solve(){
    int n,m;cin>>n>>m;
    vi arr(n),brr(m);F0R(i,n)cin>>arr[i];
    F0R(i,m)cin>>brr[i];
    int ctr=0;
    F0R(i,n){
        if(ctr==m){
            cout<<"0\n";return;
        }
        if(brr[ctr]<=arr[i]){
            ctr++;
        }
    }
    if(ctr==m){
        cout<<"0\n";return;
    }
    int lo=1,hi=1e9+1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        int ctr=0,ctr2=0,i=0;
        vi bb(n);
        while(i<n){
            if(ctr==m||ctr2==m)break;
            if(!bb[i]){
                if(brr[ctr]<=mid){
                    ctr2=max(ctr2,ctr+1);bb[i]=1;continue;
                }
            }
            if(brr[ctr2]<=arr[i]){
                ctr2++;
            }
            if(brr[ctr]<=arr[i]){
                ctr++;
            }
            i++;
        }
        if(ctr==m-1){
            if(brr[ctr]<=mid)ctr2=ctr+1;
        }
        if(ctr==m||ctr2==m)hi=mid;
        else lo=mid+1;
    }
    if(lo>1e9){
        cout<<"-1\n";return;
    }
    cout<<lo<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}