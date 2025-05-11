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

vl arr;
struct Tree {
	typedef array<ll,6> T;
	static constexpr T unit = {-1,-1,0,0,0,0};
	T f(T a, T b) {
        T ww;
        if(a[0]==-1)return b;
        if(b[0]==-1)return a;
        ww[0]=a[0];ww[1]=b[1];
        int fl=(arr[a[1]]==1&&arr[b[0]]<9),fl2=(a[1]>a[0]),fl3=(b[1]>b[0]);
        ww[2]=mul(a[2],b[2]);
        ww[3]=mul(a[3],b[2]);
        ww[4]=mul(a[2],b[4]);
        ww[5]=mul(a[3],b[4]);
        if(fl){
            ll mm=9-arr[b[0]];
            ww[2]=add(ww[2],mul(mul(a[4],b[3]),mm));
            ww[3]=add(ww[3],mul(mul(fl2?a[5]:0,b[3]),mm));
            ww[4]=add(ww[4],mul(mul(a[4],fl3?b[5]:0),mm));
            ww[5]=add(ww[5],mul(mul(fl2?a[5]:0,fl3?b[5]:0),mm));
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
    ll n,m;cin>>n>>m;
    str ss;cin>>ss;
    ll nl=n;
    if(n&(n-1))nl=1ll<<(64-__builtin_clzll(n));
    arr=vl(nl);F0R(i,n)arr[i]=ss[i]-'0';
    Tree st(nl);
    F0R(i,n){
        st.update(i,{i,i,arr[i]+1,1,1,0});
        auto ww=st.query(0,n);
    }
    F0R(_,m){
        ll x,d;cin>>x>>d;x--;
        arr[x]=d;
        st.update(x,{x,x,d+1,1,1,0});
        auto ww=st.query(0,nl);
        cout<<ww[2]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}