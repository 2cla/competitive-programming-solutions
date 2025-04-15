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
vl factslist(ll p){
    vl tt;ll i=1;
    while(i*i<p){
        if(!(p%i)){
            tt.pb(i);tt.pb(p/i);
        }i++;
    }
    if(i*i==p)tt.pb(i);
    return tt;
}
void solve(){
    string ss;cin>>ss;
    ll n=sz(ss);vl arr(n);
    F0R(i,n)arr[i]=ss[i]-97;
    vl cnts(26);
    vector<vl>qq(26);
    ll tt=0,bb=-1;
    F0R(i,n){
        if(!tt&&arr[i]){
            tt=arr[i];bb=i;
        }
        qq[arr[i]].pb(i);cnts[arr[i]]++;
    }
    if(!tt){
        cout<<n-1<<'\n';return;
    }
    ll gg=cnts[tt];
    FOR(i,1,26)gg=gcd(gg,cnts[i]);
    vl fll=factslist(gg);
    ll ans=0;
    trav(a,fll){
        ll nn=-1;
        FOR(i,1,26){
            if(!cnts[i])continue;
            nn=max(nn,qq[i][cnts[i]/a-1]);
        }
        vl st(nn-bb+1);
        FOR(i,1,26){
            if(!cnts[i])continue;
            F0R(j,cnts[i]/a)st[qq[i][j]-bb]=i;
        }
        ll ta=n,ss=nn;
        FOR(i,1,a){
            ll ww=qq[tt][i*(cnts[tt]/a)];
            F0R(j,sz(st)){
                if(st[j]!=arr[j+ww]){
                    ta=-1;break;
                }
            }
            ta=min(ta,ww-ss-1);
            ss=ww+sz(st)-1;
            if(ta<0)break;
        }
        if(ta>=0){
            if(a>1){
                F0R(i,ta+1){
                    ans+=min(i+1ll,max(0ll,min((ll)i,n-ss-1)+min((ll)i,bb)+1-i));
                }
            }else ans+=(n-ss)*(bb+1);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}