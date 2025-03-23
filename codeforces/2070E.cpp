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

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) {
        return a+b;
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
    ll n;cin>>n;
    string st;cin>>st;
    vector<Tree> ss(4,Tree(5*n+5));
    ss[0].update(n,1);
    vi pre(n+1);
    FOR(i,1,n+1){
        pre[i]=pre[i-1]+(st[i-1]=='1');
    }
    ll ans=0;
    FOR(i,1,n+1){
        ans+=1ll*ss[i&3].query(4*pre[i]-i+4+n,5*n+5);
        ans+=1ll*ss[(i+3)&3].query(4*pre[i]-i+5+n,5*n+5);
        ans+=1ll*ss[(i+2)&3].query(4*pre[i]-i+2+n,5*n+5);
        ans+=1ll*ss[(i+1)&3].query(4*pre[i]-i-1+n,5*n+5);
        int tmp=ss[i&3].query(4*pre[i]-i+n,4*pre[i]-i+1+n);
        ss[i&3].update(4*pre[i]-i+n,tmp+1);
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}