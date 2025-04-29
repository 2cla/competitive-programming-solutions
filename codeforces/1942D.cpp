// I AM A PURE
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=(b)-1;i>=a;i--)
#define F0Rd(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for(auto& a:x)
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
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
#define prt(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz
#define pct __builtin_popcount
#define YES cout<<"yes\n"
#define NO cout<<"no\n"

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}

void solve(){
    ll n,k;cin>>n>>k;
    vector<vl>arr(n,vl(n));
    F0R(i,n){
        FOR(j,i,n){
            cin>>arr[i][j];
        }
    }
    vector<vector<vl>>dp(n+1,vector<vl>(2,vl(k,-1e14)));
    dp[0][0][0]=0;
    FOR(i,1,n+1){
        int ww=0;
        vi kk(i);
        pq<pl>hp;
        F0R(j,i){
            hp.push({dp[j][0][kk[j]]+arr[j][i-1],j});
        }
        while(ww<k){
            auto[x,y]=hp.top();hp.pop();
            dp[i][1][ww]=x;
            kk[y]++;
            if(kk[y]<k){
                hp.push({dp[y][0][kk[y]]+arr[y][i-1],y});
            }ww++;
        }
        vl hpp;
        F0R(j,k){
            hpp.pb(dp[i-1][0][j]);
            hpp.pb(dp[i-1][1][j]);
        }
        sort(all(hpp),greater<ll>());
        F0R(j,k){
            dp[i][0][j]=hpp[j];
        }
    }
    vl ans;
    F0R(j,k){
        ans.pb(dp[n][0][j]);
        ans.pb(dp[n][1][j]);
    }
    sort(all(ans),greater<ll>());
    F0R(j,k){
        cout<<ans[j]<<' ';
    }cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}