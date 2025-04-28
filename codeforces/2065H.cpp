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
struct Tree {
	typedef array<pl,4> T;
	static constexpr T unit = {{{-1ll,-1ll},{-1ll,-1ll},{-1ll,-1ll},{-1ll,-1ll}}};
	T f(T a, T b) {
        if(a[0].f==-1)return b;
        if(b[0].f==-1)return a;
        ll tt,gg,g1,g2;
        array<pl,4>ww;
        F0R(i,16){
            gg=((i>>3&1)<<1)|(i&1);
            g1=i>>2&3;g2=i&3;
            tt=mul(a[g1].f,b[g2].s)+mul(a[g1].s,b[g2].f);
            if((i>>2&1)+(i>>1&1)!=1)tt+=mod-mul(a[g1].s,b[g2].s);
            tt%=mod;
            ww[gg].f=add(ww[gg].f,tt);
            ww[gg].s=add(ww[gg].s,mul(a[g1].s,b[g2].s));
        }
        F0R(i,4){
            ww[i].f=add(ww[i].f,a[i].f+b[i].f);
            ww[i].s=add(ww[i].s,a[i].s+b[i].s);
        }
        return ww;
    }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
void solve(){
    str ss;cin>>ss;
    ll n=sz(ss);
    Tree st(n);
    F0R(i,n){
        if(ss[i]=='1')st.update(i,{{{0ll,0ll},{0ll,0ll},{0ll,0ll},{1ll,1ll}}});
        else st.update(i,{{{1ll,1ll},{0ll,0ll},{0ll,0ll},{0ll,0ll}}});
    }
    ll q;cin>>q;
    F0R(_,q){
        ll w;cin>>w;w--;
        if(ss[w]=='0'){
            st.update(w,{{{0ll,0ll},{0ll,0ll},{0ll,0ll},{1ll,1ll}}});
            ss[w]='1';
        }else{
            st.update(w,{{{1ll,1ll},{0ll,0ll},{0ll,0ll},{0ll,0ll}}});
            ss[w]='0';
        }
        auto ww=st.query(0,n);
        // debug(st.query(0,2));
        ll ans=0;
        F0R(i,4)ans=add(ans,ww[i].f);
        cout<<ans<<' ';
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