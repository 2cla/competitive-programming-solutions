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

const ll INF=1e9;
struct Tree {
	typedef tuple<ll,ll,ll,ll> T;
	static constexpr T unit = {-INF,-INF,-INF,-INF};
	T f(T a, T b) {
        ll wwa=get<0>(a),wla=get<1>(a),lwa=get<2>(a),lla=get<3>(a);
        ll wwb=get<0>(b),wlb=get<1>(b),lwb=get<2>(b),llb=get<3>(b);
        return {max({wwa,wwb,wwa+lwb,wla+wwb}),
        max({wla,wlb,wwa+llb,wla+wlb}),
        max({lwa,lwb,lla+wwb,lwa+lwb}),
        max({lla,llb,lla+wlb,lwa+llb})};
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
    ll n,q;cin>>n>>q;
    vl arr(n);
    Tree tr=Tree(n);
    F0R(i,n){
        cin>>arr[i];
        tr.update(i,{arr[i],-INF,-INF,-arr[i]});
    }
    cout<<get<0>(tr.query(0,n))<<'\n';
    while(q--){
        int l,r;cin>>l>>r;l--;r--;
        swap(arr[l],arr[r]);
        tr.update(l,{arr[l],-INF,-INF,-arr[l]});
        tr.update(r,{arr[r],-INF,-INF,-arr[r]});
        cout<<get<0>(tr.query(0,n))<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}