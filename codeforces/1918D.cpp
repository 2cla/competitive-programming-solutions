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
bool s2(ll mid,vl &arr,vl &pre){
    int n=sz(arr);
    vl dp=vl(n);
    pqg<pl> hp;hp.push({0,0});
    F0R(i,n){
        while(!hp.empty()){
            if(pre[i]-pre[hp.top().sec]>mid){
                hp.pop();continue;
            }
            dp[i]=hp.top().fir+arr[i];
            hp.push({dp[i],i+1});
            break;
        }
    }
    ll m=1e15;
    F0R(i,n){
        if(pre.back()-pre[i+1]<=mid)m=min(m,dp[i]);
    }
    return (m<=mid);
}
void solve(){
    int n;cin>>n;
    vl arr=vl(n);
    vl pre=vl(n+1);
    F0R(i,n)cin>>arr[i];
    FOR(i,1,n+1)pre[i]=pre[i-1]+arr[i-1];
    ll lo=1,hi=2e14;
    while(lo<hi){
        ll mid=(lo+hi)/2;
        if(s2(mid,arr,pre))hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}