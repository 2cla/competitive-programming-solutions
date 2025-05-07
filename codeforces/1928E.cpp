// I AM A PURE
#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 0x0d010F2C
#endif
using namespace std;
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
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define prt(x) trav(a,x)cout<<a<<' ';cout<<'\n';
#define clz __builtin_clz
#define pct __builtin_popcount
#define YES cout<<"yes\n"
#define NO cout<<"no\n"
#define dbg debug

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi dp(2e5+1,1e9),g(2e5+1,-1),tt;
void solve(){
    ll n,x,y,s;cin>>n>>x>>y>>s;
    if((n*x)%y!=s%y){
        cout<<"no\n";return;
    }
    if(x+(n-1)*(x%y)>s){
        cout<<"no\n";return;
    }
    int tt=(s-n*(x%y))/y,cc=x/y,dd=x/y;
    vi ans(n,x%y);ans[0]=x;
    F0R(i,n){
        if(tt<cc)break;
        if(dp[tt-cc]<=n-i-1){
            F0R(j,i){
                ans[1+j]+=((x/y)+j+1)*y;
            }
            deque<int>tmp;
            int ww=tt-cc;
            while(ww){
                tmp.pb(dp[ww]-dp[g[ww]]);
                ww=g[ww];
            }
            ww=n-1;
            while(!tmp.empty()){
                ans[ww]+=(tmp.front()-1)*y;
                tmp.front()--;ww--;
                if(!tmp.front())tmp.pop_front();
            }
            cout<<"yes\n";
            prt(ans);return;
        }
        dd++;
        cc+=dd;
    }
    cout<<"no\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    dp[0]=0;
    F0R(i,640){
        tt.pb((i*(i+1))/2);
    }
    FOR(i,1,2e5+1){
        F0R(j,640){
            if(tt[j]>i)break;
            if(dp[i]>j+1+dp[i-tt[j]]){
                dp[i]=j+1+dp[i-tt[j]];g[i]=i-tt[j];
            }
        }
    }
    cin>>t;
    while(t--)solve();
    return 0;
}