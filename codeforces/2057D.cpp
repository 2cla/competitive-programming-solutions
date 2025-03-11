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

typedef tuple<int, int, int> ti;
 
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
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

struct Tree {
	typedef ti T;
	static constexpr T unit = {-(1<<30),1<<30,0};
	T f(T a, T b) { return {max(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),max({get<0>(b)-get<1>(a),get<2>(a),get<2>(b)})}; }
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
    void print(){
        F0R(i,2*n){
            T a = s[i];
            cout<<i<<' '<<get<0>(a)<<' '<<get<1>(a)<<' '<<get<2>(a)<<'\n';
        }
    }
};
void solve(){
    int n,q;cin>>n>>q;
    vi l1=vi(n),l2=vi(n);
    F0R(i,n){
        int a;cin>>a;
        l1[i]=a-i;l2[n-1-i]=a+i;
    }
    Tree t1(n);Tree t2(n);
    F0R(i,n){
        t1.update(i,{l1[i],l1[i],0});
    }
    F0R(i,n)t2.update(i,{l2[i],l2[i],0});
    int ans=0;
    ans=max(get<2>(t1.query(0,n)),get<2>(t2.query(0,n)));
    cout<<ans<<'\n';
    F0R(_,q){
        int p,x;cin>>p>>x;
        t1.update(p-1,{x-p+1,x-p+1,0});
        t2.update(n-p,{x+p-1,x+p-1,0});
        ans=max(get<2>(t1.query(0,n)),get<2>(t2.query(0,n)));
        cout<<ans<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}