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

const ll MOD=1e9+7;
ll pow(ll x,ll y,ll m){
    if(!y)return 1;
    ll p=pow(x,y/2,m)%m;
    p=(p*p)%m;
    if(!(y%2))return p;
    return (x*p)%m;
}
void solve(){
    ll dd=pow(1e4,MOD-2,MOD);
    ll n;cin>>n;
    vl arr(n);F0R(i,n)cin>>arr[i];
    vl prr(n);F0R(i,n)cin>>prr[i];
    ll ans=0;
    F0R(i,10){
        F0R(j,i){
            ll ee=1,eo=0,oe=0,oo=0;
            F0R(k,n){
                if(1ll<<i&arr[k]&&1ll<<j&arr[k]){
                    ll tmp1=(ee*prr[k]+oo*(10000-prr[k]))%MOD;
                    ll tmp2=(oe*prr[k]+eo*(10000-prr[k]))%MOD;
                    ll tmp3=(eo*prr[k]+oe*(10000-prr[k]))%MOD;
                    ll tmp4=(oo*prr[k]+ee*(10000-prr[k]))%MOD;
                    oo=tmp1;eo=tmp2;oe=tmp3;ee=tmp4;
                }else if(1ll<<i&arr[k]){
                    ll tmp1=(eo*prr[k]+oo*(10000-prr[k]))%MOD;
                    ll tmp2=(oo*prr[k]+eo*(10000-prr[k]))%MOD;
                    ll tmp3=(ee*prr[k]+oe*(10000-prr[k]))%MOD;
                    ll tmp4=(oe*prr[k]+ee*(10000-prr[k]))%MOD;
                    oo=tmp1;eo=tmp2;oe=tmp3;ee=tmp4;
                }else if(1ll<<j&arr[k]){
                    ll tmp1=(oe*prr[k]+oo*(10000-prr[k]))%MOD;
                    ll tmp2=(ee*prr[k]+eo*(10000-prr[k]))%MOD;
                    ll tmp3=(oo*prr[k]+oe*(10000-prr[k]))%MOD;
                    ll tmp4=(eo*prr[k]+ee*(10000-prr[k]))%MOD;
                    oo=tmp1;eo=tmp2;oe=tmp3;ee=tmp4;
                }else{
                    ee=(ee*10000)%MOD;eo=(eo*10000)%MOD;
                    oe=(oe*10000)%MOD;oo=(oo*10000)%MOD;
                }
            }
            ll tt=(oo*(1ll<<(i+j+1)))%MOD;
            ans=(ans+tt)%MOD;
        }
    }
    F0R(i,10){
        ll ie=1,io=0;
        F0R(k,n){
            if(1ll<<i&arr[k]){
                ll tmp1=(ie*prr[k]+io*(10000-prr[k]))%MOD;
                ll tmp2=(io*prr[k]+ie*(10000-prr[k]))%MOD;
                io=tmp1;ie=tmp2;
            }else{
                io=(io*10000)%MOD;ie=(ie*10000)%MOD;
            }
        }
        ll tt=(io*(1ll<<(2*i)))%MOD;
        ans=(ans+tt)%MOD;
    }
    cout<<(ans*pow(dd,n,MOD))%MOD<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}