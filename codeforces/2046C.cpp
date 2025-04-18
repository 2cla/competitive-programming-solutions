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
    int n;cin>>n;
    vpi arr(n);
    F0R(i,n)cin>>arr[i].f>>arr[i].s;
    sort(all(arr));
    int ans=0;pi ans2={-1e9,-1e9};
    int lo=0,hi=n/4;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        int xx=-1e9,yy=-1e9;
        ordered_set ww1,ww2;
        bool fl=false;
        F0R(i,n)ww2.ins({arr[i].s,i});
        F0R(i,n){
            ww1.ins({arr[i].s,i});ww2.erase({arr[i].s,i});
            if(i<n-1&&arr[i].f==arr[i+1].f)continue;
            if(sz(ww1)<mid||sz(ww2)<mid)continue;
            auto it1=ww1.find_by_order(mid-1);
            auto it2=ww2.find_by_order(mid-1);
            auto it3=ww1.find_by_order(sz(ww1)-mid);
            auto it4=ww2.find_by_order(sz(ww2)-mid);
            int f1=max((*it1).f,(*it2).f)+1,f2=min((*it3).f,(*it4).f);
            if(f1<=f2){
                xx=arr[i].f+1;yy=f1;fl=true;break;
            }
        }
        if(fl){
            lo=mid;
            if(lo>ans){
                ans=lo;ans2={xx,yy};
            }
        }
        else hi=mid-1;
    }
    cout<<ans<<'\n';
    cout<<ans2.f<<' '<<ans2.s<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}