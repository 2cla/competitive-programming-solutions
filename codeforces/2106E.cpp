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
    int n,q;cin>>n>>q;
    vi arr(n);F0R(i,n)cin>>arr[i];
    vi mm(n+1);
    F0R(i,n){
        mm[arr[i]]=i;
    }
    vi ans(q);
    F0R(i,q){
        int l,r,x;cin>>l>>r>>x;l--;r--;
        if(mm[x]<l||mm[x]>r){
            cout<<"-1 ";continue;
        }
        int lo=l,hi=r;
        if(arr[(lo+hi)/2]==x){
            cout<<"0 ";continue;
        }
        int ans1=0,ans2=0,a3=0,a4=0;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(mm[x]==mid){
                break;
            }
            if(mid>mm[x]){
                if(arr[mid]<x)ans1++;
                else a3++;
                hi=mid-1;
            }else{
                if(arr[mid]>x)ans2++;
                else a4++;
                lo=mid+1;
            }
        }
        if(ans1+a3>n-x||ans2+a4>x-1){
            cout<<"-1 ";continue;
        }
        cout<<2*max(ans1,ans2)<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}