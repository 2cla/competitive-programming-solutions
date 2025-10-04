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
typedef vector<bool> vb;
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
#define dbg debug

const ll mod=998244353;
// const ll mod=1e9+7;
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
ll pow(ll a,ll b,ll p=mod){a%=p;ll r=1%p;while(b){if(b&1)r=r*a%p;a=a*a%p;b>>=1;}return r;}
ll inv(ll x,ll p=mod){return pow(x,p-2,p);}
ll add(ll a,ll b){return (a+b)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    ll n,m,q;cin>>n>>m>>q;
    vl arr(n);F0R(i,n)cin>>arr[i];
    map<ll,ll>fac2idx;
    vl facs;
    ll i=2;
    while(i*i<m){
        if(!(m%i)){
            facs.pb(i);facs.pb(m/i);
            fac2idx[i]=sz(fac2idx);fac2idx[m/i]=sz(fac2idx);
        }i++;
    }
    if(i*i==m){
        facs.pb(i);fac2idx[i]=sz(fac2idx);
    }
    ll nf=sz(facs);
    vector<vi>dp1(nf,vi(n));
    vector<vb>dp2(nf,vb(n-1));
    vl viols(nf);
    F0R(i,nf){
        F0R(j,n){
            dp1[i][j]=arr[j]%facs[i];
        }
        F0R(j,n-1){
            if(dp1[i][j]>dp1[i][j+1]){
                dp2[i][j]=1;
                viols[i]++;
            }
        }
    }
    F0R(_,q){
        ll w;cin>>w;
        if(w==1){
            ll i,x;cin>>i>>x;i--;
            F0R(j,nf){
                dp1[j][i]=x%facs[j];
                if(i<n-1){
                    if(dp1[j][i]>dp1[j][i+1]){
                        if(!dp2[j][i]){
                            viols[j]++;
                            dp2[j][i]=1;
                        }
                    }else{
                        if(dp2[j][i]){
                            viols[j]--;
                            dp2[j][i]=0;
                        }
                    }
                }
                if(i){
                    if(dp1[j][i]<dp1[j][i-1]){
                        if(!dp2[j][i-1]){
                            viols[j]++;
                            dp2[j][i-1]=1;
                        }
                    }else{
                        if(dp2[j][i-1]){
                            viols[j]--;
                            dp2[j][i-1]=0;
                        }
                    }
                }
            }
        }else{
            ll k;cin>>k;
            ll gg=gcd(k,m);
            if(gg==1){
                cout<<"yes\n";continue;
            }
            cout<<(viols[fac2idx[gg]]<m/gg?"yes\n":"no\n");
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    // t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}