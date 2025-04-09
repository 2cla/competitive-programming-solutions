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

int rec(int mid,vi&arr,int k,int n){
    vi crr(n),dp(1+n%k+k*(n%k==0));
    F0R(i,n)crr[i]=(arr[i]>=mid);
    F0R(i,n){
        if((i+1)%k>sz(dp)-1)continue;
        if(!((i+1)%k)){
            if(i+1>=k&&sz(dp)==k+1)dp[k]=max(dp[k],crr[i]+dp[k-1]);
        }
        else dp[(i+1)%k]=max(dp[(i+1)%k],crr[i]+dp[i%k]);
    }
    return *max_element(all(dp));
} 
void solve(){
    int n,k;cin>>n>>k;
    vi arr(n);F0R(i,n)cin>>arr[i];
    vi brr=arr;sort(all(brr));
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(rec(brr[mid],arr,k,n)>=(n%k+k*(n%k==0))/2+1)lo=mid;
        else hi=mid-1;
    }
    cout<<brr[lo]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}