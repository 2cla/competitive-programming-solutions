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
#define uid(a,b) uniform_int_distribution<ll>(a,b)(rng)
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll aa=uid(9e8,1e9),b1=uid(9e8,1e9),b2=uid(9e8,1e9);
void solve(){
    ll n,m;cin>>n>>m;
    vector<vl>g(n,vl(m));
    F0R(i,n){
        str ss;cin>>ss;
        F0R(j,m){
            g[i][j]=ss[j]=='1';
        }
    }
    vl arr1(1,1),arr2(1,1);
    F0R(i,n){
        arr1.pb((arr1.back()*aa)%b1);
        arr2.pb((arr2.back()*aa)%b2);
    }
    map<pl,vpl>ww;
    map<pl,set<ll>>ww2;
    F0R(j,m){
        ll c1=0,c2=0;
        F0R(i,n){
            if(g[i][j]){
                c1=(c1+arr1[i])%b1;
                c2=(c2+arr2[i])%b2;
            }
        }
        F0R(i,n){
            if(g[i][j]){
                ll d1=(c1+b1-arr1[i])%b1,d2=(c2+b2-arr2[i])%b2;
                ww[{d1,d2}].pb({i,j});ww2[{d1,d2}].ins(j);
            }else{
                ll d1=(c1+arr1[i])%b1,d2=(c2+arr2[i])%b2;
                ww[{d1,d2}].pb({i,j});ww2[{d1,d2}].ins(j);
            }
        }
    }
    ll ans=0;
    pl ff={-1,-1};
    trav(a,ww2){
        if(sz(a.s)>ans){
            ans=sz(a.s);ff=ww[a.f][0];
        }
    }
    cout<<ans<<'\n';
    vl ans2(n);
    ll c1=0,c2=0;
    F0R(i,n){
        if(g[i][ff.s])ans2[i]=1;
    }
    ans2[ff.f]^=1;
    trav(a,ans2){
        cout<<(a?'1':'0');
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