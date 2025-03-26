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
int n,m,k;
bool rec(int mid,vi &hrr, vi &xrr){
    vi trr(n);
    F0R(i,n){
        trr[i]=hrr[i]/mid+(hrr[i]%mid!=0);
    }
    vpi ints;
    F0R(i,n){
        if(trr[i]>m)continue;
        ints.pb({xrr[i]-m+trr[i],0});
        ints.pb({xrr[i]+m-trr[i],1});
    }
    sort(all(ints));
    int ctr=0;
    trav(a,ints){
        if(a.s)ctr--;
        else ctr++;
        if(ctr==k)return true;
    }
    return false;
}
void solve(){
    cin>>n>>m>>k;
    vi hrr(n),xrr(n);
    F0R(i,n)cin>>hrr[i];
    F0R(i,n)cin>>xrr[i];
    int lo=1,hi=1e9+5;
    bool fl=false;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(rec(mid,hrr,xrr)){
            hi=mid;fl=true;
        }else lo=mid+1;
    }
    cout<<(fl?lo:-1)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}